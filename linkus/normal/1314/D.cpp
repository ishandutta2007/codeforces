#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
#define N 1000001

int n,k;
int a[80][80];
/* int pre[80][80]; */
vector<pi> pre[80][80];
int bs[5][5];
vi cr;
bool isincr[80];
int res = INF;

void rec(int i, int sz){
    if(i == n){
        /* if(rand()%5) // kox probability -> doesn't even pass pretest xd. */
        /* if(n > 60 && rand()%2) // kox probability -> doesn't even pass pretest xd. */
        /*     return; */
        /* int dp[k + 1][n]; */
        /* fill_n((int *)dp, (n * (k + 1)), INF / 2); */
        int nn = cr.size();
        int dp[k + 1][nn];
        fill_n((int *)dp, (nn * (k + 1)), INF / 2);
        dp[0][0] = 0;
        /* whatis(cr); */
        // precompute:
        /* int bs[nn][nn]; */
        /* memset(bs,127,sizeof bs); */
        /* FOR(i,0,nn){ */
        /*     FOR(x,0,nn){ */
        /*         FOR(j,0,n){ */
        /*             if(!isincr[j]) */
        /*                 /1* bs[i][x] = min(bs[i][x], a[i][j] + a[j][x]); *1/ */
        /*                 bs[i][x] = min(bs[i][x], a[cr[i]][j] + a[j][cr[x]]); */
        /*         } */
        /*     } */
        /* } */
        // XD, wysokie iq.
        // -> wait, or not? bo inpre jeszcze xd.
        // (guess moglbym trzyamc top6 jakies or sth)
        // -> let's do this. (po prostu first z sorted.)
        /* memset(bs,127,sizeof bs); */
        FOR(i,0,nn){
            FOR(x,0,nn){
                /* bs[i][x] = pre[cr[i]][cr[x]]; */
                bs[i][x] = 1e9+7;
                /* FORR(j, pre[i][x]){ */
                FORR(j, pre[cr[i]][cr[x]]){
                    if(!isincr[j.e2]){
                        bs[i][x] = j.e1;
                        break;
                    }
                }
            }
        }
        FOR(j, 0, k){
            // niby dla pierwszego i last j moznaby zoptowa.
            /* FORR(x,cr){ */
            /*     FOR(z,0,n){ */
            /*         if(!isincr[z]) */
            /*             dp[j+1][z] = min(dp[j+1][z], dp[j][x] + a[x][z]); */
            /*     } */
            /* } */
            /* ++j; */
            /* FOR(z,0,n){ */
            /*     if(!isincr[z]){ */
            /*         FORR(x,cr){ */
            /*             dp[j+1][x] = min(dp[j+1][x], dp[j][z] + a[z][x]); */
            /*         } */
            /*     } */
            /* } */
            /* FORR(x,cr){ */
            /*     FORR(z,cr){ */
            FOR(x,0,nn){
                FOR(z,0,nn){
                    dp[j + 2][z] = min(dp[j + 2][z], dp[j][x] + bs[x][z]);
                }
            }
            ++j;
        }
        res = min(res, dp[k][0]);
        return;
    }
    rec(i + 1, sz);
    if(sz < k / 2){
        cr.push_back(i);
        isincr[i] ^= 1;
        /* FOR(x,0,sz){ */
        /*     /1* bs[sz][x] = bs[x][sz] = 0; *1/ */
        /*     bs[sz][x] = bs[x][sz] = INF / 2; */
        /*     FOR(z,0,n){ */
        /*         // btw, to byo le, no bo mog do potem jeszcze inne do cra. */
        /*         if(!isincr[z]){ */
        /*             bs[sz][x] = min(bs[sz][x], a[i][z] + a[z][cr[x]]); */
        /*         } */
        /*     } */
        /*     // w8, do sb te xd. */
        /*     FOR(z,0,n){ */
        /*         if(!isincr[z]){ */
        /*             bs[x][sz] = min(bs[x][sz], a[cr[x]][z] + a[z][i]); */
        /*         } */
        /*     } */
        /* } */
        /* // -> do sb. */
        /* // wait XDDDDD */
        /* // przecie przed recem dla kadej pary ten precompute mog zrobi xd. */
        /* bs[sz][sz] = INF / 2; */
        /* FOR(z,0,n){ */
        /*     if(!isincr[z]){ */
        /*         bs[sz][sz] = min(bs[sz][sz], a[i][z] + a[z][i]); */
        /*     } */
        /* } */
        rec(i + 1, sz + 1);
        cr.pop_back();
        isincr[i] ^= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,k);
    FOR(i,0,n)
        FOR(x,0,n){
            sc(a[i][x]);
            // nvm
            /* if(a[i][x] == 0) */
            if(i == x)
                a[i][x] = INF / 2;
        }
    // Chad precompute:
    // -> wait, or not? bo inpre jeszcze xd.
    // -> trzymanie top6 najlepszych moe pyli.
    // -> pre as vec of pairs. {dist, posredni}
    /* memset(pre,127,sizeof pre); */
    FOR(i,0,n){
        FOR(x,0,n){
            FOR(j,0,n){
                pre[i][x].push_back({a[i][j] + a[j][x], j});
            }
            sort(all(pre[i][x]));
        }
    }
    cr = {0};
    isincr[0] = 1;
    /* memset(bs, 127, sizeof bs); */
    rec(1, 1);
    cout << res << '\n';
}