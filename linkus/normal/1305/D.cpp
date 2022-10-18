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
#define N 1001
 
vi adj[N];
bool kk[N];

bool rem(int v, int wh, int p = 0){
    if(v == wh){
        /* kk[v] = 0; */
        /* kk.erase( */
        return 1;
    }
    FORR(i,adj[v]){
        if(i == p) continue;
        if(rem(i,wh,v)){
            kk[v] = 0;
            /* whatis(v) */
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    int f,s;
    FOR(i,1,n){
        cin >> f >> s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    int dist[n+1][n+1];
    memset(dist,63,sizeof dist);
    for(int i = 1; i <= n; ++i){
        dist[i][i] = 0;
        for(auto &x: adj[i])
            dist[i][x] = 1;
    }
    for(int i=1;i<=n;++i)
        for(int k=1;k<=n;k++)
            for(int j=1;j<=n;++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    vi lf;
    FORE(i,1,n){
        kk[i] = 1;
        if(adj[i].size() == 1){
            lf.pb(i);
        }
    }
    int m = lf.size();
    int ile = n/2;
    srand(time(0));
    random_shuffle(all(lf));
    /* for(int i = 0; i+1 < m; i += 2){ */
    for(;;){
        vi gd;
        FORE(i,1,n){
            /* whatis(i) */
            /* whatis(kk[i]) */
            if(kk[i] && adj[i].size() == 1){
                gd.pb(i);
                /* ++cnt; */
                /* wh = i; */
            }
        }
        /* whatis(gd.size()) */
        if(gd.size() <= 1) break;
        --ile;
        int m = gd.size();
        random_shuffle(all(gd));
        pi bs = {-1,-1};
        FOR(i,1,m){
            bs = max(bs,mp(dist[gd[0]][gd[i]],gd[i]));
        }
        whatis(gd)
        /* ile--; */
        /* int ff = lf[i]; */
        /* int ss = lf[i+1]; */
        int ff = gd[0];
        int ss = bs.e2;
        assert(ff != ss);
        assert(ss != -1);
        cout << "? " << ff << ' ' << ss << endl;
        int wh;
        cin >> wh;
        assert(rem(ff,wh));
        assert(rem(ss,wh));
        if(wh == ff || wh == ss){
            cout << "! " << wh << endl;
            return 0;
        }
    }
    while(ile--){
        vi gd;
        FORE(i,1,n){
            whatis(i)
            whatis(kk[i])
            if(kk[i]){
                gd.pb(i);
                /* ++cnt; */
                /* wh = i; */
            }
        }
        /* whatis(gd.size()) */
        if(gd.size() == 1) break;
        int m = gd.size();
        random_shuffle(all(gd));
        pi bs = {-1,-1};
        FOR(i,1,m){
            bs = max(bs,mp(dist[gd[0]][gd[i]],gd[i]));
        }
        whatis(gd)
        /* int m = gd.size(); */
        /* int f = rand()%m; */
        /* int s = rand()%m; */
        /* while(s == f) s = rand()%m; */
        int ff = gd[0];
        int ss = bs.e2;
        assert(ff != ss);
        assert(ss != -1);
        cout << "? " << ff << ' ' << ss << endl;
        int wh;
        cin >> wh;
        assert(rem(ff,wh));
        assert(rem(ss,wh));
    }
    int cnt = 0;
    int wh = -1;
    FORE(i,1,n){
        if(kk[i]){
            ++cnt;
            wh = i;
        }
    }
    assert(cnt == 1);
    /* assert(kk.size() == 1); */
    cout << "! " << wh << endl;
    /* cout << "! " << *kk.begin() << endl; */
}