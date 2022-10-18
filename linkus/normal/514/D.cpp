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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    sc(n,m,k);
    int d[n][m];
    FORR(i,d)
        FORR(x,i)
            sc(x);
    int best = 0;
    int ans[m];
    memset(ans,0,m << 2);
    map<int,int> mp[m];
    int cnt = 0, il = 1;
    FOR(i,0,m){
        il = 1;
        ++mp[i][d[0][i]];
        cnt += mp[i].rbegin()->e1;
    }
    if(cnt <= k){
        best = il;
        FOR(x,0,m){
            ans[x] = mp[x].rbegin()->e1;
        }
    }
    int f = 0;
    for(int i = 1; i < n; ++i){
        ++il;
        int cnt = 0;
        FOR(x,0,m){
            ++mp[x][d[i][x]];
            cnt += mp[x].rbegin()->e1;
        }
        while(cnt > k){
            if(f == i){
                FORR(i,mp)
                    i.clear();
                il = 0;
                ++f;
                break;
            }
            cnt = 0;
            FOR(x,0,m){
                auto it = mp[x].find(d[f][x]);
                if(!--it->e2){
                    mp[x].erase(it);
                }
                cnt += mp[x].rbegin()->e1;
            }
            ++f;
            --il;
        }
        if(il > best){
            /* whatis(cnt) */
            /* whatis(il) */
            best = il;
            FOR(x,0,m){
                ans[x] = mp[x].rbegin()->e1;
            }
        }
    }
    FORR(i,ans)
        cout << i << ' ';
    cout << '\n';
}