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
#define N 100001

int n,m;
int bsit;
/* int a[N][6]; */
array<int,6> a[N];
int whbs[N * 5];
vector<int> vec;
vector<int> elpos[N * 5];
/* bitset<N> bspool[N]; */
bitset<N> bspool[N / 10];
constexpr int thr = 200;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m);
    FOR(i,0,n){
        FOR(x,1,m+1){
            sc(a[i][x]);
            vec.push_back(a[i][x]);
        }
        sc(a[i][0]);
    }
    /* sort(all(a)); */ // XDD. najs all. uwaga na to przy globalnych.
    // zreszt tak btw. to to by array XD.
    sort(a, a + n);
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    /* whatis(vec) */
    FOR(i,0,n){
        FOR(x,1,m+1){
            /* a[i][x] = lower_bound(all(vec), a[i][x]) - vec.begin(); */
            a[i][x] = lower_bound(all(vec), a[i][x]) - vec.begin();
            elpos[a[i][x]].push_back(i);
        }
    }
    memset(whbs,-1,sizeof whbs);
    FOR(i,0,vec.size()){
        whatis(elpos[i])
        if(elpos[i].size() > thr){
            FORR(x,elpos[i])
                bspool[bsit][x] = 1;
            whbs[i] = bsit++;
        }
    }
    int res = INF;
    FOR(i,0,n){
        bitset<N> bs;
        bs.reset();
        /* FOR(x,0,n){ */
        /*     cout << bs[x]; */
        /* } */
        FOR(x,1,m+1){
            if(whbs[a[i][x]] != -1){
                bs |= bspool[whbs[a[i][x]]];
            }
            else{
                FORR(j,elpos[a[i][x]]){
                    bs[j] = 1;
                }
            }
        }
        /* cout << bs << '\n'; */
        /* FOR(x,0,n){ */
        /*     cout << bs[x]; */
        /* } */
        /* cout << '\n'; */
        if(bs.count() != n){
            bs.flip();
            res = min(res, a[i][0] + a[bs._Find_first()][0]);
        }
    }
    cout << (res == INF ? -1 : res) << '\n';
}