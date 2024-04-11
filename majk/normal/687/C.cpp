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

#define MAXN 500
int A[MAXN];
vector<pii> B[MAXN+1];
bool Q[MAXN+1];
int cnt;
int N,K;

int memo[MAXN+1][MAXN+1];

void backtrack(int i, int s, int m) {
    if (memo[i][s] >= m) return;

    if (!Q[s]) {
        Q[s] = true;
        if (++cnt == K+1) return;
    }

    for (pii&b: B[i]) {
        if (b.x >= memo[i][s] && b.x < m) {
            for (int j = 0; j <= b.y; j++) {
                backtrack(i-b.x*b.y,s+b.x*j,b.x);
            }
        }
    }
    memo[i][s] = m;
}

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    vector<int> C(N); rv(C); sort(wh(C));
    for (int i = 0; i < N; i++) {
        A[i] = 0;
    }

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            memo[i][j] = 0;
        }
    }

    for (int i = 0; i <= K; i++) {
        Q[i] = false;
    }
    Q[0] = Q[K] = true; cnt = 2;

    for (int i = 0; i < N; i++) if (C[i] < K) ++A[C[i]];

    for (int i = 1; i < K; i++) {
        if (!A[i]) continue;

        for (int j = K-1; j >= 0; j--) {
            if (j != 0 && B[j].size() == 0) continue;
            for (int k = 1; k <= A[i]; k++) {
                if (j+i*k > K) break;
                B[j+i*k].push_back({i,k});
            }
        }
    }

    /*
    for (int i = 0; i <= K; i++) {
        cout << i; 
        for(pii&b:B[i]) {
            cout << ' ' << b.x << '*' << b.y;
        }
        cout << endl;
    }
    */

    backtrack(K,0,K);

    cout << cnt << endl;
    for (int i = 0; i <= K; i++) {
        if (Q[i]) cout << i << ' ';
    }
    cout << endl;
    
}