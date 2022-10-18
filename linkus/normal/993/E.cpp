#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
typedef int64_t ll;
#define int ll
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

//fast fft

// Radewoosh ma ciekawe z jakimi anti-precision error tricks:
// https://codeforces.com/contest/1548/submission/124596600
// ^^ wic no NTT needed even with modulos.

// Also, atcoder implementation seems cool (but has internal dependencies):
// https://github.com/atcoder/ac-library/blob/master/atcoder/convolution.hpp

typedef complex<double> cd;
/* typedef complex<long double> cd; */
const double PI = 4*atan(1.);


void fft(vector<cd> &a, bool invert){
    int n = a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
    for(int len = 2; len <= n; len <<= 1){
		double ang = 2*PI/len * (invert ? -1 : 1);
        cd wn(cos(ang),sin(ang));
        for(int i = 0; i < n; i += len){
            cd w(1);
            for(int j = 0; j < len/2; ++j){
				cd u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
                w *= wn;
            }
        }
    }
    if(invert)
        FOR(i,0,n) a[i] /= n;
}

vector<int> multiply(const vector<int> a, const vector<int> b){
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int k = 0;
    while((1 << k) < (int)(a.size()+b.size()-1)) ++k;
    int n = 1 << k;
    fa.resize(n,0), fb.resize(n,0);
    fft(fa,0);
    fft(fb,0);
    for(int i = 0; i < n; ++i){
        fa[i] *= fb[i];
    }
    fft(fa,1);
    vector<int> res(n);
    for(int i = 0; i < n; ++i){
        res[i] = int(fa[i].real()+0.5);
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* vector<int> a = {3,1,0}; */
    /* vector<int> b = {0,1,0,0}; */
    /* auto ret = multiply(a,b); */
    /* FORR(i,ret) cout << i << ' '; */
    /* cout << '\n'; */
    int n, X;
    sc(n, X);
    int a[n];
    GET(a);
    int cntlt = 0;
    FORR(i,a){
        cntlt += i < X;
        i = i < X;
    }
    /* vi b = {0}; */
    vi b = {-1};
    FOR(i,0,n){
        if(a[i]){
            b.push_back(i);
        }
    }
    ll res1 = 0;
    b.push_back(n);
    vi c;
    // can n - 0 occur?
    // edge case i guess
    /* FOR(i,1,n){ */
    FOR(i,1,b.size()){
        c.push_back(b[i] - b[i-1]);
    }
    int it = 0;
    /* ll res1 = 0; */
    FOR(i,0,n){
        if(a[i])
            continue;
        it = max(it, i);
        while(it + 1 < n && a[it + 1] == 0)
            ++it;
        res1 += it - i + 1;
    }
    cout << res1 << ' ';
    // k = 1 -> c[0] * c[1] + c[1] * c[2]
    // k = 2 -> c[0] * c[2] + c[1] * c[3] ...
    vi crev = c;
    /* whatis(c) */
    /* whatis(crev) */
    reverse(all(crev));
    int nn = c.size();
    auto ret = multiply(c, crev);
    /* whatis(ret) */
    FORE(k,1,n){
        /* cout << ret[nn+k-1] << ' '; */
        if(nn+k-1 < ret.size())
            cout << ret[nn+k-1] << ' ';
        else
            cout << "0 ";
    }
    cout << '\n';
}