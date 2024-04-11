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
// 1 << 19 if segtree where merges matter.
#define N 300001

int t,n,m;
int a[N];
vector<pi> cnts;
set<int> xs[N];
unordered_map<int, vi> whbad;
unordered_map<int, int> xcnt;
ll res;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(t);
    while(t--){
        sc(n, m);
        xcnt.clear();
        FOR(i,0,n)
            sc(a[i]), ++xcnt[a[i]], xs[i].clear();
        xs[n].clear();
        whbad.clear();
        cnts.clear();
        FOR(i,0,m){
            int f,s;
            sc(f,s);
            whbad[f].push_back(s);
            whbad[s].push_back(f);
        }
        FORR(i,xcnt){
            xs[i.second].insert(i.first);
            whbad[i.first].push_back(i.first);
        }
        FOR(i,0,n){
            if(xs[i].size()){
                cnts.push_back({i, *xs[i].rbegin()});
            }
        }
        res = 0;
        FORR(i,xcnt){
            ll val = i.first;
            int cnt = i.second;
            FORR(x,whbad[val]){
                xs[xcnt[x]].erase(x);
                auto it = lower_bound(all(cnts), pi{xcnt[x], -INF});
                it->second = xs[xcnt[x]].empty() ? -INF : *xs[xcnt[x]].rbegin();
            }
            FORR(i,cnts){
                res = max<ll>(res, (cnt + i.first) * (val + i.second));
            }
            FORR(x,whbad[val]){
                xs[xcnt[x]].insert(x);
                auto it = lower_bound(all(cnts), pi{xcnt[x], -INF});
                it->second = *xs[xcnt[x]].rbegin();
            }
        }
        cout << res << '\n';
    }
}