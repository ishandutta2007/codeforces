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
#include <queue>
using namespace std;

#define x first
#define y second
#define ll long long
#define ld long double
#define pii pair<int,int>
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
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

int N;
vector<int> A;
vector<vector<pii>> E;
ll L[200000];
int P[200000];
int C[200000];
int G[200000];

int dfs1(int u, int d, ll c) {
    int r = 0;
    L[d] = c;
    P[d] = u;
    for(pii v : E[u]) {
        r += dfs1(v.x, d+1, c+v.y);
    }
    G[u] = r;
    int i = bsl(0, d-1, [&](int j) { return L[d] - L[j] <= A[u]; });
    if (i != -1) { ++C[P[i]]; ++r; }
    return r - C[u];
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N); rv(A);
    E.resize(N);
    for (int i = 0; i < N-1; i++) {
        rii(p,w);
        E[p-1].push_back({i+1,w});
    }

    dfs1(0, 0, 0);
    for (int i = 0; i < N; i++) {
        cout << G[i] << ' ';
    }
    cout << endl;
}