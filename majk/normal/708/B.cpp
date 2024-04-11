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

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    ll M = 1,K = 1;
    while (M*(M-1) < 2*a00) ++M;
    while (K*(K-1) < 2*a11) ++K;
    if (M*(M-1) != 2*a00 || K*(K-1) != 2*a11) {
        cout << "Impossible" << endl;
        return 0;
    } 
    
    if (a10 == 0 && a01 == 0) {
        if (K == 1) {
            K = 0;
        } else if (M == 1) {
            M = 0;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    
    if (M <= 1 && K <= 1) { 
        if (a10 == 1 && a01 == 0) {
            cout << "10" << endl;
        } else if (a01 == 1 && a10 == 0) {
            cout << "01" << endl;
        } else if (a01 == 0 && a10 == 0) {
            cout << "1" << endl;
        } else {
            cout << "Impossible" << endl;
        }
        return 0;
    }
    
    if ((M+K)*(M+K-1) != 2*(a00+a10+a01+a11)) {
        cout << "Impossible" << endl;
    } else {
        char * X = new char[M+K+1];
        X[M+K] = 0;
        int i = 0;
        ll F = a01;
        while (M > 0 && F >= K) {
            X[i++] = '0';
            F -= K;
            --M;
        }
        while (F < K) {
            X[i++] = '1';
            --K;
        }
        if (M > 0) {
            X[i++] = '0';
            --M;
        }
        while (F > 0) {
            X[i++] = '1';
            --F;
            --K;
        }

        while (M > 0) {
            X[i++] = '0';
            --M;
        }
        cout << X << endl;
    }
}