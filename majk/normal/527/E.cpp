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
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

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

class datacenterdrama {
public:
    int N, M;
    vector<vector<pii>> E;
    vector<bool> U;
    vector<pii> S;

    void run(int u, vector<int>&P) {
        while (!E[u].empty() && U[E[u].back().y]) E[u].pop_back();

        if (E[u].empty()) return;

        pii v = E[u].back();
        E[u].pop_back();
        U[v.y] = true;
        P.push_back(v.x);
        run(v.x, P);
    }


    void solve(istream& cin, ostream& cout) {
        cin >> N >> M;
        E.resize(N);
        U = vector<bool>(M, false);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            E[u].push_back({v,i});
            E[v].push_back({u,i});
        }

        vector<int> Q;
        for (int i = 0; i < N; ++i) {
            while (true) {
                vector<int> P{i};
                run(i, P);
                reverse(P.begin(), P.end());
                run(i, P);

                if (P.size() == 1) {
                    // no more edges
                    break;
                }

                if (P.size() % 2 == 0) {
                    // loop of _odd_ length, just close it
                    P.push_back(P[0]);
                }

                if (P.front() == P.back()) {
                    // this is a closed loop of even length, orient it in any way
                    for (int i = 0; i + 2 < P.size(); i += 2) {
                        S.push_back({P[i], P[i + 1]});
                        S.push_back({P[i + 2], P[i + 1]});
                    }
                } else {
                    // just connect it to the mega loop
                    Q.insert(Q.end(), P.begin(), P.end());
                }
            }
        }

        if (!Q.empty()) {
            if (Q.front() != Q.back()) Q.push_back(Q[0]); // close itself
            if (Q.size()%2 == 0) Q.push_back(Q[0]); // odd length, just add one more
            for (int i = 0; i+2 < Q.size(); i+=2) {
                S.push_back({Q[i], Q[i+1]});
                S.push_back({Q[i+2], Q[i+1]});
            }
        }

        cout << S.size() << '\n';
        for (pii&s:S) {
            cout << s.x+1 << ' ' << s.y+1 << '\n';
        }
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	datacenterdrama solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}