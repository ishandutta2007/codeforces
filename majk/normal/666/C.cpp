/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Majk
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

#ifndef MOD_H
#define MOD_H
template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
    inline ui inv(ui a) {
        ll t=0,nt=1,r=N,nr=a;
        while(nr) { ll q=r/nr; t-=q*nt; swap(t,nt); r-=q*nr; swap(r,nr); }
        assert(r<=1); return (t<0) ? t+N : t;
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
    inline Field<N> operator-() {return {-v};};
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
#endif

int Z = 100005;

class TaskC {
public:
	void solve(istream& cin, ostream& cout) {
		int Q; cin >> Q;
		string S; cin >> S;
		vector<FieldMod> F = FieldMod::fact(Z);
		vector<FieldMod> I = FieldMod::invfact(Z);
		vector<FieldMod> P26(Z), P25(Z), P(Z);
		P25[0] = P26[0] = P[0] = 1;
		for (int i = 1; i < Z; ++i) {
			P25[i] = P25[i-1]*25;
			P26[i] = P26[i-1]*26;
			P[i] = P25[i]/P26[i];
		}

		vector<pair<pii, int>> M;

		for (int i = 0; i < Q; ++i) {
			int T;
			cin >> T;
			if (T == 1) {
				cin >> S;
			} else {
				int N;
				cin >> N;
				int f = M.size();
				M.push_back({{S.size(), N}, f});
			}
		}

		if (M.size() == 0) return;

		vector<FieldMod> R(M.size());
		sort(M.begin(), M.end());
		int lastL = 0;
		int lastN = 0;
		FieldMod ans = 0;
		for (auto &m: M) {
			int L = m.x.x;
			int N = m.x.y;


			if (N < L) { R[m.y] = 0; continue; }

			if (lastL != L) {
				ans = 0;
				lastN = L-1;
				lastL = L;
			}


			for (int i = lastN + 1; i <= N; ++i) {
				ans += F[i-1] * I[i-L] * I[L-1] * P[i];
			}

			R[m.y] = ans * P26[N] / P25[L];
			lastN = N;
		}

		for (auto &r: R) cout << r << '\n';
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskC solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}