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

struct fns{
    int x1,x2,y1,y2;
    ll alicz,amian,blicz; //b has same mian as a, if it as a vertical line, is hold value of x instead
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int x1,x2,y1,y2;
    ll ans = 0;
    vector<fns> fn;
    FOR(i,0,n){
        sc(x1,y1,x2,y2);
        if(x1 > x2) swap(x1,x2), swap(y1,y2);
        /* whatis(i) */
        ans += abs(__gcd(y1-y2,x1-x2))+1;
        ll alicz = (y1-y2);
        ll amian = (x1-x2);
        if(amian < 0){
            amian *= -1;
            alicz *= -1;
        }
        ll blicz = (x2^x1?y2*amian-alicz*x2:x1);
        /* whatis(alicz) */
        /* whatis(amian) */
        /* whatis(blicz) */
        set<pair<int,int>> st;
        FOR(j,0,i){
            if(fn[j].amian == 0 && amian == 0) //because input asserts no segments on the same line
                continue;
            if(amian == 0){
                if(blicz < fn[j].x1 || blicz > fn[j].x2) continue;
                ll ylicz = fn[j].alicz*blicz+fn[j].blicz;
                if(ylicz%fn[j].amian) continue;
                ylicz /= fn[j].amian;
                if(ylicz < min(y1,y2) || ylicz > max(y1,y2)) continue;
                st.insert({blicz,ylicz});
            }
            else if(fn[j].amian == 0){
                if(fn[j].blicz < x1 || fn[j].blicz > x2) continue;
                ll ylicz = alicz*fn[j].blicz+blicz;
                if(ylicz%amian) continue;
                ylicz /= amian;
                if(ylicz < min(fn[j].y1,fn[j].y2) || ylicz > max(fn[j].y1,fn[j].y2)) continue;
                st.insert({fn[j].blicz,ylicz});
            }
            else{
                ll cmnmian = amian*fn[j].amian/__gcd(amian,fn[j].amian);
                /* whatis(cmnmian) */
                /* whatis(amian) */
                /* whatis(fn[j].amian) */
                ll xlicz = cmnmian/amian*blicz-cmnmian/fn[j].amian*fn[j].blicz;
                ll xmian = -1*(cmnmian/amian*alicz-cmnmian/fn[j].amian*fn[j].alicz);
                /* whatis(xlicz) */
                /* whatis(xmian) */
                if(!xmian) continue;
                if(xlicz%xmian) continue;
                xlicz /= xmian;
                ll ylicz = cmnmian/amian*alicz*xlicz+cmnmian/amian*blicz;
                if(ylicz%cmnmian) continue;
                ylicz /= cmnmian;
                /* whatis(xlicz) */
                /* whatis(ylicz) */
                /* whatis(x1) */
                /* whatis(x2) */
                /* whatis(y1) */
                /* whatis(y2) */
                /* whatis(fn[j].x1) */
                /* whatis(fn[j].x2) */
                /* whatis(fn[j].y1) */
                /* whatis(fn[j].y2) */
                if(xlicz < x1 || xlicz > x2 || xlicz < fn[j].x1 || xlicz > fn[j].x2 || ylicz < min(y1,y2) || ylicz < min(fn[j].y1,fn[j].y2) || ylicz > max(y1,y2) || ylicz > max(fn[j].y1,fn[j].y2)) continue;
                st.insert({xlicz,ylicz});
            }
        }
        fn.pb({x1,x2,y1,y2,alicz,amian,blicz});
        /* whatis(st) */
        ans -= st.size();
    }
    cout << ans << '\n';
}