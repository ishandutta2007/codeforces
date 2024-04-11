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

int il[N];
int sz;
vi comps[500][500];
bool blck[500][500];

int n,k;
int wh;
int csz[N];
void d1(int i, int x){
    comps[i][x].pb(wh);
    if(blck[i][x]){
        return;
    }
    ++csz[wh];
    int xx[] = {0,0,1,-1};
    int yy[] = {1,-1,0,0};
    FOR(m,0,4){
        int j = i+xx[m];
        int c = x+yy[m];
        if(j >= 0 && c >= 0 && j < n && c < n){
            if(comps[j][c].empty() || comps[j][c].back() != wh)
                d1(j,c);
        }
    }
}

void add(int i, int x){
    sz += blck[i][x];
    FORR(j,comps[i][x]){
        if(++il[j] == 1){
            sz += csz[j];
        }
    }
}

void rem(int i, int x){
    sz -= blck[i][x];
    FORR(j,comps[i][x]){
        if(--il[j] == 0){
            sz -= csz[j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,k);
    string s[n];
    FOR(i,0,n){
        getstr(s[i]);
        FOR(x,0,n){
            if(s[i][x] == 'X') blck[i][x] = 1;
        }
    }
    FOR(i,0,n){
        FOR(x,0,n){
            if(blck[i][x]) continue;
            if(comps[i][x].empty()){
                ++wh;
                /* whatis(i) */
                /* whatis(x) */
                d1(i,x);
            }
        }
    }
    FOR(i,0,k){
        FOR(x,0,k){
            add(i,x);
        }
    }
    int ans = sz;
    bool left = 1;
    int up = 0, low = 0+k-1;
    while(low < n){
        if(left){
            int xl = 0, xr = k-1;
            while(xr+1 < n){
                ++xr;
                for(int i = up; i <= low; ++i){
                    add(i,xr);
                    rem(i,xl);
                }
                ++xl;
                ans = max(ans,sz);
            }
            if(low+1 ==n) break;
            ++low;
            for(int x = xl; x <= xr; ++x){
                rem(up,x);
                add(low,x);
            }
                ans = max(ans,sz);
            ++up;
        }
        else{
            int xl = n-k, xr = n-1;
            while(xl > 0){
                --xl;
                for(int i = up; i <= low; ++i){
                    add(i,xl);
                    rem(i,xr);
                }
                --xr;
                ans = max(ans,sz);
            }
            if(low+1 ==n) break;
            ++low;
            for(int x = xl; x <= xr; ++x){
                rem(up,x);
                add(low,x);
            }
                ans = max(ans,sz);
            ++up;
        }
        left ^= 1;
    }
    cout << ans << '\n';
}