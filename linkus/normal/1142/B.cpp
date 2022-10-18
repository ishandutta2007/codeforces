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
#define N 200051

int ds[N][19]; //dystance do 2^ktej liczby

int a[N],p[N];
bool vis[N];
/* vi pos[N+2]; */
int nx2[N];

int t[N*2];
int n = N;

int query(int l, int r){
    int res = INF;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            res = min(res,t[l++]);
            //res += t[l++];
        if(r&1)
            res = min(res,t[--r]);
            //res += t[--r];
    }
    return res;
}

void d1(int v){
    vis[v] = 1;
    /* auto it = lower_bound(all(pos[nx[a[v]]]),v); */
    if(nx2[v] == INF){
        FOR(i,0,19)
            ds[v][i] = INF;
    }
    else{
        ds[v][0] = nx2[v];
        if(!vis[nx2[v]])
            d1(nx2[v]);
        FOR(i,1,19){
            ds[v][i] = ds[ds[v][i-1]][i-1];
            if(ds[v][i] == INF) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,q;
    sc(n,m,q);
    memset(t,127,sizeof t);
    FOR(i,0,n) sc(p[i]);
    int nx[n];
    FOR(i,0,n-1){
        nx[p[i]] = p[i+1];
    }
    int ls[n+1];
    memset(ls,-1,sizeof ls);
    nx[p[n-1]] = p[0];
    FOR(i,0,m){
        sc(a[i]); //pos[a[i]].pb(i);
    }
    for(int i = m-1; i >= 0; --i){
        ls[a[i]] = i;
        if(~ls[nx[a[i]]]){
            nx2[i] = ls[nx[a[i]]];
        }
        else{
            nx2[i] = INF;
        }
        /* whatis(i) */
        /* whatis(nx2[i]) */
    }
    memset(ds,127,sizeof ds);
    FOR(i,0,m){
        if(!vis[i]) d1(i);
    }
    /* FOR(i,0,m){ */
    /*     whatis(ds[i][0]) */
    /*     whatis(ds[i][1]) */
    /* } */
    FOR(i,0,m){
        int il = n-1;
        int d = i;
        int val = 0;
        while(il){
            if(il&1){
                d = ds[d][val];
            }
            if(d == INF) break;
            il >>= 1;
            ++val;
        }
        /* ac[i] = d; */
        t[i+N] = d;
        /* whatis(i) */
        /* whatis(ac[i]) */
    }
    for(int i = N; --i;){
        t[i] = min(t[i<<1],t[i<<1|1]);
    }
    int l,r;
    while(q--){
        sc(l,r);
        --l,--r;
        /* whatis(query(l,r+1)); */
        /* FOR(i,l,r+1) whatis(ac[i]) */
        cout << (query(l,r+1) <= r ? '1' : '0');
    }
}