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
 
vi adj[N];
int n;
/* vi cr; */
/* bool vis[N]; */
/* int res = INF; */

/* void d1(int v, int p){ */
/*     cr.push_back(v); */
/*     vis[v] = 1; */
/*     vi back; */
/*     FORR(i,adj[v]){ */
/*         /1* if(i == p) *1/ */
/*         /1*     continue; *1/ */
/*         if(vis[i]){ */
/*             // inc parent. */
/*             back.push_back(i); */
/*         } */
/*         else{ */
/*             d1(i, v); */
/*         } */
/*     } */
/*     cr.pop_back(); */
/*     sort(all(back)); */
/*     FORR(i,cr){ */
/*         if(!binary_search(all(back), i)){ */
/*             if(cr.size() + 2 < res) */
/*                 res = cr.size() + 2; */
/*         } */
/*     } */
/* } */

/* int n; */
/* void d2(int v, int p){ */
/*     cr.push_back(v); */
/*     vis[v] = 1; */
/*     vi back; */
/*     FORR(i,adj[v]){ */
/*         /1* if(i == p) *1/ */
/*         /1*     continue; *1/ */
/*         if(vis[i]){ */
/*             // inc parent. */
/*             back.push_back(i); */
/*         } */
/*         else{ */
/*             /1* d1(i, v); *1/ */
/*             d2(i, v); */
/*         } */
/*     } */
/*     cr.pop_back(); */
/*     sort(all(back)); */
/*     FORR(i,cr){ */
/*         if(!binary_search(all(back), i)){ */
/*             if(cr.size() + 2 == res){ */
/*                 FORR(i,cr){ */
/*                     cout << i + 1 << ' '; */
/*                 } */
/*                 cout << v + 1 << ' '; */
/*                 cout << i + 1 << ' '; */
/*                 cout << n << '\n'; */
/*                 exit(0); */
/*             } */ 
/*         } */
/*     } */
/* } */

int crc;
int comp[N];
int cnt;
vi wh;
void d1(int v){
    ++cnt;
    comp[v] = crc;
    wh.pb(v);
    FORR(i,adj[v]){
        if(comp[i])
            continue;
        d1(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* int n,m; */
    int m;
    sc(n,m);
    FOR(i,0,m){
        int f,s;
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    /* d1(0,-1); */
    queue<int> qu;
    qu.push(0);
    int dist[n];
    int pr[n];
    pr[0] = -1;
    memset(dist,127,n << 2);
    dist[0] = 0;
    int d2 = -1;
    while(!qu.empty()){
        int v = qu.front(); qu.pop();
        FORR(i,adj[v]){
            if(dist[v] + 1 < dist[i]){
                pr[i] = v;
                dist[i] = dist[v] + 1;
                if(dist[i] == 2){
                    d2 = i;
                }
                qu.push(i);
            }
        }
    }
    if(dist[n - 1] <= 4){
        /* if(dist[n - 1] == 0x7f7f7f7f) */
        /*     REE(-1) */
        cout << dist[n - 1] << '\n';
        vi vec;
        /* int cr = n; */
        int cr = n - 1;
        while(cr != -1){
            vec.push_back(cr);
            cr = pr[cr];
        }
        reverse(all(vec));
        FORR(i,vec)
            cout << i + 1 << ' ';
        cout << '\n';
        return 0;
    }
    if(d2 != -1){
        cout << "4\n";
        cout << "1 " << pr[d2] + 1 << ' ' << d2 + 1 << " 1 " << n << '\n';
        return 0;
    }
    else{
        assert(dist[n - 1] == INF);
        comp[0] = INF;
        FOR(i,1,n-1){
            if(dist[i] == 1 && !comp[i]){
                ++crc;
                cnt = 0;
                wh.clear();
                d1(i);
                FORR(x,wh){
                    if(adj[x].size() - 1 < cnt - 1){
                        queue<int> qu;
                        qu.push(x);
                        int dist[n];
                        int pr[n];
                        pr[x] = -1;
                        memset(dist,127,n << 2);
                        dist[x] = 0;
                        int d2 = -1;
                        while(!qu.empty()){
                            int v = qu.front(); qu.pop();
                            FORR(i,adj[v]){
                                if(!i)
                                    continue;
                                if(dist[v] + 1 < dist[i]){
                                    pr[i] = v;
                                    dist[i] = dist[v] + 1;
                                    if(dist[i] == 2){
                                        d2 = i;
                                    }
                                    qu.push(i);
                                }
                            }
                        }
                        assert(d2 != -1);
                        cout << "5\n";
                        cout << "1 " << x + 1 << ' ' << pr[d2] + 1 << ' ' << d2 + 1 << ' ' << x + 1 << ' ' << n << '\n';
                        return 0;
                    }
                }
            }
        }
        cout << "-1\n";
    }
}