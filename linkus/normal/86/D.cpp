#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = rbegin(arr)+(plus); x != rend(arr); ++x)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
/* #define getchar_unlocked() getchar() */
#define getchar_unlocked() _getchar_nolock()
/* #define puchar _putchar_nolock() */
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int res[1000001];
ll pows[200001];
ll ans;

/* inline void out(ll num){ */
/*     char buf[20]; */
/*     buf[0] = num%10; */
/*     num /= 10; */
/*     char *it = buf+1; */
/*     while(num){ */
/*         *it++ = num%10; */
/*         num /= 10; */
/*     } */
/*     while(it != buf){ */
/*         putchar(*--it+48); */
/*     } */
    /* if(num > 9){ */
    /*     out(num/10); */
    /* } */
    /* putchar(num%10+'0'); */
    /* putchar("0123456789"[num%10]); */
/* } */

inline void inc(int num){
    /* ans -= (ll)res[num]*res[num]*num; */
    ans -= pows[res[num]]*num;
    ++res[num];
    ans += pows[res[num]]*num;
    /* ans += (ll)res[num]*res[num]*num; */
}

inline void dec(int num){
    /* ans -= (ll)res[num]*res[num]*num; */
    ans -= pows[res[num]]*num;
    --res[num];
    ans += pows[res[num]]*num;
    /* ans += (ll)res[num]*res[num]*num; */
}

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3; //%4
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
/* constexpr int maxn = 1 << logn; */
constexpr int logn = 18;
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
    for(ll i = 1; i < 200001; ++i)
        pows[i] = i*i;
    int n,t;
    sc(n,t);
    int in[n];
    GET(in);
    /* const int S = sqrt(n) - (sqrt(n) == (int)sqrt(n)); */
    /* const int S = sqrt(n); */
    /* const int S = 447; */
    const int S = 447;
    /* FOR(i,0,n) */
    /*     sc(in[i]); */
    ll answer[t];
    struct qu{
        int l;
        int r;
        int id;
    };
    qu query[t];
    FOR(i,0,t){
        sc(query[i].l, query[i].r);
        /* --query[i].l, --query[i].r; */
        --query[i].l;
        query[i].id = i;
    }
    /* sort(query,query+t,[&](auto &f, auto &s){if(f.l/S == s.l/S) return f.r < s.r; return f.l < s.l;}); */
    int block[t];
    FOR(i,0,t){
        block[i] = query[i].l/S;
    }
    /* sort(query,query+t,[&](qu &f, qu &s){if(f.l/S == s.l/S) return bool((f.r<s.r)^(f.l/S&1)); return f.l < s.l;}); */
    /* sort(query,query+t,[&](qu &f, qu &s){if(block[f.id] == block[s.id]) return bool((f.r<s.r)^(block[f.id]&1)); return f.l < s.l;}); */
    int64_t ord[t];
    int k = 20;
    /* while(k < n) k <<= 1; */
    FOR(i,0,t){
        /* ord[query[i].id] =  hilbertOrder(query[i].l,query[i].r,k,0); */
        ord[query[i].id] =  hilbertorder(query[i].l,query[i].r);
    }
    sort(query,query+t,[&](qu &f, qu &s){return ord[f.id]<ord[s.id];});
    /* sort(query,query+t,[&](qu &f, qu &s){if(f.l/S != s.l/S) return f.l < s.l; return bool((f.r<s.r)^((f.l/S)&1));}); */
    int curl = 0, curr = 0;
    FORR(i,query){
        int L = i.l, R = i.r;
        while(curl < L){
            dec(in[curl++]);
        }
        while(curl > L){
            inc(in[--curl]);
        }
        while(curr < R){
            inc(in[curr++]);
        }
        while(curr > R){
            dec(in[--curr]);
        }
        answer[i.id] = ans;
    }
    FORR(i,answer){
        cout << i << '\n';
    }
}