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
 class RField {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline int pow(int a, ll p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
    /*extended GCD(slow):ll t=0,nt=1,r=N,nr=a;while(nr){ll q=r/nr;t-=q*nt;swap(t,nt);r-=q*nr;swap(r,nr);}assert(r<=1);return(t<0)?t+N:t;*/
    inline int inv(int a){return pow(a,N-2);}
public:
    inline RField(int x = 0, int N = 0) : N(N), v(x) {}
    inline RField pow(int p){return (*this)^p; }
    inline RField operator^(ll p){return {pow(v,p),N};}
    inline RField&operator+=(const RField&o) {checkMod(o);if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline RField&operator-=(const RField&o) {checkMod(o);if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; }
    inline RField&operator*=(const RField&o) {checkMod(o);v=ll(v)*o.v % N; return *this; }
    inline RField&operator/=(const RField&o) {checkMod(o); return *this*={inv(o.v),N}; }
    inline RField operator+(const RField&o) const {RField r{*this};return r+=o;}
    inline RField operator-(const RField&o) const {RField r{*this};return r-=o;}
    inline RField operator*(const RField&o) const {RField r{*this};return r*=o;}
    inline RField operator/(const RField&o) const {RField r{*this};return r/=o;}
    inline RField operator-() {if(v) return {N-v,N}; else return {0,N};};
    inline RField& operator++() { ++v; if (v==N) v=0; return *this; }
    inline RField operator++(int) { RField r{*this}; ++*this; return r; }
    inline RField& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline RField operator--(int) { RField r{*this}; --*this; return r; }
    inline bool operator==(const RField&o) const { return o.v==v; }
    inline bool operator!=(const RField&o) const { return o.v!=v; }
    inline explicit operator int() const { return v; }
    void checkMod(const RField&o) {
        if (N == 0 && o.N == 0) {
            throw std::runtime_error("No modulus set");
        } else if (N == 0) {
            N = o.N;
        } else if (o.N != 0 && N != o.N) {
            cerr << N << ' ' << o.N << endl;
            throw std::runtime_error("Different moduli");
        }
    }
//    inline static vector<RField>fact(int t){vector<RField>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
//    inline static vector<RField>invfact(int t){vector<RField>F(t+1,1);RField X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private:
    int v; int N;
};
//istream &operator>>(std::istream&is,RField&f){unsigned int v;is>>v;f=v;return is;}
ostream &operator<<(std::ostream&os,const RField&f){return os<<int(f);}
RField operator+(int i,const RField&f){return i+f;}
RField operator-(int i,const RField&f){return i-f;}
RField operator*(int i,const RField&f){return i*f;}
RField operator/(int i,const RField&f){return i/f;}


class VisitOfTheGreat {
public:
void solve(istream& cin, ostream& cout) {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int K, P;
        ll L, R;
        cin >> K >> L >> R >> P;

        if (P == 2) {
            cout << (K+1)%2 << '\n';
            continue;
        }

        if (K == 1) {
            cout << 2 << '\n';
            continue;
        }



        bool isOdd = K%2;
        auto Y = RField{2, P-1} ^ L;
        auto X = RField{K%P, P} ^ int(Y);
        R -= L;

        if (K%P == 0 && Y == 0) X = RField{0, P};

        RField Z;
        if (X == 0) {
            Z = {1, P};
        } else if (X == 1) {
            Z = RField{2, P} ^ ((R+1)%(P-1));
        } else {
            Z = ((X ^ int(RField{2, P-1} ^ (R+1))) - 1) / (X-1);
        }
        if (isOdd) {
            Z /= RField{2, P} ^ (R%(P-1));
        }

        cout << Z << '\n';

    }
}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	VisitOfTheGreat solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}