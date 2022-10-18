#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef complex<double> cd;
const double PI = 4*atan(1.);

/* void fft (vector<cd> & a, bool invert) { */
/* 	int n = (int) a.size(); */

/* 	for (int i=1, j=0; i<n; ++i) { */
/* 		int bit = n >> 1; */
/* 		for (; j>=bit; bit>>=1) */
/* 			j -= bit; */
/* 		j += bit; */
/* 		if (i < j) */
/* 			swap (a[i], a[j]); */
/* 	} */

/* 	for (int len=2; len<=n; len<<=1) { */
/* 		double ang = 2*PI/len * (invert ? -1 : 1); */
/* 		cd wlen (cos(ang), sin(ang)); */
/* 		for (int i=0; i<n; i+=len) { */
/* 			cd w (1); */
/* 			for (int j=0; j<len/2; ++j) { */
/* 				cd u = a[i+j],  v = a[i+j+len/2] * w; */
/* 				a[i+j] = u + v; */
/* 				a[i+j+len/2] = u - v; */
/* 				w *= wlen; */
/* 			} */
/* 		} */
/* 	} */
/* 	if (invert) */
/* 		for (int i=0; i<n; ++i) */
/* 			a[i] /= n; */
/* } */

#define N 550000

int rev[N];
cd wlen_pw[N];

void fft (cd a[], int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;

		cd wlen (cos(ang), sin(ang));
		wlen_pw[0] = cd (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;

		for (int i=0; i<n; i+=len) {
			cd t,
				*pu = a+i,
				*pv = a+i+len2,
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu += t;
			}
		}
	}

	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
    }
}

int nn,n,m,k,kk;

vector<int> multiply(vector<int> a, vector<int> b, int n){
    cd fa[n],fb[n];
    fill(copy(a.begin(),a.end(),fa),fa+n,0);
    fill(copy(b.begin(),b.end(),fb),fb+n,0);
    fft(fa,n,0);
    fft(fb,n,0);
    for(int i = 0; i < n; ++i){
        fa[i] *= fb[i];
    }
    fft(fa,n,1);
    vector<int> res(n);
    for(int i = 0; i < n; ++i){
        res[i] = int(fa[i].real()+0.5);
    }
    return res;
}

/* Prec. error max_ans/1e15 (2.5e18) for (long) doubles, so int rounding works
for doubles with answers 0.5e15, e.g. for sizes 2^20 and RANDOM ints in [0,45k],
assuming DBL_MANT_DIG=53 and LDBL_MANT_DIG=64. Consider normalizing and brute.*/
#define REP(i,n) for(int i = 0; i < int(n); ++i)
typedef double ld; // 'long double' is 2.2 times slower
struct C { ld re, im;
	C operator * (const C & he) const {
		return C{re * he.re - im * he.im,
				re * he.im + im * he.re};
	}
	void operator += (const C & he) { re += he.re; im += he.im; }
};
void dft(vector<C> & a, bool rev) {
	const int n = a.size();
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		static vector<C> t[30];
		vector<C> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			const ld ang = 2 * acosl(0) / len;
			REP(i, len) om[i] = i%2 || !who ?
					C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				 const C x = a[i+k], y = a[i+k+len]
						* C{om[k].re, om[k].im * (rev ? -1 : 1)};
				a[i+k] += y;
				a[i+k+len] = C{x.re - y.re, x.im - y.im};
			}
	}
	if(rev) REP(i, n) a[i].re /= n;
}
template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
		bool split = false, bool normalize = false) {
	if(a.empty() || b.empty()) return {};
	T big = 0; if(normalize) { // [0,B] into [-B/2, B/2]
		assert(a.size() == b.size()); // equal size!!!
		for(T x : a) big = max(big, x);
		for(T x : b) big = max(big, x);
		big /= 2;
	}
	int n = a.size() + b.size();
	vector<T> ans(n - 1);
	/* if(min(a.size(),b.size()) < 190) { // BRUTE FORCE
		REP(i, a.size()) REP(j, b.size()) ans[i+j] += a[i]*b[j];
		return ans; } */
	while(n&(n-1)) ++n;
	auto foo = [&](const vector<C> & w, int i, int k) {
		int j = i ? n - i : 0, r = k ? -1 : 1;
		return C{w[i].re + w[j].re * r, w[i].im
				- w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
	};
	if(!split) { // standard fast version
		vector<C> in(n), done(n);
		REP(i, a.size()) in[i].re = a[i] - big;
		REP(i, b.size()) in[i].im = b[i] - big;
		dft(in, false);
		REP(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
		dft(done, true);
		REP(i, ans.size()) ans[i] = is_integral<T>::value ?
				llround(done[i].re) : done[i].re;
	//REP(i,ans.size())err=max(err,abs(done[i].re-ans[i]));
	}
	else { // Split big INTEGERS into pairs a1*M+a2,
		const T M = 1<<15; // where M = sqrt(max_absvalue).
		vector<C> t[2]; // This version is 2.2-2.5 times slower.
		REP(x, 2) {
			t[x].resize(n);
			auto & in = x ? b : a; // below use (in[i]-big) if normalized
			REP(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
			dft(t[x], false);
		}
		T mul = 1;
		for(int s = 0; s < 3; ++s, mul *= M) {
			vector<C> prod(n);
			REP(x, 2) REP(y, 2) if(x + y == s) REP(i, n)
				prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
			dft(prod, true); // remember: llround(prod[i].re)%MOD*mul !!!
			REP(i, ans.size()) ans[i]+= llround(prod[i].re)*mul;
		}
	}
	if(normalize) {
		T so_far = 0;
		REP(i, ans.size()) {
			if(i < (int) a.size()) so_far += a[i] + b[i];
			else so_far -= a[i-a.size()] + b[i-a.size()];
			ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
		}
	}
	return ans;
}

int cnt[1000000];
string s,t;
void dood(char c){
    vector<int> a(m);
    vector<int> b(n,0);
    /* int a[m]; */
    /* int b[n]; */
    FOR(i,0,m) a[i] = t[i] == c;
    int ls = -1000000;
    FOR(i,0,n){
        if(s[i] == c) ls = i;
        if(i-ls <= k) b[i] = 1;
    }
    ls = 1000000;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == c) ls = i;
        if(ls-i <= k) b[i] = 1;
    }
    /* vector<int> ret = multiply(a,b,nn); */
    vector<int> ret = multiply(a,b);
    /* vector<int> ret = convolution(a,b); */
    FOR(i,0,ret.size()){
        cnt[i] += ret[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m,k);
    getstr(s);
    getstr(t);
    reverse(all(s));
    while((1 << kk) < (int)(n+m-1)) ++kk;
    nn = 1 << kk;
    calc_rev(nn,kk);
    dood('A');
    dood('C');
    dood('G');
    dood('T');
    /* FOR(i,0,n+m+1) whatis(cnt[i]) */
    /* FOR(i,0,n+m+1){ */
    /*     whatis(i) */
    /*     whatis(cnt[i]) */
    /* } */
    cout << count(cnt,cnt+n+m+1,m) << '\n';
}