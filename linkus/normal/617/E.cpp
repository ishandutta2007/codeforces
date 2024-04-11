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
#define whatis(x) cerr << #x << " is " << (x) << endl;
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

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

inline int64_t hilbertOrder(int x, int y, int pow, int rotate = 0){
	if (pow == 0){
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

// supposively simpler and slightly faster
/* constexpr int logn = 20; */
constexpr int logn = 17;
constexpr int maxn = 1 << logn;

long long hilbertorder(int x, int y)
{
	long long d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | (rx * 3 ^ static_cast<int>(ry));
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //1. precompute pairs
    //2. sort by l, fix l, lower_bound/segtree on r
    //nah, sqrt decomposition mo's go brrr
    //ac in one go, gj
    int n,m,k;
    sc(n,m,k);
    int a[n];
    GET(a);
    /* FORR(i,a) */
    /*     i ^= k; */
    static vi wh[2*N];
    int xr = 0;
    int prexr[n];
    wh[0].pb(-1); // important little thing
    FOR(i,0,n){
        /* wh[a[i]].pb(i); */
        wh[xr ^= a[i]].pb(i);
        prexr[i] = xr;
    }
    array<int,3> qus[m];
    ll res[m];
    /* int ord[m]; */ // watch out for that
    ll ord[m];
    int kk = 0;
    while((1 << kk) < n) ++kk;
    FOR(i,0,m){
        sc(qus[i][0], qus[i][1]);
        --qus[i][0];
        --qus[i][1];
        qus[i][2] = i;
        /* ord[i] = hilbertOrder(qus[i][0], qus[i][1], kk); */
        // TLE xdd
        // I guess dlatego e uyem intw zamiast llw na ord hmmm
        // yep
        // nice, 1887ms hilbertOrder() vs 2854ms n/sqrt(m)+1
        /* ord[i] = hilbertorder(qus[i][0], qus[i][1]); */
        // this one 1934ms
    }
    /* int bucket = n / sqrt(n) + 1; */ // not like this actually!
    int bucket = n / sqrt(m) + 1; // like this
    /* sort(qus,qus+m,[&](auto &f, auto &s){return f[0] / bucket != s[0] / bucket ? f[0] / bucket < s[0] / bucket : f[1] > s[1];}); */
    // actually this can be made faster with some % 2
    /* sort(qus,qus+m,[&](auto &f, auto &s){return f[0] / bucket != s[0] / bucket ? f[0] / bucket < s[0] / bucket : (f[1] > s[1]) ^ (f[0] / bucket % 2);}); */
    sort(qus,qus+m,[&](auto &f, auto &s){return f[0] / bucket != s[0] / bucket ? f[0] / bucket < s[0] / bucket : (f[1] == s[1] ? 0 : ((f[1] > s[1]) ^ (f[0] / bucket % 2)));});
    /* sort(qus,qus+m,[&](auto &f, auto &s){return f[0] / bucket != s[0] / bucket ? f[0] / bucket < s[0] / bucket : (f[1] > s[1]);}); */
    // wowow, that actually works even slightly faster than hilbert, damn
    /* sort(qus,qus+m,[&](auto &f, auto &s){return ord[f[2]] < ord[s[2]];}); */
    // doesn't work interestingly^^
    /* sort(qus,qus+m,[&](array<int,3> &f, array<int,3> &s){return ord[f[2]] < ord[s[2]];}); */
    ll cr = 0;
    int l = qus[0][0], r = qus[0][0]-1;
    int cnt[2*N] = {};
    ++cnt[~r ? prexr[r] : 0];
    FORR(i,qus){
        whatis(i[0])
        whatis(i[1])
        // sprytne, zamiast robienia zawsze lower_boundow, mozemy tez
        // aktualizowac co przesunicia county kadego z xorw -> getting rid
        // of that log
        // w cnt jest prefxr [l-1;r]
        //
        // -> Dayummm 1903ms -> 202ms neat
        while(r < i[1]){
            whatis("++r")
            ++r;
            int need = prexr[r] ^ k;
            whatis(need)
            whatis(wh[need])
            // can rem pref na [l-1;r-1]
            /* cr += lower_bound(all(wh[need]), r) - lower_bound(all(wh[need]), l-1); */
            cr += cnt[need];
            ++cnt[prexr[r]];
        }
        while(r > i[1]){
            whatis("--r")
            int need = prexr[r] ^ k;
            // can rem pref na [l-1;r-1]
            /* cr -= lower_bound(all(wh[need]), r) - lower_bound(all(wh[need]), l-1); */
            --cnt[prexr[r]];
            cr -= cnt[need];
            --r;
        }
        while(l > i[0]){
            whatis("--l")
            --l;
            // takie x >= l && x <= r ze (prexr[x] ^ prexr[l-1]) == k
            int need = (l ? prexr[l-1] : 0) ^ k;
            // [l,r]
            /* cr += lower_bound(all(wh[need]), r+1) - lower_bound(all(wh[need]), l); */
            /* ++cnt[prexr[l]]; */
            // order?
            // well done
            /* ++cnt[l ? prexr[l-1] : 0]; */
            cr += cnt[need];
            ++cnt[l ? prexr[l-1] : 0];
        }
        while(l < i[0]){
            whatis("++l")
            // takie x >= l && x <= r ze (prexr[x] ^ prexr[l-1]) == k
            int need = (l ? prexr[l-1] : 0) ^ k;
            // [l,r]
            /* cr += lower_bound(all(wh[need]), r+1) - lower_bound(all(wh[need]), l); */
            // forgot to change sugn here
            /* cr -= lower_bound(all(wh[need]), r+1) - lower_bound(all(wh[need]), l); */
            // order?
            // gj
            --cnt[l ? prexr[l-1] : 0];
            cr -= cnt[need];
            /* --cnt[prexr[l]]; */
            ++l;
        }
        whatis(cr)
        res[i[2]] = cr;
    }
    FORR(i,res)
        cout << i << '\n';
    // mo's damn
    /* int fix = 0; */
    /* int ile = 0; */
    /* FOR(i,0,n){ */
    /*     /1* FORR(x,wh[sth]){ *1/ */
    /*     /1* } *1/ */
    /*     int sth = k ^ fix; */
    /*     ile += wh[sth].end() - lower_bound(all(wh[sth]), i); */
    /*     /1* whatis(i) *1/ */
    /*     /1* whatis(wh[sth].end() - lower_bound(all(wh[sth]), i)) *1/ */
    /*     fix ^= a[i]; */
    /* } */
    /* whatis(ile) */
}