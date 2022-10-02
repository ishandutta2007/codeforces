#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#ifndef MDEBUG
#define NDEBUG
#endif

#define x first
#define y second
#define ll long long
#define d double
#define ld long double
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pss pair<string,string>
#define psi pair<string,int>
#define pis pair<int,string>
#define psl pair<string,ll>
#define pls pair<ll,string>
#define wh(x) (x).begin(),(x).end()
#define ri(x) int x;cin>>x;
#define rii(x,y) int x,y;cin>>x>>y;
#define rl(x) ll x;cin>>x;
#define rv(v) for(auto&_cinv:v) cin>>_cinv;
#define wv(v) for(auto&_coutv:v) cout << _coutv << ' '; cout << endl;
#define ev(v) for(auto&_cerrv:v) cerr << _cerrv << ' '; cerr << endl;
#define MOD 1000000007

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
// auto fraclt = [](auto&a,auto&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
template<typename T> void fracn(pair<T,T>&a) {auto g=gcd(a.x,a.y);a.x/=g;a.y/=g;}
template<typename T> struct Index { int operator[](const T&t){auto i=m.find(t);return i!=m.end()?i->y:m[t]=m.size();}int s(){return m.size();} unordered_map<T,int> m; };


int CHI[300000];
vector<int> Chains[150000];
vector<int> C[300000];
int S[300000];
int chaincount = 0;

int size(int v) {
    int ans = 1;
    for (int &c:C[v]) {
        ans += size(c);
    }
    return S[v] = ans;
}

void calc(int v) {
    if (C[v].size() == 0) return;

    int chi = chaincount;
    vector<int> & ch = Chains[chaincount++];

    int nv;
    while (true) {
        CHI[v] = chi;
        ch.push_back(v);

        int ms = 0;
        for (int &c:C[v]) {
            ms = max(ms, S[c]);
        }
        if (ms==0) break;
        for (int &c:C[v]) {
            if (ms == S[c]) {
                nv = c; ms = 10000000;
            } else {
                calc(c);
            }
        }
        v=nv;
    }
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N,Q; scanf("%d %d",&N,&Q);
    for (int i=0;i<N;++i) S[i]=0;
    for (int i=0;i<N-1;++i) { int p;scanf("%d",&p); C[p-1].push_back(i+1); }
    size(0);
    assert(S[0] == N);
    calc(0);
    
    
    auto l = [](int el, int val) { return S[el] * 2 > val; };
    for (int i=0;i<Q;++i) {
        int q; scanf("%d",&q); --q;
        vector<int> &ch = Chains[CHI[q]];
        if (S[q] == 1) {
            printf("%d\n", q+1);
        } else {
            auto iter = lower_bound(wh(ch), S[q], l);
            printf("%d\n", *--iter + 1);
        }
    }
}