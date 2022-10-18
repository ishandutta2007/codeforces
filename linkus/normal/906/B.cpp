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
    int xx[] = {0,0,1,-1};
    int yy[] = {1,-1,0,0};
    int n,m;
    sc(n,m);
    int b[n][m];
    int nn = n, mm = m;
    if(nn > mm)
        swap(nn,mm);
    bool good = 1;
    if(nn == 1 && mm == 1)
        good = 1;
    else if(nn <= 2 && mm <= 3)
        good = 0;
    if(!good)
        REE("NO")
    if(nn == 1 && mm == 1){
        REE("YES\n1")
    }
    if(nn <= 3 && mm <= 3){
    /* if(nn <= 5 && mm <= 5){ */
        cout << "YES\n";
    {{
        int sz = n * m;
        int a[sz];
        iota(a,a+sz,1);
        bool adj[sz+1][sz+1];
        memset(adj,0,sizeof adj);
        {
            int b[n][m];
            FOR(i,0,sz){
                b[i/m][i%m] = a[i];
            }
            FOR(i,0,n){
                FOR(x,0,m){
                    FOR(j,0,4){
                        int ni = i+xx[j];
                        int nx = x+yy[j];
                        if(ni < 0 || nx < 0 || ni >= n || nx >= m) continue;
                        adj[b[i][x]][b[ni][nx]] = adj[b[ni][nx]][b[i][x]] = 1;
                    }
                }
            }
        }
        int res = 0;
        do{
            int b[n][m];
            FOR(i,0,sz){
                b[i/m][i%m] = a[i];
            }
            bool kk = 1;
            FOR(i,0,n){
                FOR(x,0,m){
                    FOR(j,0,4){
                        int ni = i+xx[j];
                        int nx = x+yy[j];
                        if(ni < 0 || nx < 0 || ni >= n || nx >= m) continue;
                        if(adj[b[i][x]][b[ni][nx]]){
                            kk = 0;
                        }
                    }
                }
            }
            if(kk){
                ++res;
                FOR(i,0,n){
                    FOR(x,0,m){
                        cout << b[i][x] << ' ';
                    }
                    cout << '\n';
                }
                cout << '\n';
                return 0;
            }
        }while(next_permutation(a,a+sz));
        assert(0);
        /* whatis(n) */
        /* whatis(m) */
        /* whatis(res) */
        }
    }
    }
    else if(mm == 4){
        cout << "YES\n";
        int sz = n*m;
        FOR(i,0,sz){
            b[i/m][i%m] = i+1;
        }
        if(m > n){
            FOR(i,0,n){
                int nw[m];
                int it = 0;
                nw[0] = b[i][2];
                nw[3] = b[i][1];
                nw[1] = b[i][0];
                nw[2] = b[i][3];
                memcpy(&b[i][0],nw,m << 2);
                if(i&1){
                    reverse(&b[i][0],&b[i][m]);
                }
            }
        }
        else{
            FOR(x,0,m){
                int nw[n];
                int it = 0;
                nw[0] = b[2][x];
                nw[3] = b[1][x];
                nw[1] = b[0][x];
                nw[2] = b[3][x];
                /* memcpy(&b[i][0],nw,m << 2); */
                FOR(i,0,n){
                    b[i][x] = nw[i];
                }
                if(x&1){
                    for(int i = 0; i < n/2; ++i){
                        swap(b[i][x], b[n-i-1][x]);
                    }
                    /* reverse(&b[i][0],&b[i][m]); */
                }
            }
        }
        /* if(n != nn){ */
        /*     int ret[n][m]; */
        /*     FOR(i,0,sz){ */
        /*         ret[i/m][i%m] = i+1; */
        /*     } */
        /*     map<int,int> swp; */
        /*     int it = 0; */
        /*     FOR(x,0,m){ */
        /*         FOR(i,0,n){ */
        /*             ++it; */
        /*             swp[it] = ret[i][x]; */
        /*             /1* swp[ret[i][x]] = it; *1/ */
        /*         } */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m){ */
        /*             int id = ret[i][x]-1; */
        /*             ret[i][x] = b[id/mm][id%mm]; */
        /*         } */
        /*             /1* cout << b[x][i] << ' '; *1/ */
        /*         /1* cout << '\n'; *1/ */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m) */
        /*             ret[i][x] = swp[ret[i][x]]; */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m) */
        /*             cout << ret[i][x] << ' '; */
        /*         cout << '\n'; */
        /*     } */
        /* } */
        /* else{ */
            FOR(i,0,n){
                FOR(x,0,m)
                    cout << b[i][x] << ' ';
                cout << '\n';
            }
        /* } */
    }
    else{
        cout << "YES\n";
        int sz = n*m;
        FOR(i,0,sz){
            b[i/m][i%m] = i+1;
        }
        if(m > n){
            FOR(i,0,n){
                int nw[m];
                int it = 0;
                FOR(x,0,m){
                    nw[x] = b[i][it];
                    it += 2;
                    if(it >= m)
                        it = 1;
                }
                memcpy(&b[i][0],nw,m << 2);
                if(i&1){
                    reverse(&b[i][0],&b[i][m]);
                    if(m&1){
                        for(int x = 0; x < (m-m/2)/2; ++x){
                            swap(b[i][x+m/2], b[i][m-x-1]);
                        }
                        for(int x = 0; x < m/2/2; ++x){
                            swap(b[i][x], b[i][m/2-x-1]);
                        }
                    }
                }
            }
        }
        else{
            FOR(x,0,m){
                int nw[n];
                int it = 0;
                FOR(i,0,n){
                    nw[i] = b[it][x];
                    it += 2;
                    if(it >= n)
                        it = 1;
                }
                /* memcpy(&b[i][0],nw,m << 2); */
                FOR(i,0,n){
                    b[i][x] = nw[i];
                }
                if(x&1){
                    for(int i = 0; i < n/2; ++i){
                        swap(b[i][x], b[n-i-1][x]);
                    }
                    /* reverse(&b[i][0],&b[i][m]); */
                    if(n&1){
                        for(int i = 0; i < (n-n/2)/2; ++i){
                            swap(b[i+n/2][x], b[n-i-1][x]);
                        }
                        for(int i = 0; i < n/2/2; ++i){
                            swap(b[i][x], b[n/2-i-1][x]);
                        }
                    }
                }
            }
        }
        /* if(n != nn){ */
        /*     int ret[n][m]; */
        /*     FOR(i,0,sz){ */
        /*         ret[i/m][i%m] = i+1; */
        /*     } */
        /*     map<int,int> swp; */
        /*     int it = 0; */
        /*     FOR(x,0,m){ */
        /*         FOR(i,0,n){ */
        /*             ++it; */
        /*             swp[it] = ret[it/m][i%m]; */
        /*         } */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m){ */
        /*             int id = ret[i][x]-1; */
        /*             ret[i][x] = b[id/mm][id%mm]; */
        /*         } */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m) */
        /*             ret[i][x] = swp[ret[i][x]]; */
        /*     } */
        /*     FOR(i,0,n){ */
        /*         FOR(x,0,m) */
        /*             cout << ret[i][x] << ' '; */
        /*         cout << '\n'; */
        /*     } */
        /* } */
        /* else{ */
            FOR(i,0,n){
                FOR(x,0,m)
                    cout << b[i][x] << ' ';
                cout << '\n';
            }
        /* } */
    }
    /* { */
    /*     int sz = n*m; */
    /*     int a[sz]; */
    /*     iota(a,a+sz,1); */
    /*     /1* bool adj[sz+1][sz+1]; *1/ */
    /*     vector<bool> adj[sz+1]; */
    /*     /1* memset(adj,0,sizeof adj); *1/ */
    /*     FOR(i,0,sz+1) */
    /*         adj[i].resize(sz+1); */
    /*     { */
    /*         int b[n][m]; */
    /*         FOR(i,0,sz){ */
    /*             b[i/m][i%m] = a[i]; */
    /*         } */
    /*         FOR(i,0,n){ */
    /*             FOR(x,0,m){ */
    /*                 FOR(j,0,4){ */
    /*                     int ni = i+xx[j]; */
    /*                     int nx = x+yy[j]; */
    /*                     if(ni < 0 || nx < 0 || ni >= n || nx >= m) continue; */
    /*                     adj[b[i][x]][b[ni][nx]] = adj[b[ni][nx]][b[i][x]] = 1; */
    /*                 } */
    /*             } */
    /*         } */
    /*     } */
    /*     bool kk = 1; */
    /*     FOR(i,0,n){ */
    /*         FOR(x,0,m){ */
    /*             FOR(j,0,4){ */
    /*                 int ni = i+xx[j]; */
    /*                 int nx = x+yy[j]; */
    /*                 if(ni < 0 || nx < 0 || ni >= n || nx >= m) continue; */
    /*                 if(adj[b[i][x]][b[ni][nx]]){ */
    /*                     whatis(i) */
    /*                     whatis(x) */
    /*                     kk = 0; */
    /*                 } */
    /*             } */
    /*         } */
    /*     } */
    /*     /1* assert(kk); *1/ */
    /* } */
}