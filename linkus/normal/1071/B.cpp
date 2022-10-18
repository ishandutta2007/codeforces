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
template<class T> ostream& operator<<(ostream &os, array<T,5> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 2000

int n,k;
string a[N];
string org[N];

int bs[N][N];
void d1(int x, int y, int lf){
    if(!lf) return;
    if(a[0][0] != 'a'){
        a[0][0] = org[0][0] = 'a';
        --lf;
    }
    bs[0][0] = lf;
    queue<pair<int,int>> qu;
    qu.push({0,0});
    bool vis[N][N];
    memset(vis,0,sizeof vis);
    while(!qu.empty()){
        int x = qu.front().e1;
        int y = qu.front().e2;
        qu.pop();
        if(!bs[x][y]) continue;
        if(vis[x][y]) continue;
            vis[x][y] = 1;
        if(org[x][y] != 'a'){
            a[x][y] = 'a';
            --bs[x][y];
        }
        if(x+1 != n){
            bs[x+1][y] = max(bs[x+1][y],bs[x][y]);
            qu.push({x+1,y});
        }
        if(y+1 != n){
            bs[x][y+1] = max(bs[x][y+1],bs[x][y]);
            qu.push({x,y+1});
        }
    }
    /* if(bs[x][y] >= lf) return; */
    /* bs[x][y] = lf; */
    /* if(!lf) return; */
    /* if(org[x][y] != 'a') */
    /*     a[x][y] = 'a', --lf; */
    /* if(x+1 < n){ */
    /*     d1(x+1,y,lf); */
    /* } */
    /* if(y+1 < n){ */
    /*     d1(x,y+1,lf); */
    /* } */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    FOR(i,0,n){
        cin >> a[i]; org[i] = a[i];
        /* cin >> a[i]; */
    }
    d1(0,0,k);
    char mn[2*n+5];
    memset(mn,127,sizeof mn);
    string ans;
    queue<array<int,4>> qu;
    mn[0] = 0;
    qu.push({{0,0,1,0}});
    int dd = 1;
    bool vis[N][N];
    memset(vis,0,sizeof vis);
    while(!qu.empty()){
        /* whatis(qu.front()) */
        int x = qu.front()[0];
        int y = qu.front()[1];
        int d = qu.front()[2];
        int bf = qu.front()[3];
        qu.pop();
        if(d != dd){
            if(mn[dd]){
                /* whatis(dd) */
                /* whatis((char)mnc[dd]); */
                ans += (char)mn[dd];
            }
            dd = d;
        }
        if(bf > mn[d-1]) continue;
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        char c = a[x][y];
        mn[d] = min(mn[d],c);
        if(x+1 != n){
            qu.push({{x+1,y,d+1,c}});
        }
        if(y+1 != n){
            qu.push({{x,y+1,d+1,c}});
        }
    }
    ans += mn[dd];
    cout << ans << '\n';
}