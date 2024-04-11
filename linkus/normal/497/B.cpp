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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int a[n];
    GET(a);
    vi pos[2];
    FOR(i,0,n){
        --a[i];
        pos[a[i]].pb(i);
    }
    vector<pi> ret;
    FORE(t,1,n){
        vi ile(2,0);
        /* int l = 0; */
        bool k = 1;
        /* whatis(t) */
            /* int lol = 0; */
        int en = -1;
        int last = -1;
        for(;;){
            /* ++lol; */
            /* if(lol == 10) return 0; */
            /* whatis(nxit[0]) */
            /* whatis(nxit[1]) */
            auto it1 = lower_bound(all(pos[0]),en);
            auto it2 = lower_bound(all(pos[1]),en);
            bool k1 = pos[0].end()-it1 >= t;
            bool k2 = pos[1].end()-it2 >= t;
            if(!k1 && !k2){
                if(en != n)
                    k = 0;
                break;
            }
            int p1 = k1 ? *(it1+t-1) : INF;
            int p2 = k2 ? *(it2+t-1) : INF;
            if(p1 < p2){
                ++ile[0];
                last = 0;
                en = p1+1;
            }
            else{
                ++ile[1];
                last = 1;
                en = p2+1;
            }
            /* if(nxit[0] != INF && (nxit[1] == INF || (pos[0][nxit[0]] <= pos[1][nxit[1]]))){ */
            /*     while(it[1] < (int)pos[1].size() && pos[1][it[1]] < pos[0][nxit[0]]){ */
            /*         ++it[1]; */
            /*     } */
            /*     end = pos[0][nxit[0]]+1; */
            /*     last = 0; */
            /*     it[0] = nxit[0]+1; */
            /*     ++ile[0]; */
            /* } */
            /* else{ */
            /*     while(it[0] < (int)pos[0].size() && pos[0][it[0]] < pos[1][nxit[1]]){ */
            /*         ++it[0]; */
            /*     } */
            /*     end = pos[1][nxit[1]]+1; */
            /*     last = 1; */
            /*     it[1] = nxit[1]+1; */
            /*     ++ile[1]; */
            /* } */
            /* whatis(ile) */
            /* FOR(x,0,2){ */
            /* } */
        }
        if(!k) continue;
        if(ile[0] == ile[1]) continue;
        if(max(ile[0],ile[1]) != ile[last]) continue;
        ret.pb({max(ile[0],ile[1]),t});
    }
    /* whatis(ret) */
    sort(all(ret));
    cout << ret.size() << '\n';
    FORR(i,ret)
        cout << i.e1 << ' ' << i.e2 << '\n';
}