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
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
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
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define N 524288
//nearest sufficient power of 2

int t[N << 1];

inline int __gcd(int x, int y){
    while(y){
        /* swap(x %= y,y); */
        x %= y;
        if(!x){
            return y;
        }
        y %= x;
    }
    return x;
}

int k,n;

inline bool query(int v, int tl, int tr, int l, int r, int val){
    /* whatis(v) */
    /* whatis(tl) */
    /* whatis(tr) */
    /* whatis(l) */
    /* whatis(r) */
    /* whatis(t[v]) */
    if(t[v] % val == 0)
        return 1;
    if(v >= n){
        /* whatis(k) */
        if(!--k)
            return 0;
        /* whatis(k) */
        return 1;
    }
    int tm = (tl+tr) >> 1;
    if(tm >= l){
        if(!query(v << 1,tl,tm,l,min(tm,r),val))
            return 0;
    }
    if(tm+1 <= r){
        if(!query(v << 1|1,tm+1,tr,max(l,tm+1),r,val))
            return 0;
    }
    return 1;
}

inline void modify(int pos, int val){
    t[pos += n] = val;
    while(pos >>= 1)
        t[pos] = __gcd(t[pos<<1],t[pos<<1|1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q,mode,f,s,val;
    sc(n);
    int actn = n;
    n = 524288;
    int cur;
    for(int i = 0; i < actn; ++i){
        sc(cur);
        t[i+n] = cur;
    }
    for(int i = n; --i;)
        t[i] = __gcd(t[i<<1],t[i<<1|1]);
    sc(q);
    /* k = 2; */
    /* whatis(query(1,0,n-1,0,2,4)) */
    while(q--){
        sc(mode,f,s);
        if(mode == 1){ //query
            sc(val);
            k = 2;
            cout << (query(1,0,n-1,f-1,s-1,val) ? "YES\n" : "NO\n");
        }
        else{
            modify(f-1,s);
        }
    }
}