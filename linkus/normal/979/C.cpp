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
#define whatis(x) cerr << #x << " is " << x << endl;
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
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define N 300001
vector<int> adj[N];
ll s1,s2,a,af,ab;
ll n,f,b;

bool d2(int v, int p){
    if(v == f){
        if(p == b) ab = v;
        return true;
    }
    FORR(i,adj[v]){
        if(i == p) continue;
        if(d2(i,v)){
            if(p == b) ab = v;
            return true;
        }
    }
    return false;
}

bool d1(int v, int p){
    if(v == b){
        if(p == f) af = v;
        return true;
    }
    FORR(i,adj[v]){
        if(i == p) continue;
        if(d1(i,v)){
            if(p == f) af = v;
            return true;
        }
    }
    return false;
}

void xd1(int v, int p){
    ++s1;
    FORR(i,adj[v]){
        if(i == af) continue;
        if(i == p) continue;
        xd1(i,v);
    }
}

void xd2(int v, int p){
    ++s2;
    FORR(i,adj[v]){
        if(i == ab) continue;
        if(i == p) continue;
        xd2(i,v);
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,f,b);
    --f,--b;
    int fir,sec;
    FOR(i,1,n){
        sc(fir,sec);
        --fir,--sec;
        adj[fir].push_back(sec);
        adj[sec].push_back(fir);
    }
    a = (ll)n*(n-1);
    d1(f,-1);
    /* whatis(af) */
    d2(b,-1);
    /* whatis(ab) */
    xd1(f,-1);
    xd2(b,-1);
    a -= s1*s2;
    cout << a << '\n';
}