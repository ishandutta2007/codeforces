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

vector<int> adj[N], adjrev[N];
bool vis[N];
int comp[N];
bool assign[N];
vector<int> order;
int it;

void d1(int v){
    vis[v] = 1;
    for(auto &i: adj[v]){
        if(!vis[i])
            d1(i);
    }
    order.push_back(v);
}

void d2(int v){
    comp[v] = it;
    for(auto &i: adjrev[v]){
        if(comp[i] == -1)
            d2(i);
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //mt19937_64 for 64bit
inline int rand(int l, int r){
    return uniform_int_distribution<int>(l,r)(rng);
}

int main(){
    // make sure than 2 * (x) is in brackets
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int pres = -1;
        int imp,nimp;
        FORE(i,1,n){
            cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << endl;
            int rt;
            cin >> rt;
            if(pres != -1 && pres != rt){
                if(rt == 1)
                    imp = i - 1, nimp = i + 2;
                else
                    nimp = i - 1, imp = i + 2;
                break;
            }
            pres = rt;
        }
        vi wh{imp};
        FORE(i,1,n){
            if(i == imp || i == nimp)
                continue;
            cout << "? " << imp << ' ' << nimp << ' ' << i << endl;
            int rt;
            cin >> rt;
            if(rt == 0)
                wh.push_back(i);
        }
        /* int m = 2 * (n + 1); */
        /* FOR(i,0,m){ */
        /*     adj[i].clear(); */
        /*     adjrev[i].clear(); */
        /*     vis[i] = 0; */
        /*     comp[i] = -1; */
        /* } */
        /* order.clear(); */
        /* it = 0; */
        /* // (x or y) -> (~x -> y) and (~y -> x) */
        /* /1* for(int i = 0; i < n; ++i){ *1/ */
        /* /1*     for(auto &x: adj[i]){ *1/ */
        /* /1*         adjrev[x].push_back(i); *1/ */
        /* /1*         // Zwolnienie pamici jeli trzeba *1/ */
        /* /1*         /2* adj[i].clear(); *2/ *1/ */
        /* /1*         /2* adj[i].shrink_to_fit(); *2/ *1/ */
        /* /1*     } *1/ */
        /* /1* } *1/ */
        /* srand(time(0)); */
        /* FOR(i,0,2*n){ */
        /*     int a,b,c; */
        /*     while(a = rand(1,n), b = rand(1,n), c = rand(1,n), a == b || b == c || a == c); */
        /*     cout << "? " << a << ' ' << b << ' ' << c << endl; */
        /*     int ret; */
        /*     cin >> ret; */
        /*     if(ret == 1){ */
        /*         adj[2*a].push_back(2*b+1); */
        /*         adj[2*a].push_back(2*c+1); */
        /*         adj[2*b].push_back(2*a+1); */
        /*         adj[2*b].push_back(2*c+1); */
        /*         adj[2*c].push_back(2*b+1); */
        /*         adj[2*c].push_back(2*a+1); */
        /*     } */
        /*     else{ */
        /*         adj[2*a+1].push_back(2*b); */
        /*         adj[2*a+1].push_back(2*c); */
        /*         adj[2*b+1].push_back(2*a); */
        /*         adj[2*b+1].push_back(2*c); */
        /*         adj[2*c+1].push_back(2*b); */
        /*         adj[2*c+1].push_back(2*a); */
        /*     } */
        /* } */
        /* for(int i = 0; i < m; ++i){ */
        /*     for(auto &x: adj[i]){ */
        /*         adjrev[x].push_back(i); */
        /*         // Zwolnienie pamici jeli trzeba */
        /*         /1* adj[i].clear(); *1/ */
        /*         /1* adj[i].shrink_to_fit(); *1/ */
        /*     } */
        /* } */
        /* for(int i = 0; i < m; ++i){ */
        /*     if(!vis[i]) */
        /*         d1(i); */
        /* } */
        /* memset(comp,-1,sizeof comp); */
        /* for(int i = 0; i < m; ++i){ */
        /*     // bruh xdd. */
        /*     /1* int v = order[n - i - 1]; *1/ */
        /*     int v = order[m - i - 1]; // highlight this on concepts. */
        /*     if(comp[v] == -1){ */
        /*         d2(v); */
        /*         ++it; */
        /*     } */
        /* } */
        /* bool kk = 1; */
        /* /1* for(int i = 0; i < m; i += 2){ *1/ */
        /* vi wh; */
        /* for(int i = 2; i < m; i += 2){ */
        /*     //i -> x */
        /*     //i+1 -> ~x */
        /*     if(comp[i] == comp[i + 1]){ */
        /*         assert(0); */
        /*         /1* kk = 0; *1/ */
        /*         /1* break; *1/ */
        /*     } */
        /*     // component x przed componentem ~x w topo <-> x true */
        /*     assign[i / 2] = comp[i] > comp[i + 1]; */
        /*     if(assign[i / 2] == 1) */
        /*         wh.push_back(i / 2); */
        /*     // XXX assign == 0 -> 2 * i + 1, nie 2 * i z tym. Might wanna flip this (2nd trening druynowy 2021). */
        /*     /1* assign[i / 2] = comp[i] < comp[i + 1]; *1/ */
        /*     // Jak mam wybr jednego z dwch w obrbie jednego iksa, i chc wymusi */
        /*     // wybr jednego, bo np. inny jest pusty, albo jest <= 2 czego, dodaj */
        /*     // i * 2 + 1, i * 2. */
        /* } */
        cout << "! " << wh.size();
        FORR(i,wh)
            cout << ' ' << i;
        cout << endl;
    /* } */
    }
}