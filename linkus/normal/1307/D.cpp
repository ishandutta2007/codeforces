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
    int n,m,k;
    sc(n,m,k);
    vi adj[n];
    int wh[k];
    GET(wh);
    FORR(i,wh)
        --i;
    FOR(i,0,m){
        int f,s;
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    queue<int> qu;
    int d1[n],d2[n];
    memset(d1,127,n<<2);
    memset(d2,127,n<<2);
    {
        qu.push(0);
        d1[0] = 0;
        while(!qu.empty()){
            int v = qu.front(); qu.pop();
            FORR(i,adj[v]){
                if(d1[v]+1 < d1[i]){
                    d1[i] = d1[v]+1;
                    qu.push(i);
                }
            }
        }
    }
    {
        qu.push(n-1);
        d2[n-1] = 0;
        while(!qu.empty()){
            int v = qu.front(); qu.pop();
            FORR(i,adj[v]){
                if(d2[v]+1 < d2[i]){
                    d2[i] = d2[v]+1;
                    qu.push(i);
                }
            }
        }
    }
    assert(d1[n-1] == d2[0]);
    int res = 0;
    //mxe min(d1[i] + d2[j] + 1, d1[j] + d2[i] + 1) foreach i,j in k arr
    //convex hull trick kappa
    //2 pointer (czy tam set) -> fixuj blizsza d1 -> najdalsza od d2 dajsza od d1 od nodea
    vi bl1,bl2;
    FORR(i,wh){
        if(d1[i] <= d2[i])
            bl1.pb(i);
        if(d2[i] <= d1[i])
            bl2.pb(i);
    }
    sort(all(bl1),[&](int f, int s){return d1[f] > d1[s];});
    int nd[k];
    memcpy(nd,wh,k<<2);
    sort(nd,nd+k,[&](int f, int s){return d1[f] < d1[s];});
    int it = k-1;
    int mxo = -2137000;
    FORR(i,bl1){
        while(it >= 0 && (d1[nd[it]] > d1[i] || (d1[nd[it]] == d1[i] && i != nd[it]))){
            whatis(nd[it])
            mxo = max(mxo,d2[nd[it]]);
            --it;
        }
        whatis(i)
        whatis(d1[i]+mxo+1)
        res = max(res,d1[i]+mxo+1);
    }
    sort(all(bl2),[&](int f, int s){return d2[f] > d2[s];});
    sort(nd,nd+k,[&](int f, int s){return d2[f] < d2[s];});
    mxo = -2137000;
    it = k-1;
    FORR(i,bl2){
        while(it >= 0 && (d2[nd[it]] > d2[i] || (d2[nd[it]] == d2[i] && i != nd[it]))){
            mxo = max(mxo,d1[nd[it]]);
            --it;
        }
        res = max(res,d2[i]+mxo+1);
    }
    /* FORR(i,wh){ */
    /*     FORR(x,wh){ */
    /*         if(i == x) continue; */
    /*         int cr = min(d1[i]+d2[x],d1[x]+d2[i])+1; */
    /*         res = max(res,cr); */
    /*     } */
    /* } */
    cout << min(res,d1[n-1]);
}