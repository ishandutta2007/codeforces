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

int N,K;
vector<int> E[200000];
map<pii, int> M;
bool U[200000];
int C[200000];

int unis(int u, int ig) {
    auto iter = M.find({u,ig});
    if (iter != M.end()) return iter->y;
    int &m = M[{u,ig}];

    if (U[u]) m += 1;
    for (int v : E[u]) {
        if (v != ig) {
            m += unis(v,u);
        }
    }

    return m;
}

ll cnt(int u, int ig, int e) {
    ll a = 0;
    if (U[u]) a += e;
    for (int v : E[u]) {
        if (v != ig) {
            a += cnt(v,u,e+1);
        }
    }
    return a;
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        U[i] = false; C[i] = -1;
    }
    for (int i = 0; i < 2*K; i++) {
        int k; scanf("%d", &k);
        U[k-1] = true;
    }
    for (int i = 0; i < N-1; i++) {
        int u,v; scanf("%d %d", &u, &v);
        --u; --v; E[u].push_back(v); E[v].push_back(u);
    }
 
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int u : E[i]) {
            x = max(x,unis(u,i));
        }
        if (x <= K) {
            ll ans = 0;
            for(int u:E[i]) ans += cnt(u,i,1);
            cout << ans << endl;
            return 0;
        }
    }
}