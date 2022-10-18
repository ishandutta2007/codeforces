#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = rbegin(arr)+(plus); x != rend(arr); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
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
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
inline ll mod(ll i, ll n) { return (i % n + n) % n; }

long long mul( long long a, long long b, long long m ) {
    long long q = (long long)((long double)a * (long double)b / (long double)m);
    long long r = a * b - q * m;
    return (r + 5 * m) % m;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* const ll A = 214765741, B = 100000007; */
    /* const ll A = 2147645741, B = 3037000493; */
    /* const ll A = 2147645741, B = 99999999977; */
    const ll A = 2147645741, B = (1ll << 60)-1;
    /* whatis(B) */
    int n;
    sc(n);
    string s[n];
    ll p[10];
    p[0] = 1;
    FOR(i,1,10){
        /* p[i] = mod(p[i-1]*A,B); */
        p[i] = mul(p[i-1],A,B);
        /* whatis(p[i]) */
    }
    ll h[n][9];
    map<ll,int> was;
    ll ch;
    FOR(i,0,n){
        set<ll> wasown;
        getstr(s[i]);
        h[i][0] = s[i][0];
        FOR(x,1,s[i].size()){
            /* h[i][x] = mod(h[i][x-1]*A+s[i][x],B); */
            h[i][x] = mod(mul(h[i][x-1],A,B)+s[i][x],B);
        }
        FOR(sz,1,10){
            int till = 10-sz;
            ++was[h[i][sz-1]];
            wasown.insert(h[i][sz-1]);
            FOR(x,1,till){
                /* if(wasown.count(ch = mod(h[i][x+sz-1] - h[i][x-1]*p[sz],B))) continue; */
                if(wasown.count(ch = mod(h[i][x+sz-1] - mul(h[i][x-1],p[sz],B),B))) continue;
                wasown.insert(ch);
                ++was[ch];
            }
        }
    }
    /* whatis(was['1']); */
    /* whatis(mod(h[1][1]-h[1][0]*p[1],B)) */
    /* whatis(mod(h[1][2]-h[1][1]*p[1],B)) */
    FOR(i,0,n){
        FOR(sz,1,10){
            if(was[h[i][sz-1]] == 1){
                cout << s[i].substr(0,sz) << '\n';
                goto g;
            }
            int till = 10-sz;
            FOR(x,1,till){
                /* if(was[mod(h[i][x+sz-1] - h[i][x-1]*p[sz],B)] == 1){ */
                if(was[mod(h[i][x+sz-1] - mul(h[i][x-1],p[sz],B),B)] == 1){
                    /* whatis(x) */
                    cout << s[i].substr(x,sz) << '\n';
                    goto g;
                }
            }
        }
        g:;
    }
}