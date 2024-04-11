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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        vi vec;
        int cnt[100007]{}; // t * to??? XXX
        auto ins = [&](int x){
            if(++cnt[x] == 1)
                vec.push_back(x);
        };
        constexpr ll mod = 998244353;
        ll res = 0;
        /* ll cr = 0; */
        /* for(int i = n - 1; i >= 0; --i){ */
        /* for(int i = n - 1; i >= 0; --i){ */
        for(int j = n - 1; j >= 0; --j){
            /* ins(100004); */
            /* cnt[100004] = n - i; */
            cnt[100004] = 1;
            vec.push_back(100004);
            /* while(vec.size() && !cnt[vec.back()]) */
            /*     vec.pop_back(); */
            /* int cr = a[i]; */
            int cr = a[j];
            vi nwvec;
            sort(all(vec)); // sqrt * log hmm
            vec.erase(unique(all(vec)),vec.end());
            /* whatis(i) */
            /* for(int i = 0; i < (int)vec.size(); ++i){ */
            for(int i = 0; i < (int)vec.size(); ++i){
                /* ins(100004); */ // ? xd.
                /* if(!cnt[vec[i]]){ */
                /*     swap(vec[i], vec.back()); // leetcode strat <3. */
                /*     vec.pop_back(); */
                /*     --i; */
                /* } */
                /* else{ */
                assert(cnt[vec[i]]);
                int cn = cnt[vec[i]];
                int ile = (cr + vec[i] - 1) / vec[i];
                int nw = cr / ile;
                /* whatis(vec[i]) */
                /* whatis(cn) */
                /* whatis(ile) */
                /* whatis(nw) */
                /* res += ile * cnt[vec[i]]; */
                /* res += (ile - 1) * cnt[vec[i]]; */
                /* res += (i + 1) * (ile - 1) * cnt[vec[i]]; */
                // bruh XD i mam tutaj shadowowane.
                // bruh XD i mam tutaj shadowowane.
                /* res += (n - i - 1) * (ile - 1) * cnt[vec[i]]; */
                /* res += (n - j - 1) * (ile - 1) * cnt[vec[i]]; */
                res += (ll)(j + 1) * (ile - 1) % mod * cnt[vec[i]];
                res %= mod;
                // -> Dobrze XDDD
                // Czyli bym to wbi wtedy, gdyby nie shadowwing eh.
                // -> added to F8.
                /* cr += (ile - 1) * cnt[vec[i]]; */
                assert(nw <= vec[i]);
                cnt[vec[i]] = 0;
                /* cnt[nw] += ile; */
                cnt[nw] += cn;
                cnt[nw] %= mod;
                nwvec.push_back(nw);
                /* } */
            }
            vec = std::move(nwvec);
            /* res += cr; */
        }
        cout << res << '\n';
    }
}