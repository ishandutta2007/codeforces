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

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    ri(N); ri(K); ri(S); ri(T);

    vector<int> C(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> V[i];
    }
    
    vector<int> G(K);
    rv(G);
    G.push_back(0); G.push_back(S);
    sort(wh(G));

    vector<int> F(K+1);
    for (int i = 0; i <= K; i++) {
        F[i] = G[i+1] - G[i];
    }
    sort(wh(F));
    vector<int> P(K+1);
    int s = 0;
    for (int i = 0; i <= K; i++) {
       s += F[i];
       P[i] = s;
    }

    int best = MOD; 
    for (int i = 0; i < N; i++) {
        if (F[K] > V[i]) { continue; }
        if (C[i] >= best) continue;
        int dbl = bsh(0, K, [&](int j) { return F[j]*2 <= V[i]; });
        ll t = 3LL * P[K];
        if (dbl != -1) t -= 2LL * P[dbl];
        t -= (K - dbl) * V[i];
        if (t <= T) best = C[i];
    }

    if (best == MOD) { cout << -1 << endl; }
    else {cout << best << endl; }


}