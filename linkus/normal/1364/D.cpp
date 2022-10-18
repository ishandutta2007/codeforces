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

int n,m,k;
vi adj[N];
bool vis[N];
vi ret;

vi qu;
void d1(int v, int p){
    vis[v] = 1;
    qu.push_back(v);
    FORR(i,adj[v]){
        if(i >= k) continue;
        if(i == p) continue;
        if(vis[i]){
            /* whatis("cyk") */
            ret = {i};
            while(qu.back() != i){
                ret.pb(qu.back());
                qu.pop_back();
            }
            return;
        }
        d1(i, v);
        if(ret.size()) return;
    }
    qu.pop_back();
}

int kol[N];
vi cr;
void d2(int v, int p){
    cr.pb(v);
    FORR(i,adj[v]){
        if(i >= k) continue;
        /* if(i == p) continue; */
        if(kol[i] == -1){
            kol[i] = kol[v] ^ 1;
            d2(i,v);
        }
        else{
            assert(kol[i] == (kol[v] ^ 1));
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m,k);
    int f,s;
    while(m--){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    /* d1(0, -1); // how did this pass 138 tests lol */
    // nevermind, connected
    FOR(i,0,k){
        if(ret.size()) break;
        if(!vis[i]){
            qu.clear();
            d1(i,-1);
        }
    }
    if(ret.size()){
        cout << "2\n" << ret.size() << '\n';
        FORR(i,ret)
            cout << i+1 << ' ';
        cout << '\n';
    }
    else{
        cout << "1\n";
        memset(kol,-1,n<<2);
        vi res;
        FOR(i,0,k){
            if(kol[i] == -1){
                kol[i] = 0;
                d2(i,-1);
                int c[2] = {};
                FORR(i,cr){
                    ++c[kol[i]];
                }
                FORR(i,cr){
                    if(kol[i] == (c[0] < c[1]))
                        res.pb(i);
                }
                cr.clear();
            }
        }
        /* vi ord(k); */
        /* iota(all(ord),0); */
        /* sort(all(ord),[&](int f, int s){return ng[f].size() < ng[s].size();}); */
        /* FORR(i,ord){ */
        /*     bool kk = 1; */
        /*     FORR(x,ng[i]){ */
        /*         if(inc[x]){ */
        /*             kk = 0; */
        /*             break; */
        /*         } */
        /*     } */
        /*     if(kk){ */
        /*         res.pb(i); */
        /*         inc[i] = 1; */
        /*     } */
        /* } */
        while(res.size() > k/2+k%2) res.pop_back();
        assert(res.size() == k/2+k%2);
        FORR(i,res){
            cout << i+1 << ' ';
        }
        cout << '\n';
    }
}