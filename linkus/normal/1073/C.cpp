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
#define N 1000001

int n,x,y,dlr,dud,dfx,dfy;
string s;

inline bool ok(int mid){
    int cnt[128];
    memset(cnt,0,128<<2);
    for(int i = 0; i < mid; ++i){
        ++cnt[(int)s[i]];
    }
    /* whatis(mid) */
        for(int xdd = 0; xdd < 1; ++xdd){
            int l = cnt['L'];
            int r = cnt['R'];
            int u = cnt['U'];
            int d = cnt['D'];
            int dl = dlr;
            int du = dud;
            dl += l;
            dl -= r;
            du += d;
            du -= u;
            int ll = abs(x-dl)+abs(y-du);
            if(mid < ll || mid%2 != ll%2) break;
            return 1;
        }
    for(int i = mid; i < n; ++i){
        --cnt[(int)s[i-mid]];
        ++cnt[(int)s[i]];
        for(int xdd = 0; xdd < 1; ++xdd){
            int l = cnt['L'];
            int r = cnt['R'];
            int u = cnt['U'];
            int d = cnt['D'];
            int dl = dlr;
            int du = dud;
            dl += l;
            dl -= r;
            du += d;
            du -= u;
            int ll = abs(x-dl)+abs(y-du);
            if(mid < ll || mid%2 != ll%2) break;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    getstr(s);
    sc(x,y);
    int l = abs(x)+abs(y);
    if(n < l || n%2 != l%2) REE(-1)
    dlr = 0, dud = 0;
    FORR(i,s){
        if(i == 'L') --dlr;
        if(i == 'R') ++dlr;
        if(i == 'D') --dud;
        if(i == 'U') ++dud;
    }
    if(dlr == x && dud == y) REE(0)
    dfx = x-dlr, dfy = y-dud;
    /* whatis(dfx) */
    /* whatis(dfy) */
    int low = 1, high = n, mid, ans = -1; //low and high inclusive
    while(low <= high){
        mid = low+(high-low)/2;
        if(ok(mid)){
            ans = mid;
            high = mid-1; //Jak najmniejsza
            //low = mid+1; //Jak najwiksza
        }
        else{
            low = mid+1; //Jak najmniejsza
            //high = mid-1; //Jak najwiksza
        }
    }
    cout << ans << '\n';
}