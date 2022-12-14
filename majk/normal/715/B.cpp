/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author majk
 */

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

#define x first
#define y second
typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return x?8*sizeof(int)-__builtin_clz(x):0; }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif
// #include "../l/mod.h"

class TaskB {
public:

    int N, M, L, S, T;
    vector<vector<pii>> E;
    vector<vector<pii>> F;

    void copyGraph(ll v, ll null) {
        int over = null ? v % null : 0;
        int single = null ? v / null : 0;

        F.clear();
        F.resize(N);

        for (int i = 0; i < N; ++i) {
            for (pii e: E[i]) {
                if (e.y == 0) {
                    if (i < e.x) {
                        int cost = single + (over-- > 0);
                        F[i].push_back({e.x, cost});
                        F[e.x].push_back({i, cost});
                    }
                } else {
                    F[i].push_back(e);
                }
            }
        }
    }

    ll cost() {
        minheap<pair<ll,int>> H;
        vector<ll> D(N, 1e18);
        D[S] = 0;
        H.push({0LL, S});
        while (!H.empty()) {
            auto h = H.top(); H.pop();
            if (D[h.y] != h.x) continue;
            for (pii f: F[h.y]) {
                if (f.y + h.x < D[f.x]) {
                    D[f.x] = f.y + h.x;
                    H.push({D[f.x], f.x});
                }
            }
        }

        return D[T];
    }

    void solve(istream& cin, ostream& cout) {
        cin >> N >> M >> L >> S >> T;
        E.resize(N);

        ll null = 0;

        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            E[u].push_back({v,w});
            E[v].push_back({u,w});
            null += w==0;
        }

        ll ans = bsh(null, null * L, [&](ll x) {
            copyGraph(x, null);
            return cost() <= L;
        });

        if (ans == -1) {
            cout << "NO\n";
        } else {
            copyGraph(ans, null);
            if (cost() != L) {
                cout << "NO\n";
            } else {

                cout << "YES\n";
                for (int i = 0; i < N; ++i) {
                    for (pii f: F[i]) {
                        if (i < f.x) {
                            cout << i << ' ' << f.x << ' ' << f.y << '\n';
                        }
                    }
                }
            }
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}