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
#define N 7010

int n;
vi adj[2];
int dp[N][2]; //0 -> n-1
int cnt[N][2]; //ile winnujacych wrogow w nxcie

void recrev(int pos, int k);

void aktwcnt(int pos, int k){ //aktualizuj ilosc winnujacych przeciwnych dla nextow
    FORR(i,adj[k^1]){
        int pr = pos-i;
        if(pr < 0) pr += n;
        if(!pr) continue;
        if(++cnt[pr][k^1] == (int)adj[k^1].size()){
            dp[pr][k^1] = 0;
            recrev(pr,k^1);
        }
    }
}

void recrev(int pos, int k){ //loseing
    FORR(i,adj[k^1]){
        int pr = pos-i;
        if(pr < 0) pr += n;
        if(!pr) continue;
        if(dp[pr][k^1] != 1){
            dp[pr][k^1] = 1;
            aktwcnt(pr,k^1);
        }
    }
}

/* void rec(int pos, int k){ */
/*     dp[pos][k] = 2; */
/*     bool dr = 0; */
/*     int nd0 = n-pos; */
/*     if(binary_search(all(adj[k]),nd0)){ */
/*         dp[pos][k] = 1; */
/*         return; */
/*     } */
/*     FORR(i,adj[k]){ */
/*         int nx = (pos+i)%n; */
/*         /1* if(!nx){ *1/ */
/*         /1*     dp[pos][k] = 1; *1/ */
/*         /1*     return; *1/ */
/*         /1* } *1/ */
/*         if(!~dp[nx][k^1]) */
/*             rec(nx,k^1); */
/*         if(dp[nx][k^1] == 0){ */
/*             dp[pos][k] = 1; */
/*             return; */
/*         } */
/*         else if(dp[nx][k^1] == 2){ */
/*             dr |= 1; */
/*         } */
/*     } */
/*     if(!dr) */
/*         dp[pos][k] = 0; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp,-1,sizeof dp);
    sc(n);
    FOR(i,0,2){
        int sz;
        sc(sz);
        while(sz--){
            int cr;
            sc(cr);
            adj[i].pb(cr);
        }
    }
    FOR(i,0,2) sort(all(adj[i]));
    string xd[] = {"Lose","Win","Loop"};
    recrev(0,0);
    recrev(0,1);
    FOR(i,0,2){
        FOR(x,1,n){
            if(!~dp[x][i]) dp[x][i] = 2;
            /* if(!~dp[x][i]){ */
            /*     rec(x,i); */
            /* } */
            cout << xd[dp[x][i]] << ' ';
        }
        cout << '\n';
    }
}