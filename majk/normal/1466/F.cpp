#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

#define x first
#define y second
typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

struct	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	inline ui size(int u) { return -P[find(u)]; }
	vector<int> P;
	size_t comp;
};

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	/*extended GCD(slow):ll t=0,nt=1,r=N,nr=a;while(nr){ll q=r/nr;t-=q*nt;swap(t,nt);r-=q*nr;swap(r,nr);}assert(r<=1);return(t<0)?t+N:t;*/
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x<0?N+x:x) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if (v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
    inline Field<N>&operator-=(const Field<N>&o) {if (v<o.v) v -= o.v-N; else v-=o.v; return *this; }
    inline Field<N>&operator*=(const Field<N>&o) {v=(ull)v*o.v % N; return *this; }
    inline Field<N>&operator/=(const Field<N>&o) { return *this*=inv(o.v); }
    inline Field<N> operator+(const Field<N>&o) const {Field<N>r{*this};return r+=o;}
    inline Field<N> operator-(const Field<N>&o) const {Field<N>r{*this};return r-=o;}
    inline Field<N> operator*(const Field<N>&o) const {Field<N>r{*this};return r*=o;}
    inline Field<N> operator/(const Field<N>&o) const {Field<N>r{*this};return r/=o;}
    inline Field<N> operator-() {if(v) return {(int)(N-v)}; else return {0};};
    inline Field<N>& operator++() { ++v; if (v==N) v=0; return *this; }
    inline Field<N> operator++(int) { Field<N>r{*this}; ++*this; return r; }
    inline Field<N>& operator--() { --v; if (v==-1) v=N-1; return *this; }
    inline Field<N> operator--(int) { Field<N>r{*this}; --*this; return r; }
    inline bool operator==(const Field<N>&o) const { return o.v==v; }
	inline bool operator!=(const Field<N>&o) const { return o.v!=v; }
	inline explicit operator ui() const { return v; }
	inline static vector<Field<N>>fact(int t){vector<Field<N>>F(t+1,1);for(int i=2;i<=t;++i){F[i]=F[i-1]*i;}return F;}
	inline static vector<Field<N>>invfact(int t){vector<Field<N>>F(t+1,1);Field<N> X{1};for(int i=2;i<=t;++i){X=X*i;}F[t]=1/X;for(int i=t-1;i>=2;--i){F[i]=F[i+1]*(i+1);}return F;}
private: ui v;
};
template<unsigned int N>istream &operator>>(std::istream&is,Field<N>&f){unsigned int v;is>>v;f=v;return is;}
template<unsigned int N>ostream &operator<<(std::ostream&os,const Field<N>&f){return os<<(unsigned int)f;}
template<unsigned int N>Field<N> operator+(int i,const Field<N>&f){return Field<N>(i)+f;}
template<unsigned int N>Field<N> operator-(int i,const Field<N>&f){return Field<N>(i)-f;}
template<unsigned int N>Field<N> operator*(int i,const Field<N>&f){return Field<N>(i)*f;}
template<unsigned int N>Field<N> operator/(int i,const Field<N>&f){return Field<N>(i)/f;}


typedef Field<1000000007> FieldMod;

class FEuclidsNightmare {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M; cin >> N >> M;
        UnionFind UF(M+1);
        vector<int> Ans;
        for (int i = 0; i < N; ++i) {
            int a,b = 0,c; 
            cin >> c >> a; 
            if (c>1) cin >> b;
            if (UF.unite(a,b)) Ans.push_back(i+1);
        }

        cout << FieldMod{2}.pow(Ans.size()) << ' ' << Ans.size() << '\n' << Ans;
    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	FEuclidsNightmare solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}