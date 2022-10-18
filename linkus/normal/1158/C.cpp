#pragma GCC optimize("O3")
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
#define N 500002
int t[N << 2];
int lazy[N << 2];

void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    lazy[v] = 0;
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = min(t[v<<1] , t[v<<1|1]);
}

void push(int v){
    if(lazy[v]){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        t[v<<1] += lazy[v];
        t[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int inc){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += inc;
        lazy[v] += inc;
        return;
    }
    push(v);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),inc);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,inc);
    t[v] = min(t[v<<1],t[v<<1|1]);
}

pair<int,int> query(int v, int tl, int tr, int l, int r){
    if(l > r) return {0x7f7f7f7f,0x7f7f7f7f};
    /* if(t[v]){ */
    /*     return {0x7f7f7f7f,0x7f7f7f7f}; */
    /* } */
    if(tl == l && tr == r && tr == tl){
        return {t[v],tl};
        /* if(t[v]){ */
        /*     return {0x7f7f7f7f,1}; */
        /* } */
        /* return {t[v],v}; */
    }
    push(v);
    int tm = (tl+tr)>>1;
    if(t[v<<1] < t[v<<1|1]){
        return query(v<<1,tl,tm,l,min(tm,r));
    }
    else{
        return query(v<<1|1,tm+1,tr,max(l,tm+1),r);
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n;
        sc(n);
        int a[n];
        GET(a);
        FORR(i,a) --i;
        vi adj[n];
        int deg[n];
        memset(deg,0,n<<2);
        FOR(i,0,n){
            if(a[i] < 0) continue;
            if(i+1 < n)
                ++deg[i+1];
            if(a[i] != n){
                --deg[a[i]];
            }
            /*     adj[a[i]].pb(i); */
            /*     ++deg[i]; */
            /* } */
        }
            /* whatis(adj[0].size()) */
        FOR(i,1,n) deg[i] += deg[i-1];
        FOR(i,0,n){
            if(a[i] < 0) continue;
            if(a[i] != n){
                adj[a[i]].pb(i);
                ++deg[i];
            }
        }
        /* whatis(deg[0]) */
        build(1,0,n-1,deg);
        vi ord;
        vi noinc;
        bool bad = 0;
        FOR(xxx,0,n){
            auto xd = query(1,0,n-1,0,n-1);
            /* whatis(xd) */
            if(xd.e1){
                cout << "-1\n";
                bad = 1;
                break;
            }
            /* whatis(xd.e2) */
            ord.pb(xd.e2);
            modify(1,0,n-1,xd.e2,xd.e2,INF);
            /* whatis(xd.e2) */
            /* whatis(n) */
            /* whatis(adj[0].size()) */
            FORR(i,adj[xd.e2]){
                /* whatis(i) */
                modify(1,0,n-1,i,i,-1);
            }
            if(a[xd.e2] > 0){
                modify(1,0,n-1,xd.e2+1,a[xd.e2]-1,-1);
            }
        }
        if(bad) continue;
        int ans[n];
        int it = n;
        FOR(i,0,n){
            ans[ord[i]] = it--;
        }
        FORR(i,ans)
            cout << i << ' ';
        cout << '\n';
        /* FOR(i,0,n){ */
        /*     deg[i] = */
        /* } */
    }
}