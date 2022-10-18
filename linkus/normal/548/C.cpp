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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    ll h,a,x,y;
    ll h1,a1,x1,y1;
    ll h2,a2,x2,y2;
    sc(n);
    {
        sc(h,a,x,y);
        h1 = h;
        a1 = a;
        x1 = x;
        y1 = y;
        int t[n];
        memset(t,-1,sizeof t);
        int cr = 0;
        for(;;){
            if(h == a){
                break;
            }
            /* assert(h >= 0 && h < n); */
            if(t[h] == -1){
                t[h] = cr;
            }
            else{
                cr = -1;
                break;
            }
            ++cr;
            h = (x*h+y)%n;
        }
        if(cr == -1) REE(-1)
    }
    int nx[n]; //nx po nd1%nd2 dla dwjki
    {
        sc(h,a,x,y);
        h2 = h;
        a2 = a;
        x2 = x;
        y2 = y;
        int t[n];
        memset(t,-1,sizeof t);
        int cr = 0;
        for(;;){
            if(h == a){
                break;
            }
            /* assert(h >= 0 && h < n); */
            if(t[h] == -1){
                t[h] = cr;
            }
            else{
                cr = -1;
                break;
            }
            ++cr;
            h = (x*h+y)%n;
        }
        if(cr == -1) REE(-1)
    }
    ll res = 0;
    while(h1 != a1){
        h1 = (x1*h1+y1)%n;
        h2 = (x2*h2+y2)%n;
        /* whatis(h1) */
        /* whatis(h2) */
        ++res;
    }
    int w1 = 0, w2 = 0;
    FOR(xd,0,3000000){ // to get rid of weid edge cases
        if(h1 == a1 && h2 == a2) REE(res)
        ++res;
        h1 = (x1*h1+y1)%n;
        h2 = (x2*h2+y2)%n;
        if(h1 == a1 && h2 == a2) REE(res)
        if(h1 == a1) ++w1;
        if(h2 == a2) ++w2;
        if(xd > 2000500 && (h1 == a1 || w1 < 2)) break;
    }
    if(w1 < 2 || w2 < 2) REE(-1)
    vi vec;
    ll nh = h1;
    for(;;){
        if(vec.size() && nh == vec[0]){
            break;
        }
        vec.pb(nh);
        nh = (x1*nh+y1)%n;
    }
    //vec is cycle
    int nd1 = vec.size();
    vec.clear();
    nh = h2;
    for(;;){
        if(vec.size() && nh == vec[0]){
            break;
        }
        vec.pb(nh);
        nh = (x2*nh+y2)%n;
    }
    //vec is cycle
    int nd2 = vec.size();
    FOR(i,0,vec.size()){
        nx[vec[i]] = vec[(i+nd1)%nd2];
    }
    FOR(xd,0,2000000){ //no moduloo yay
        if(h2 == a2) REE(res)
        //h1 same always at a1
        res += nd1;
        /* if(!(h2 >= 0 && h2 < n)) REE("BAD") */
        h2 = nx[h2];
    }
    REE(-1)
}