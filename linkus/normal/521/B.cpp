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
#define N 100005

vector<int> adj[N]; //jakie nizej
vector<int> adjr[N]; //jakie wyzej
int lfadj[N]; //ile wyzej z 1 degiem
int deg[N]; //ile nizej
set<int> cur;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    map<pi,int> wh;
    FOR(i,0,n){
        int x,y;
        sc(x,y);
        if(y == 0){
            ++deg[i];
        }
        pi lol;
        for(int xx = -1; xx <= 1; ++xx)
            for(int yy = -1; yy <= 1; ++yy){
                if(yy == 0) continue;
                lol = {x+xx,y+yy};
                if(wh.count(lol)){
                    if(yy == -1){
                        adj[i].pb(wh[lol]);
                        adjr[wh[lol]].pb(i);
                    }
                    else{
                        adjr[i].pb(wh[lol]);
                        adj[wh[lol]].pb(i);
                    }
                }
            }
        wh[mp(x,y)] = i;
    }
    FOR(i,0,n)
        deg[i] += adj[i].size();
    FOR(i,0,n){
        /* whatis(i) */
        /* whatis(deg[i]) */
        assert(deg[i]);
        if(deg[i] == 1){
            FORR(x,adj[i])
                ++lfadj[x];
        }
    }
    FOR(i,0,n){
        if(!lfadj[i])
            cur.insert(i);
    }
    ll ret = 0;
    ll mod = 1e9+9;
    ll pw[n];
    pw[0] = 1;
    FOR(i,1,n)
        pw[i] = pw[i-1]*n%mod;
    bool whm = 1;
    int lewl = n-1;
    bool wyw[n];
    memset(wyw,0,n);
    while(cur.size()){
        /* whatis(cur) */
        int ch = -1;
        if(whm)
            ch = *cur.rbegin();
        else
            ch = *cur.begin();
        cur.erase(ch);
        wyw[ch] = 1;
        /* whatis(ch) */
        ret += ch*pw[lewl--];
        ret %= mod;
        whm ^= 1;
        if(deg[ch] == 1){ //what if conneced to floor????
            FORR(x,adj[ch]){ //pozostale tem s :/
                if(wyw[x]) continue;
                if(--lfadj[x] == 0){
                    cur.insert(x);
                }
            }
        }
        FORR(i,adjr[ch]){
            if(wyw[i]) continue;
            --deg[i];
            assert(deg[i]); //juz wywalone??
            if(deg[i] == 1){
                FORR(x,adj[i]){ //pozostale tem s :/
                    if(wyw[x]) continue;
                    if(++lfadj[x] == 1){
                        cur.erase(x);
                    }
                }
            }
        }
    }
    cout << ret << '\n';
}