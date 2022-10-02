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

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; cin >> N; N--;
    vector<pll> T(N);
    pll L; cin >> L.x >> L.y;
    for(auto&t: T) cin >> t.x >> t.y;
    sort(wh(T), greater<pll>());
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    int i=0;
    while(i<N && T[i].x>L.x) {
        Q.push(T[i].y-T[i].x+1);
        ++i; 
    }
    int best=Q.size()+1;

    while(!Q.empty() && best > 1) {
        ll q=Q.top(); Q.pop();
        if (L.x < q) break;
        L.x -= q;
    
        while(i<N && T[i].x>L.x) {
            Q.push(T[i].y-T[i].x+1);
            ++i; 
        }
        best=min(best,(int)Q.size()+1);
    }
    cout << best << endl;
}