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

namespace std { 
template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui inv(ui a) {
        /*ll t=0,nt=1,r=N,nr=a;
        while(nr) { ll q=r/nr; t-=q*nt; swap(t,nt); r-=q*nr; swap(r,nr); }
        assert(r<=1); return (t<0) ? t+N : t;*/
		ui p = N-2, r = 1, e = a;
		while (p) {
			if (p&1) r = ((ull)r*e)%N;
			e = ((ull)e*e)%N;
			p >>= 1;
		}
		return r;
    }
public:
    inline Field(int x = 0) : v(x) {}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v = (ll)v+o.v-N; else v = v+o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v = N-o.v+v; else v=v-o.v; return *this; } 
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) { return o.v==v; }
    inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]/i;}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

int main(int,char**) {
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    string SS; cin >> SS;
    char L = ' ';
    vector<int> C;
    for (auto &s: SS) {
        if (L != s) {
            C.push_back(s-'a');
            L = s;
        }
    }

    int M = C.size();
    vector<int> P(26,0);

    vector<vector<FieldMod>> S(M+2,vector<FieldMod>(M+1, 0));
    for (int i = 1; i <= M+1; i++) {
        S[i][0] = 1;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            S[i+1][j] = S[i][j] + S[i][j-1] - S[P[C[i-1]]][j-1];
        }
        P[C[i-1]] = i+1;
    }
    auto F = FieldMod::fact(10000);
    auto I = FieldMod::invfact(5000);
    FieldMod ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += F[N - 1] * I[N - i] * I[i - 1] * S[M+1][i];
    } 

    cout << ans << endl;

}