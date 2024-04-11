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
        string s[n];
        FORR(i,s)
            getstr(i);
        // C1:
        /* ll wh[3]{}; */
        /* // (i + x) % 3 najprociej i guess */
        /* /1* FOR(ch,0,3){ *1/ */
        /* /1* } *1/ */
        /* FOR(i,0,n){ */
        /*     FOR(x,0,n){ */
        /*         if(s[i][x] == 'X'){ */
        /*             ++wh[(i+x)%3]; */
        /*         } */
        /*     } */
        /* } */
        /* int mn = min_element(wh,wh+3)-wh; */
        /* FOR(i,0,n){ */
        /*     FOR(x,0,n){ */
        /*         if(s[i][x] == 'X' && (i+x)%3 == mn){ */
        /*             s[i][x] = 'O'; */
        /*         } */
        /*     } */
        /*     cout << s[i] << '\n'; */
        /* } */
        // C2:
        /* int dp[n][4][4]; */
        // 2n(-1) tych przektnych wsm
        /* int dp[n+1][4][4]; */
        int dp[2 * n][4][4];
        /* memset(dp,127,n << 6); */
        /* memset(dp,127,(n+1) << 6); */
        memset(dp,127,n << 7);
        dp[0][1][1] = 0;
        // omg, backtrack jeszcze
        // i guess na pale moge go zrobic, jak n = 300
        /* vector<pair<int,char>> wh[2 * n]; // {nr przektnej, ktry char do zamalowania na przeciwny} */
        vector<pair<int,char>> wh[2 * n][4][4]; // {nr przektnej, ktry char do zamalowania na przeciwny}
        /* FOR(i,1,n){ */
        // bottom up ezer wsm
        // jak na koncu jest gdzies 3, to tak jakby *musze* tam to pomalowac:?
        // -> dp do n inclusive
        /* FOR(i,0,n-1){ */
        /* FOR(i,0,n){ */
        int ilex[n << 1], ileo[n << 1];
        memset(ilex,0,n << 3);
        memset(ileo,0,n << 3);
        int cc = n * n;
        FOR(i,0,n){
            FOR(x,0,n){
                if(s[i][x] == 'X'){
                    ++ilex[i+x];
                }
                else if(s[i][x] == 'O'){
                    ++ileo[i+x];
                }
                else{
                    --cc;
                }
            }
        }
        // wait, w teorii do n * 2 - 1 tylko, ale doesnt matter i guess?
        // or does it?
        /* FOR(i,0,n << 1){ */
        // settowaem out-of-bounds
        FOR(i,0,(n << 1) - 1){
            FOR(x,1,4){
                FOR(o,1,4){
                    if(dp[i][x][o] == INF)
                        continue;
                    // inf wtedy wsm, ale poza edge casem poczatkowym i guess
                    /* if(x == 3 && o == 3) */
                    /*     continue; */
                    // wsm moge z mniejsza iloscia ifow all opisac
                    // bottom up ezer wsm
                    if(x+1 < 4 && o+1 < 4){
                        /* dp[i+1][x+1][o+1] = min(dp[i+1][x+1][o+1], dp[i][x][o]); */
                        if(dp[i+1][x+1][o+1] > dp[i][x][o]){
                            dp[i+1][x+1][o+1] = dp[i][x][o];
                            wh[i+1][x+1][o+1] = wh[i][x][o];
                        }
                    }
                    if(x+1 < 4){
                        /* dp[i+1][x+1][1] = min(dp[i+1][x+1][1], dp[i][x][o] + ilex[i]); */
                        /* dp[i+1][x+1][1] = min(dp[i+1][x+1][1], dp[i][x][o] + ileo[i]); */
                        // ???? ileo[1] ????
                        /* if(dp[i+1][x+1][1] > dp[i][x][o] + ileo[1]){ */
                        /*     dp[i+1][x+1][1] = dp[i][x][o] + ileo[1]; */
                        if(dp[i+1][x+1][1] > dp[i][x][o] + ileo[i]){
                            dp[i+1][x+1][1] = dp[i][x][o] + ileo[i];
                            wh[i+1][x+1][1] = wh[i][x][o];
                            wh[i+1][x+1][1].push_back({i,'O'});
                        }
                    }
                    if(o+1 < 4){
                        /* dp[i+1][1][o+1] = min(dp[i+1][1][o+1], dp[i][x][o] + ileo[i]); */
                        /* dp[i+1][1][o+1] = min(dp[i+1][1][o+1], dp[i][x][o] + ilex[i]); */
                        /* if(dp[i+1][1][o+1] > dp[i][x][o] + ilex[1]){ */
                        /*     dp[i+1][1][o+1] = dp[i][x][o] + ilex[1]; */
                        if(dp[i+1][1][o+1] > dp[i][x][o] + ilex[i]){
                            dp[i+1][1][o+1] = dp[i][x][o] + ilex[i];
                            wh[i+1][1][o+1] = wh[i][x][o];
                            wh[i+1][1][o+1].push_back({i,'X'});
                        }
                    }
                }
            }
        }
        FOR(i,1,4){
            FOR(x,1,4){
                // ??
                /* if(dp[2 * n][i][x] <= cc / 3){ */
                if(dp[2 * n - 1][i][x] <= cc / 3){
                    whatis(t)
                    // very na pae, but that's okay
                    FORR(k,wh[2 * n - 1][i][x]){
                        FOR(i,0,n){
                            FOR(x,0,n){
                                if(i+x == k.e1){
                                    if(s[i][x] == k.e2)
                                        s[i][x] = s[i][x] == 'O' ? 'X' : 'O';
                                }
                            }
                        }
                    }
                    goto got;
                }
            }
        }
        assert(0);
        got:
        FOR(i,0,n){
            cout << s[i] << '\n';
        }
        /* assert(0); */
 }
}