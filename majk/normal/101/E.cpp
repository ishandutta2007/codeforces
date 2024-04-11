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
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(ll x) { return x?8*sizeof(ll)-__builtin_clzll(x):0; }

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

class ECandiesAndStones {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M, P; cin >> N >> M >> P;
        vector<int> X(N), Y(M); cin >> X >> Y;
        for (int&x:X) x %= P;
        for (int&y:Y) y %= P;
        vector<pii> D(M, {0,0});
        vector<vector<pii>> R;
        vector<int> CH, W;
        int C = 120;
        D[0] = {(X[0] + Y[0])%P, 0};
        for (int j = 0; j < M-1; ++j) D[j+1] = max(D[j+1], {D[j].x + (X[0] + Y[j+1])%P, D[j].y});

        for (int i = 0; i < N; ++i) {
            if (i % C == 0 || i == N-1) {
                CH.push_back(i);
                R.push_back(D);
                for (int j = 0; j < M; ++j) D[j].y = j;
            }

            if (i != N-1) {
                vector<pii> E(M, {0, 0});
                for (int j = 0; j < M; ++j) {
                    E[j] = max(E[j], {D[j].x + (X[i + 1] + Y[j]) % P, D[j].y});
                }

                for (int j = 0; j < M-1; ++j) E[j+1] = max(E[j+1], {E[j].x + (X[i+1] + Y[j+1])%P, E[j].y});

                swap(E, D);
            }
        }


        int Q = R.size();
        W.resize(Q);
        int w = M-1;
        W[Q-1] = w;
        for (int i = Q-1; i >= 1; --i) W[i-1] = w = R[i][w].y;
        
        R.clear();

        vector2<pii> E( C+1, M,  {0,0});
        string Ans;
        for (int i = 0; i < Q-1; ++i) {
            int L = CH[i+1] - CH[i];
            
            int l = W[i ], r = W [ i+1 ]+1;
            for(int i = 0; i<= L; ++i) for (int j = l; j< r; ++j) E[i][ j]={ 0, 0 } ;
         E[0][l] = {100, l};

            for (int j = 0; j < L; ++j) {
                for (int k = l; k < r; ++k) {
                 E[j + 1][k] = max( E[j + 1][k], { E[j][k].x + (X[CH[i] + j + 1] + Y[k]) % P, k});
                }

                for (int k = l; k < r - 1; ++k) {
                    E[j + 1][k + 1] = max (E[j + 1][k + 1],
                                           {E[j + 1][k].x + (X[CH[i] + j + 1] + Y[k + 1]) % P, E[j+1][k].y});
                }
            }


            w = W[i+1];
            string S;
            for (int j = L; j > 0; --j) {
                int t = E[j][w].y;
                S += string(w-t, 'S');
                S += 'C';
                w = t;
            }
            reverse(S.begin(),S.end());
            Ans += S;
        }

        string S;
        for (int a = 0; a < W[0]; ++a) S += 'S';
        Ans = S + Ans;

        int a = 0, b = 0, t = (X[0]+Y[0])%P;
        for (char c: Ans) {
            if (c == 'C') ++a;
            else ++b;
            t += (X[a] + Y[b])%P;
        }

//        cout << Ans.size() << '\n';
//        cout << t << endl;
        cout << t << '\n';
        cout << Ans << '\n';


    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ECandiesAndStones solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}