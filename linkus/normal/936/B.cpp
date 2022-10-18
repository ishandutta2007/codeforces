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
#define N 100001

vi adj[N];
int dfs_num[N], dfs_min[N];
int wh[N];
vector<vector<int>> scc;
stack<int> st;
int it;

//Order of SCCs is a reverse topological sort of SCC Condensation-DAG
bool kk = 0;
void tarjan(int cur){
    dfs_num[cur] = dfs_min[cur] = ++it;
    st.push(cur);
    for(auto &i: adj[cur]){
        if(!dfs_num[i])
            tarjan(i);
        dfs_min[cur] = min(dfs_min[cur], dfs_min[i]);
    }
    if(dfs_num[cur] == dfs_min[cur]){
        scc.push_back({});
        int cr;
        do{
            //elements of the scc
            cr = st.top(); st.pop();
            dfs_min[cr] = 0x7f7f7f7f;
            wh[cr] = scc.size()-1;
            scc.back().push_back(cr);
        }while(cr != cur);
        if(scc.back().size() > 1) kk |= 1;
        else scc.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    int mm,v;
    FOR(i,0,n){
        sc(mm);
        while(mm--){
            sc(v);
            adj[i].pb(v-1);
        }
    }
    int s;
    sc(s); --s;
    int p[n+1][2]; //0 -> petya move 1 -> npetya move
    //lisc == 1 -> win
    memset(p,-1,sizeof p);
    p[s][0] = n;
    queue<pi> qu;
    qu.push({s,0});
    int wh = -1;
    while(!qu.empty()){
        int v = qu.front().e1, odd = qu.front().e2; qu.pop();
        int nodd = odd^1;
        FORR(i,adj[v]){
            if(p[i][nodd] == -1){
                p[i][nodd] = v;
                qu.push({i,nodd});
                if(adj[i].empty() && nodd == 1){
                    wh = i;
                    break;
                }
            }
        }
    }
    if(~wh){
        cout << "Win\n";
        vi xd;
        int v = wh;
        int odd = 1;
        while(~v){
            xd.pb(v);
            v = p[v][odd];
            odd ^= 1;
        }
        xd.pop_back();
        reverse(all(xd));
        FORR(i,xd)
            cout << i+1 << ' ';
        return 0;
    }
    FOR(i,0,n){
        if((~p[i][0] || ~p[i][1]) && !dfs_num[i]){
            tarjan(i);
        }
    }
    cout << (kk?"Draw\n":"Lose\n");
}