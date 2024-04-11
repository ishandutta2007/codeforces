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
// 1 << 19 if segtree where merges matter.

const int N = 2e5+4; //Sometimes must be scaled into a power of 2!!!!!!!!!!!!!

// function, base val
template<int op(int, int), int baseval>
class seg{
public:
    int t[N*2]; // XXX jeeli wiele testw to sikwadraci z t takim.
    int n;

    int query(int l, int r){
        int res = baseval;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1)
                res = op(res,t[l++]);
                //res += t[l++];
            if(r&1)
                res = op(res,t[--r]);
                //res += t[--r];
        }
        return res;
    }

    void modify(int p, int val){
        p += n;
        for(t[p] = min(t[p], val); p > 1; p>>=1)
            t[p>>1] = op(t[p] , t[p^1]);
    }

    template<typename T>
    seg(T a, int n) : n(n) {
        for(int i = 2*n-1; i >= n; --i)
            t[i] = a[i - n];
        for(int i = n - 1; i > 0; --i)
            t[i] = op(t[i<<1] , t[i<<1|1]);
    }
};

int fun(int a, int b){
    return min(a,b);
    /* return min(a,b); */
    /* return a + b; */
}


vector<int> vec(2e5 + 1, INF);
seg<fun, INF> t(vec, vec.size());
set<int> st;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n >> q;
    FOR(i,0,n){
        st.insert(i);
    }
    while(q--){
        int typ;
        cin >> typ;
        if(typ == 0){
            int l, r, wh;
            cin >> l >> r >> wh;
            --l,--r;
            if(wh == 0){
                auto it = st.lower_bound(l);
                while(it != st.end() && *it <= r){
                    ++it;
                    st.erase(prev(it));
                }
            }
            else{
                t.modify(l,r);
            }
        }
        else{
            int wh;
            cin >> wh;
            --wh;
            auto it = st.lower_bound(wh);
            if(it == st.end() || *it != wh){
                cout << "NO\n";
            }
            else{
                /* whatis(st) */
                /* int r = it == st.end() ? n - 1 : *it - 1; */ // bruhhh
                int r = it == --st.end() ? n - 1 : *next(it) - 1;
                int l = it == st.begin() ? 0 : *prev(it) + 1;
                /* int ret = t.query(l, r + 1); */
                int ret = t.query(l, wh + 1); // musi zawiera mnie.
                /* whatis(l) */
                /* whatis(r) */
                /* whatis(ret) */
                if(ret <= r){
                    cout << "YES\n";
                }
                else{
                    cout << "N/A\n";
                }
            }
        }
    }
}