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
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <queue>
#include <array>
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
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f){ui r=200;while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif
#ifndef UTIL_H
#define UTIL_H



template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};

struct	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	inline ui size(int u) { return -P[find(u)]; }
	vector<int> P;
	size_t comp;
};



#endif

class DTheMajesticBrownTreeSnake {
public:
    int N, A, B, LEN;
    vector<vector<int>> E;
    vector<int> D, DUP;
    vector<int> P, Good;
    set<pii> Cache;

    bool findHim(int u, int p, vector<int>&Path) {
        if (u == B) return true;

        for (int v: E[u]) {
            if (v != p) {
                Path.push_back(v);
                if (findHim(v, u, Path)) return true;
                Path.pop_back();
            }
        }
        return false;
    }

    int depth(int u, int p) {
        P[u] = p;
        D[u] = 0;
        for (int v : E[u]) {
            if (v != p) {
                D[u] = max(D[u], 1 + depth(v, u));
            }
        }
        return D[u];
    }

    void check(vector<int> X) {
        int a = X[0], b = X.back();
        if (Cache.find({a,b}) != Cache.end()) return;

        Cache.insert({a,b});

        int par = X[LEN - 1];
        while (true) {
            pii furthest = {-1, -1};
            for (int c: E[b]) {
                if (c != par) {
                    furthest = max(furthest, {D[c]+1, c});
                }
            }
            if (P[b] != -1 && P[b] != par) {
                furthest = max(furthest, {DUP[b], P[b]});
            }
            if (furthest.x != -1) {
                par = b;
                X.push_back(b = furthest.y);
            } else {
                break;
            }
        }

        reverse(X.begin(),X.end());
        X.resize(LEN+1);
        check(X);
    }

    void depthUp(int u, int up) {
        DUP[u] = up;
        up++;
        int M = E[u].size();
        vector<int> A(M), P(M+1, 0), S(M+1, 0);
        for (int i = 0; i < M; ++i) { A[i] = D[E[u][i]] + 2; }
        for (int i = 0; i < M; ++i) P[i+1] = max(P[i], A[i]);
        for (int i = 0; i < M; ++i) S[M-i-1] = max(S[M-i], A[M-i-1]);
        for (int i = 0; i < M; ++i) depthUp(E[u][i], max({P[i], S[i+1], up}));
    }

    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for (int t = 0; t < T; ++t) {
            Cache.clear();
            cin >> N >> A >> B;
            --A; --B;
            E.assign(N, {});
            for (int i = 0; i < N - 1; ++i) {
                int a, b; cin >> a >> b; --a; --b;
                E[a].push_back(b);
                E[b].push_back(a);
            }

            Good.assign(N, 0);
            vector<int> Path{A};
            findHim(A, -1, Path);
            LEN = Path.size() - 1; // number of edges

            D.assign(N, 0);
            P.assign(N, 0);
            DUP.assign(N, 0);
            depth(0, -1);

            for (int i = 1; i < N; ++i) E[i].erase(find(E[i].begin(),E[i].end(),P[i]));
            depthUp(0, 0);
            for (int i = 0; i < N; ++i) {
                for (int j: E[i]) if (D[j] >= LEN-1) Good[i]++;
                if (i != 0 && DUP[i] >= LEN) Good[i]++;
            }
            check(Path);
            reverse(Path.begin(),Path.end());
            check(Path);

            UnionFind UF(N);
            for (int i = 0; i < N; ++i) {
                for (int j: E[i]) {
                    if (Good[i] < 3 && Good[j] < 3) UF.unite(i, j);
                }
            }

            bool ok = false;
            for (pii s: Cache) {
                bool sxa = UF.united(s.x, A);
                bool sxb = UF.united(s.x, B);
                bool sya = UF.united(s.y, A);
                bool syb = UF.united(s.y, B);
                if (sxa && syb) continue;
                if (sxb && sya) continue;
                ok = true;
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }
};



int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	DTheMajesticBrownTreeSnake solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}