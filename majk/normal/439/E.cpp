#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template <unsigned int N> class Field {
    typedef unsigned int ui;
    typedef unsigned long long ull;
	inline ui pow(ui a, ui p){ui r=1,e=a;while(p){if(p&1){r=((ull)r*e)%N;}e=((ull)e*e)%N;p>>=1;}return r;}
	/*extended GCD(slow):ll t=0,nt=1,r=N,nr=a;while(nr){ll q=r/nr;t-=q*nt;swap(t,nt);r-=q*nr;swap(r,nr);}assert(r<=1);return(t<0)?t+N:t;*/
	inline ui inv(ui a){return pow(a,N-2);}
public:
    inline Field(int x = 0) : v(x) {}
	inline Field<N> pow(int p){return (*this)^p; }
	inline Field<N> operator^(int p){return {(int)pow(v,(ui)p)};}
    inline Field<N>&operator+=(const Field<N>&o) {if ((ll)v+o.v >= N) v += o.v - N; else v += o.v; return *this; }
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
typedef pair<int,int> pii;
#define x first
#define y second
typedef Field<1000000007> FieldMod;
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }


constexpr int MX = 1e5;
int main() {
    vector<int> S(MX+1, 0);
    for (int i = 2; i <= MX; ++i) {
        if (S[i] == 0) {
            for (int j = i; j <= MX; j += i) S[j] = i;
        }
    }

    auto F = FieldMod::fact(2*MX);
    auto I = FieldMod::invfact(2*MX);

    int T; cin >> T;
    for (int q = 0; q < T; ++q) {
        int N, C; cin >> N >> C;
        vector<pii> Q{{1,1}};
        int n = N;
        while (n != 1) {
            int f = S[n];
            while (S[n] == f) n /= f;
            vector<pii> R;
            for (pii q:Q) {
                R.push_back(q);
                R.push_back({q.x*f, -q.y});
            }
            swap(Q,R);
        }
       
        FieldMod ans = 0;
        for (pii r:Q) {
            // distribute N/r.x-F among C people
            if (N/r.x >= C) {
                FieldMod cur = F[N/r.x - 1] * I[N/r.x - C] * I[C - 1];
                ans += r.y==1?cur:-cur;
            }
        }
        cout << ans << '\n';
    }
}