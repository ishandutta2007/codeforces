#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
//typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

ll hsh[300000];
int n,m;
bool g;
/* const ll A = 1000000007, B = 461168601893; */
const ll A = 1000000007, B = 4611686018427387903;
/* const char chr[] = "abc"; */
const string chr = "abc";
string s;
int sz;

long long mul(ll a, ll b, ll m){
    ll q = (long double)a * (long double)b / (long double)m;
    ll p = a*b-q*m;
    return (p)%m;
}

/* ll mul(ll a, ll b, ll m){ */
/*     if(!b) */
/*         return 0; */
/*     /1* whatis(b) *1/ */
/*     ll res = mul(a, b>>1, m); */
/*     res += res; */
/*     res %= m; */
/*     return (b&1)?(res+a)%m:res; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m);
    ll *hs = hsh;
    int tmn = n;
    ll p[600001];
    p[0] = 1;
    for(int i = 1; i <= 600000; ++i){
        p[i] = mul(p[i-1],A,B);
    }
    while(tmn--){
        getstr(s);
        ll cur = 0;
        FOR(i,0,s.size()){
            cur = (cur+mul(p[i],(s[i]-96),B))%B;
            cur = (cur+B)%B;
        }
        *hs++ = cur;
        /* whatis(cur) */
    }
    sort(hsh,hsh+n);
    while(m--){
        getstr(s);
        sz = s.size();
        g = 0;
        ll cur = 0;
        FOR(i,0,sz){
            cur = (cur+mul(p[i],(s[i]-96),B))%B;
            cur = (cur+B)%B;
        }
        FOR(i,0,sz){
            FORR(c,chr){
                if(c == s[i]) continue;
                ll newc = (cur - mul(p[i],(s[i]-96),B) + mul(p[i],(c-96),B))%B;
                newc = (newc+B)%B;
                g |= binary_search(hsh,hs,newc);
            }
        }
        /* rec(0,1,0); */
        cout << (g?"YES\n":"NO\n");
    }
                return 0;
}