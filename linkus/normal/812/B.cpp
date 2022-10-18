#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x < end(arr); ++x)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
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
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    bool arr[n][m+2];
    FORR(i,arr){
        FORR(x,i){
            char c;
            getch(c);
            x = c == '1';
        }
    }
    int dp[n][2];
    memset(dp,63, sizeof dp);
    dp[n-1][0] = 0;
    dp[n-1][1] = m+1;
    int cur = n - 1;
    int lastp = 0;
    for(int i = 0;i < n;++i){
        bool g = 1;
        FORR(x,arr[i]){
            if(x)
                g = 0;
        }
        if(g)
            ++lastp;
        else
            break;
    }
    if(lastp == n) --lastp;
    while(cur > lastp){
        int lastl = 0;
        int lastr = m+1;
        FOR(i,0,m+2){
            if(arr[cur][i]){
                lastr = i;
                break;
            }
        }
        for(int i = m+1;i > 0; --i){
            if(arr[cur][i]){
                lastl = i;
                break;
            }
        }
        dp[cur-1][0] = min(dp[cur-1][0], dp[cur][1]+m+2);
        dp[cur-1][0] = min(dp[cur-1][0], dp[cur][0]+lastl*2+1);
        dp[cur-1][1] = min(dp[cur-1][1], dp[cur][0]+m+2);
        dp[cur-1][1] = min(dp[cur-1][1], dp[cur][1]+(m+1-lastr)*2+1);
        --cur;
    }
    /* FOR(i,0,n) */
    /*     cout << dp[i][0] << ' ' <<  dp[i][1] << '\n'; */
    int pos = -1;
    FOR(i,0,m+2){
        if(arr[lastp][i]){
            pos = i;
            dp[lastp][1] += m+1-pos;
            break;
        }
    }
    for(int i = m+1;i > 0; --i){
        if(arr[lastp][i]){
            pos = i;
            dp[lastp][0] += pos;
            break;
        }
    }
    int ans = min(dp[lastp][0], dp[lastp][1]);
    /* whatis(l); */
    cout << ans << '\n';
    /* int cur = n - 1; */
    /* int ans = 0; */
    /* bool right = 0; */
    /* while(cur > 0){ */
    /*     int pos = -1; */
    /*     if(right){ */
    /*         FOR(i,0,m+2){ */
    /*             if(arr[cur][i]){ */
    /*                 pos = i; */
    /*                 break; */
    /*             } */
    /*         } */
    /*     } */
    /*     else{ */
    /*         for(int i = m+1;i > 0; --i){ */
    /*             if(arr[cur][i]){ */
    /*                 pos = i; */
    /*                 break; */
    /*             } */
    /*         } */
    /*     } */
    /*     if(pos == -1){ */
    /*         ++ans; */
    /*         --cur; */
    /*         continue; */
    /*     } */
    /*     int distl = 0, distr = 0; */
    /*     FOR(i,0,m+2){ */
    /*         if(arr[cur-1][i]){ */
    /*             distl = i; */
    /*             break; */
    /*         } */
    /*     } */
    /*     for(int i = m+1;i > 0; --i){ */
    /*         if(arr[cur-1][i]){ */
    /*             distr = m+1-i; */
    /*             break; */
    /*         } */
    /*     } */
    /*     /1* whatis(pos) *1/ */
    /*     distl += pos+1, distr += m+1-pos+1; */
    /*     whatis(distl) */
    /*     whatis(distr) */
    /*     if(right == 0){ */
    /*         if(distl < distr){ */
    /*             right = 0, ans += pos * 2 + 1; */
    /*         } */
    /*         else{ */
    /*             right = 1, ans += m+2; */
    /*         } */
    /*     } */
    /*     else{ */
    /*         if(distl < distr){ */
    /*             right = 0, ans += m+2; */
    /*         } */
    /*         else{ */
    /*             right = 1, ans += (m+1-pos) * 2 + 1; */
    /*         } */
    /*     } */
    /*     --cur; */
    /*     /1* whatis(distl) *1/ */
    /*     /1* whatis(distr) *1/ */
    /*     /1* cout << ans << ' ' << right << '\n'; *1/ */
    /* } */
    /* /1* int l = 4; *1/ */
    /* /1* whatis(l); *1/ */
    /* int pos = -1; */
    /* if(right){ */
    /*     FOR(i,0,m+2){ */
    /*         if(arr[0][i]){ */
    /*             pos = i; */
    /*             break; */
    /*         } */
    /*     } */
    /* } */
    /* else{ */
    /*     for(int i = m+1;i > 0; --i){ */
    /*         if(arr[0][i]){ */
    /*             pos = i; */
    /*             break; */
    /*         } */
    /*     } */
    /* } */
    /* /1* whatis(l); *1/ */
    /* if(pos != -1){ */
    /*     ans += right?m+1-pos:pos; */
    /* } */
    /* for(int i = 0;i < n-1;++i){ */
    /*     bool g = 1; */
    /*     FORR(x,arr[i]){ */
    /*         if(x) */
    /*             g = 0; */
    /*     } */
    /*     if(g) */
    /*         --ans; */
    /*     else */
    /*         break; */
    /* } */
    /* /1* whatis(l); *1/ */
    /* cout << ans << '\n'; */
}