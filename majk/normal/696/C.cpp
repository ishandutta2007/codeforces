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

struct M { 
    ll a11,a12,a21,a22;
    M operator+(const M& o) {
        return {(a11+o.a11)%MOD,(a12+o.a12)%MOD,(a21+o.a21)%MOD,(a22+o.a22)%MOD};
    }
    M operator*(const M& o) {
        return {(a11*o.a11+a12*o.a21)%MOD,(a11*o.a12+a12*o.a22)%MOD,(a21*o.a11+a22*o.a21)%MOD,(a21*o.a12+a22*o.a22)%MOD};
    }
};

ll div2(ll a) {
    if (a & 1) return (a+MOD)/2;
    else return a/2;
}


int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int K; scanf("%d", &K);
    M mat = {0,2,1,1};
    ll q = 2;
    while(K--) {
        ll A; scanf("%I64d", &A);
        if (A == 1) continue;
        
        M cmat = mat;
        M rmat = {1,0,0,1};
        ll cq = q, rq = 1;
        while(A) {
            if (A & 1) {
                rq = (rq * cq)%MOD;
                rmat = rmat * cmat;
            }
            cmat = cmat * cmat;
            cq = (cq * cq)%MOD;

            A /= 2;
        }

        mat = rmat;
        q = rq;
    }

    q = div2(q);
    ll p = div2(mat.a11);
    if (p == 0) q = 1;
    printf("%I64d/%I64d\n", p, q);
}