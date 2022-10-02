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
template<typename T,typename U> pair<T,U> operator+(const pair<T,U>&a,const pair<T,U>&b) { return {a.x+b.x,a.y+b.y}; }
template<typename T,typename U> pair<T,U> operator-(const pair<T,U>&a,const pair<T,U>&b) { return {a.x-b.x,a.y-b.y}; }
template<typename T,typename U> ostream& operator<<(ostream& o, const pair<T,U>&a) { return o << a.x << ' ' << a.y; }
}
// auto fraclt = [](auto&a,auto&b) { return (ll)a.x * b.y < (ll)b.x * a.y; };
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }
template<typename T> void fracn(pair<T,T>&a) {auto g=gcd(a.x,a.y);a.x/=g;a.y/=g;}
template<typename T> struct Index { int operator[](const T&t){auto i=m.find(t);return i!=m.end()?i->y:m[t]=m.size();}int s(){return m.size();} unordered_map<T,int> m; };
auto polar = [](pii&a,pii&b) { if (a.y==0&&a.x>0) return true; if (b.y==0&&b.x>0) return false; if (a.y>0&&b.y<0) return true; return !(a.y<0&&b.y>0) && ((ll)a.x*b.y-(ll)a.y*b.x)>0; };
ll ccw(const pii&a, const pii&b, const pii&c) { return (ll)(b.x-a.x)*(c.y-a.y) - (ll)(b.y-a.y)*(c.x-a.x); }
ll area(const pii&a,const pii&b,const pii&c) { return abs(ccw(a,b,c)); }

vector<pii> convexhull(const vector<pii> &v) {
    int N = v.size(); vector<pii> w(N+1); int lo = 0;
    for (int i = 0; i<N; ++i) if (v[i].y < v[lo].y) lo = i;
    pii o = v[lo];
    for (int i = 0; i<N; ++i) w[i+1] = v[i]-o;
    swap(w[1],w[lo+1]); 
    sort(w.begin()+2,w.end(),polar);
    w[0] = w[N];
    int M=1;
    for (int i=2;i<=N;++i) {
        while(ccw(w[M-1],w[M],w[i]) <= 0) if (M>1) --M; else if (i == N) break; else ++i;
        ++M;
        swap(w[M],w[i]);
    }
    vector<pii> res(M);
    for (int i=0;i<M;++i) res[i] = w[i+1]+o;
    return res;
}

int main(int,char**) {
    ios_base::sync_with_stdio(false);
    ri(N);rl(S);vector<pii> P(N);
    for (auto&p:P) cin >> p.x >> p.y;
    vector<pii> C = convexhull(P);
    assert(C.size()>=3);
    int M=C.size(),a=0,b=1,c=2,ba=0,bb=1,bc=2;
    while(true) {
        while(true) {
            while (area(C[a],C[b],C[c]) <= area(C[a],C[b],C[(c+1)%M])) c = (c+1)%M;
            if (area(C[a],C[b],C[c]) <= area(C[a],C[(b+1)%M],C[c])) b = (b+1)%M; else break;
        }
        if (area(C[a],C[b],C[c]) > area(C[ba],C[bb],C[bc])) { ba=a;bb=b;bc=c; }
        a = (a+1)%M;
        if (a==b) b = (b+1)%M;
        if (b==c) c = (c+1)%M;
        if (a==0) break;
    }

    vector<pii> r{C[ba]+C[bb]-C[bc],C[ba]-C[bb]+C[bc],C[bb]+C[bc]-C[ba]};
    for(auto &p:r) cout << p << endl;
    return 0;
}