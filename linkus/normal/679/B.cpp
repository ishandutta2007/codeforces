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

vector<ll> pows;
map<ll,pair<ll,ll>> dp;

pair<ll,ll> rec(ll cr){
    if(dp.count(cr)) return dp[cr];
    /* if(!cr) return 0; */
    /* if(cr < 8) return {cr,cr}; */
    if(cr == 0) return {cr,cr};
    /* if(~dp[cr]) */
    /*     return dp[cr]; */
    auto wh = (lower_bound(all(pows),cr+1)-1);
    /* whatis(wh) */
    pair<ll,ll> f = rec(cr-*wh);
    ++f.e1;
    f.e2 += *wh;
    if(wh-pows.begin()){
        pair<ll,ll> s = rec(*(wh)-1);
        /* ++s.e1; */
        /* s.e2 += *(wh-1); */
        /* pair<ll,ll> s = rec(*wh-*(wh-1)-1); */
        /* ++s.e1; */
        /* s.e2 += *(wh-1); */
        f = max(f,s);
    }
    /* return dp[cr] = rec(cr-wh)+1; */
    /* return rec(cr-wh)+1; */
    return dp[cr] = f;
}

void xd(ll cr, int poz){
    if(cr > 1e15) return;
    whatis(cr)
    whatis(poz)
    auto it = (lower_bound(all(pows),cr+1));
    if(cr+*(it-1) < *it) --it;
    while(*it < 1e15 && cr+*(it) >= *(it+1)) ++it;
    whatis(cr)
    whatis(*it)
    xd(cr+*it,poz+1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    FORE(i,1,100005){
        pows.pb((ll)i*i*i);
    }
    /* xd(1,1); */
    /* whatis(rec(41)) */
    ll n;
    sc(n);
    pair<ll,ll> ret = rec(n);
    cout << ret.e1 << ' ' << ret.e2 << '\n';
    /* whatis(rec(215970)) */
    /* memset(dp,-1,sizeof dp); */
    /* ll n; */
    /* sc(n); */
    /* dp[0] = 0; */
    /* map<int,int> mpp; */
    /* pair<ll,ll> bs = {-1,-1}; */
    /* for(ll i = max((ll)1,n-100); i <= n; ++i){ */
        /* bs = max(bs,mp((ll)rec(i),i)); */
    /* FOR(i,1,50){ */
    /*     cout << i << ": " << rec(i) << '\n'; */
    /*     /1* ++mpp[rec(i)]; *1/ */
    /* } */
    /* cout << bs.e1 << ' ' << bs.e2 << '\n'; */
    /* whatis(mpp) */
}