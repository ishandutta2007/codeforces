#pragma GCC optimize("O3")
#pragma GCC target("sse4")
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
/* #define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size) */
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
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

inline void chkmax(int &a, const int &b){
    if(b > a)
        a = b;
}
inline void chkmin(int &a, const int &b){
    if(b < a)
        a = b;
}

#define INF (1 << 30)

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,l,r,k,t;
    int posa[100001];
    int posb[100001];
    /* fill_n(posa,100000,INF); */
    /* fill_n(posb,100000,INF); */
    /* cout << bitset<32>((posa[0] >> 30) - 2); */
    memset(posa,127,sizeof posa);
    memset(posb,127,sizeof posb);
    sc(n);
    while(n--){
        sc(t,l,r);
        --r;
        if(t == 1){
            sc(k);
            if(k > 0){
                for(int i = l; i <= r; ++i){
                    chkmin(posa[i],k);
                }
                /* while(l <= r){ */
                    /* posa[l] = min(posa[l],k); */
                    /* chkmin(posa[l],k); */
                    /* ++l; */
                /* } */
            }
            else{
                k = -k;
                for(int i = l; i <= r; ++i){
                    chkmin(posb[i],k);
                }
                /* while(l <= r){ */
                    /* posb[l] = min(posb[l],k); */
                    /* chkmin(posb[l],k); */
                    /* ++l; */
                /* } */
            }
        }
        else{
            ll ans = 0;
            for(int i = l; i <= r; ++i){
                    ans += (posa[i]+posb[i]) & (((posa[i] >> 30) | (posb[i] >> 30)) - 1);
                /* if(posa[i] < INF && posb[i] < INF) */
                /*     ans += posa[i]+posb[i]; */
            }
            /* while(l <= r){ */
            /*     if(posa[l] < INF && posb[l] < INF) */
            /*         ans += posa[l]+posb[l]; */
            /*     ++l; */
            /* } */
            cout << ans << '\n';
        }
    }
}