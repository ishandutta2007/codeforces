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
#define N 1000000007

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    string s[n];
    int rog[n][m];
    int col[n][m];
    memset(rog,0,sizeof rog);
    memset(col,0,sizeof rog);
    FORR(i,s)
        getstr(i);
        /* cin >> i; */
    FOR(i,0,n){
        rog[i][m-1] = (s[i][m-1] == '*');
        for(int x = m-2; x >= 0; --x){
            /* whatis(i) */
            /* whatis(x) */
            rog[i][x] = (s[i][x] == '*');
            if(rog[i][x])
                rog[i][x] += rog[i][x+1];
            /* whatis(rog[i][x]) */
        }
    }
    FOR(i,0,m){
        col[n-1][i] = (s[n-1][i] == '*');
        for(int x = n-2; x >= 0; --x){
            col[x][i] = (s[x][i] == '*');
            if(col[x][i])
                col[x][i] += col[x+1][i];
        }
    }
    bool xd[n][m];
    bool xd2[m][n];
    FOR(i,0,n){
        FOR(x,0,m){
            xd2[x][i] = xd[i][x] = s[i][x] == '*';
        }
    }
    vector<array<int,3>> vec;
    FOR(i,0,n){
        FOR(x,0,m){
            int low = 0,high = min(x,m-x-1),mid,ans=0;
            while(low <= high){
                mid = low+(high-low)/2;
                /* if(i == 2 && x == 4){ */
                    /* whatis(low) */
                    /* whatis(high) */
                    /* whatis(mid) */
                    /* whatis(rog[i][x-mid]) */
                /* } */
                if(rog[i][x-mid] > mid*2){
                    low = mid+1;
                    ans = mid;
                }
                else{
                    high = mid-1;
                }
            }
            low = 0,high = min(i,n-i-1);
            /* whatis(ans) */
            int ans2 = 0;
            while(low <= high){
                mid = low+(high-low)/2;
                /* if(i == 2 && x == 4){ */
                /*     whatis(low) */
                /*     whatis(high) */
                /*     whatis(mid) */
                /*     whatis(col[i-mid][x]) */
                /* } */
                if(col[i-mid][x] > mid*2){
                    low = mid+1;
                    ans2 = mid;
                }
                else{
                    high = mid-1;
                }
            }
            /* whatis(ans2) */
            ans = min(ans,ans2);
            /* whatis(i) */
            /* whatis(x) */
            /* whatis(ans) */
            if(ans){
                memset(&xd[i][x-ans],0,ans*2+1);
                memset(&xd2[x][i-ans],0,ans*2+1);
                vec.pb({{i+1,x+1,ans}});
            }
        }
    }
    FOR(i,0,n){
        FOR(x,0,m){
            if(xd[i][x] & xd2[x][i]) REE(-1)
        }
    }
    cout << vec.size() << '\n';
    FORR(i,vec){
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    }
}