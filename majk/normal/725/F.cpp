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
#define pll pair<ll,ll>

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

typedef pair<ll,int> G;

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; cin >> N;

    ll A=0,B=0;
    priority_queue<G> Q;
    vector<pair<pll,pll>> D;
    for (int i = 0; i < N; i++) {
        ll a1,b1,a2,b2; cin >> a1>>b1>>a2>>b2;
        if (a1+b1+a2+b2==0) continue;
        if (a1+b1>a2+b2) {
            Q.push({a1+b1,D.size()});
            D.push_back({{a1,b1},{a2,b2}});
        } else if (b1>a2) {
            A += a2;
            B += b1;
        } else if (a1>b2) {
            A += a1;
            B += b2;
        }
    }

    bool t = true;
    while (!Q.empty()) {
        auto q = Q.top(); Q.pop();
        if (t) A += D[q.y].x.x;
        else B += D[q.y].x.y;
        t = !t;
        D[q.y] = {D[q.y].y, {0,0}};
        int s = D[q.y].x.x + D[q.y].x.y;
        if (s > 0) {
            Q.push({s,q.y});
        }
    }

    cout << A-B << endl;
}