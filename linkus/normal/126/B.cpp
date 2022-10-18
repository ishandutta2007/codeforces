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

/* inline ll mul(ll a, ll b, ll mod){ */
/*     ll p = (long double)a * (long double)b / (long double)mod; */
/*     ll q = a*b/mod*p; */
/*     return (q+5*mod)%mod; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    getstr(s);
    /* const ll A = 1000000007, B = (1ll << 62ll)-1; */
    const ull A = 1000000007;
    ull p[s.size()+1];
    ull h[s.size()];
    p[0] = 1;
    FORE(i,1,(int)s.size()){
        p[i] = p[i-1]*A;
        /* p[i] = mul(p[i-1],A,B); */
    }
    h[0] = s[0];
    FOR(i,1,(int)s.size()){
        /* h[i] = s[i] + mul(h[i-1],A,B); */
        h[i] = s[i] + h[i-1]*A;
    }
    vector<int> lens;
    FORE(i,1,(int)s.size()){
        /* whatis(i) */
        /* whatis(h[i-1]) */
        /* whatis((h[s.size()-1] - mul(h[s.size()-1-i],p[i],B))) */
        /* if(h[i-1] == (h[s.size()-1] - mul(h[s.size()-1-i],p[i],B) % B + B) % B) */
        if(h[i-1] == (h[s.size()-1] - h[s.size()-1-i]*p[i]))
            lens.pb(i);
    }
    /* whatis(h[2]) */
    /* whatis(h[8]-h[5]*p[3]) */
    /* whatis(lens) */
    int low = 0, high = lens.size()-1, ans = 0;
    while(low <= high){
        int md = low+(high-low)/2;
        int mid = lens[md];
        ull hsh = h[mid-1];
        /* if(hsh != (h[s.size()-1] - mul(h[s.size()-1-mid],p[mid],B) + B) % B){ */
            /* high = md-1; */
            /* continue; */
        /* } */
        for(int i = 1, till = s.size()-mid; i < till; ++i){
            /* if(hsh == (h[i] - mul(h[i-mid],p[mid],B) % B + B) % B){ */
            if(hsh == (h[i+mid-1] - h[i-1]*p[mid])){
                low = md+1;
                /* whatis(mid) */
                ans = mid;
                goto nxt;
            }
        }
        high = md-1;
        nxt:;
    }
    cout << (ans?s.substr(0,ans):"Just a legend\n");
}