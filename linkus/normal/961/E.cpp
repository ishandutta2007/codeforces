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

#define N 200007
int t[N << 1];
int n;

/* inline int query(int l, int r){ */
/*     int ret = 0; */
/*     for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){ */
/*         if(l&1) */
/*             ret += t[l++]; */
/*         if(r&1) */
/*             ret += t[--r]; */
/*     } */
/*     return ret; */
/* } */

/* inline void modify(int pos){ */
/*     for(t[pos += n] = 0;pos >>= 1;) */
/*         t[pos] = t[pos << 1] + t[pos << 1 | 1]; */
/* } */

inline void updf(int pos){
    for(;pos < n; pos |= (pos+1))
        ++t[pos];
}

inline void upd(int pos){
    for(;pos < n; pos |= (pos+1))
        --t[pos];
}

inline int query(int r){
    int ret = 0;
    for(;r >= 0; r = (r & (r+1))-1)
        ret += t[r];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    int a[n];
    GET(a);
    pair<int,int> in[n];
    FOR(i,0,n){
        in[i]= {a[i],i};
    }
    sort(in,in+n);
    ll ans = 0;
    FOR(i,0,n)
        updf(i);
    /* for(int i = n << 1; --i >= n;) */
    /*     t[i] = 1; */
    /* for(int i = n; --i;) */
    /*     t[i] = t[i << 1] + t[i << 1 | 1]; */
    int it = 0;
    FOR(i,1,n){
        while(it < n && in[it].e1 <= i){
            /* modify(in[it].e2); */
            upd(in[it].e2);
            ++it;
        }
        /* ans += query(0, min(i-1,a[i]-1)); */
        ans += query(min(i-1,a[i]-1));
    }
    cout << ans << '\n';
}