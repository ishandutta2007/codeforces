/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
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
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
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
    /* bool tran = 0; */
    bool hor[n][m - 1]; // 1 -> != 0 -> ==
    bool ver[n - 1][m]; // likewise.
    /* vector<vector<bool>> hor(n, vector<bool>(m-1)); // 1 -> != 0 -> == */
    /* vector<vector<bool>> ver(n-1, vector<bool>(m)); // likewise. */
    char c;
    FOR(x,0,m-1){
        getch(c);
        hor[0][x] = c == 'N';
    }
    FOR(i,0,n-1){
        FOR(x,0,m){
            getch(c);
            ver[i][x] = c == 'N';
        }
        FOR(x,0,m-1){
            getch(c);
            hor[i+1][x] = c == 'N';
        }
    }
    // syf zbytni tak tbh, juz lepiej napisac 2 wersje wewnetrznego xd.
    /* if(n > m){ */
    /*     tran = 1; */
    /*     swap(n,m); */
    /*     swap(hor, ver); */
    /* } */
    int a[n][m];
    if(k >= 2){
        if(m >= n){
            a[0][0] = 0;
            FOR(x,1,m){
                a[0][x] = a[0][x-1] ^ hor[0][x-1];
            }
            FOR(i,1,n){
                int ileb = 0;
                /* whatis(ileb) */
                a[i][0] = 0;
                /* FOR(x,0,m){ */
                FOR(x,1,m){
                    a[i][x] = a[i][x-1] ^ hor[i][x-1];
                    ileb += (a[i][x] != a[i-1][x]) ^ ver[i-1][x];
                }
                // forgot about ileb for first elem in row / col (only
                // discovered while writing col version code).
                ileb += (a[i][0] != a[i-1][0]) ^ ver[i-1][0];
                if(ileb > m / 2){
                    ileb = 0;
                    a[i][0] = 1;
                    /* FOR(x,0,m){ */
                    FOR(x,1,m){
                        a[i][x] = a[i][x-1] ^ hor[i][x-1];
                        ileb += (a[i][x] != a[i-1][x]) ^ ver[i-1][x];
                    }
                    ileb += (a[i][0] != a[i-1][0]) ^ ver[i-1][0];
                    /* whatis("2nd") */
                    /* whatis(ileb) */
                    assert(ileb <= m / 2);
                }
            }
        }
        else{
            a[0][0] = 0;
            FOR(x,1,n){
                a[x][0] = a[x-1][0] ^ ver[x-1][0];
            }
            FOR(i,1,m){
                int ileb = 0;
                /* whatis(ileb) */
                a[0][i] = 0;
                /* FOR(x,0,m){ */
                FOR(x,1,n){
                    /* a[x][i] = a[x][i-1] ^ ver[x-1][i]; */
                    a[x][i] = a[x-1][i] ^ ver[x-1][i];
                    ileb += (a[x][i] != a[x][i-1]) ^ hor[x][i-1];
                }
                ileb += (a[0][i] != a[0][i-1]) ^ hor[0][i-1];
                if(ileb > n / 2){
                    ileb = 0;
                    a[0][i] = 1;
                    /* FOR(x,0,m){ */
                    FOR(x,1,n){
                        /* a[x][i] = a[x][i-1] ^ ver[x-1][i]; */
                        a[x][i] = a[x-1][i] ^ ver[x-1][i];
                        ileb += (a[x][i] != a[x][i-1]) ^ hor[x][i-1];
                    }
                    /* whatis("2nd") */
                    /* whatis(ileb) */
                    ileb += (a[0][i] != a[0][i-1]) ^ hor[0][i-1];
                    assert(ileb <= n / 2);
                }
            }
        }
        cout << "YES\n";
        FOR(i,0,n){
            FOR(x,0,m){
                cout << a[i][x] + 1 << ' ';
            }
            cout << '\n';
        }
    }
    else{
        int tot = (n-1) * m + (m-1) * n;
        int ileb = 0;
        FORR(i,hor)
            FORR(x,i)
                ileb += x;
        FORR(i,ver)
            FORR(x,i)
                ileb += x;
        if((tot - ileb) * 4 >= tot * 3){
            cout << "YES\n";
            FOR(i,0,n){
                FOR(x,0,m){
                    cout << "1 ";
                }
                cout << '\n';
            }
        }
        else{
            cout << "NO\n";
        }
    }
}