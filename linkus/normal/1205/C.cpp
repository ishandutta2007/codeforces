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
#define N 55

int a[N][N];
int n;

int z(int x1, int y1, int x2, int y2){
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    memset(a,-1,sizeof a);
    a[1][1] = 1;
    a[n][n] = 0;
    a[1][2] = 0;
    a[2][3] = a[1][2]^1^z(1,2,2,3);
    a[2][1] = a[2][3]^1^z(2,1,2,3);
    FORE(i,1,n){
        FORE(x,1,n){
            /* if((i+x)%2) continue; */
            if(~a[i][x]) continue;
            if(x == 1){
                int wh = z(i-2,x,i,x);
                a[i][x] = a[i-2][x]^(!wh);
            }
            else if(i == 1){
                int wh = z(i,x-2,i,x);
                a[i][x] = a[i][x-2]^(!wh);
            }
            else{
                int wh = z(i-1,x-1,i,x);
                a[i][x] = a[i-1][x-1]^(!wh);
            }
        }
    }
    /* FORE(i,1,n){ */
    /*     FORE(x,1,n){ */
    /*         /1* cout << ' '; *1/ */
    /*         /1* if((i+x)%2){ *1/ */
    /*         /1*     cout << ' '; *1/ */
    /*         /1*     continue; *1/ */
    /*         /1* } *1/ */
    /*         /1* cout << ' '; *1/ */
    /*         cout << a[i][x] << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
    bool rev = 0;
    bool dood = 0;
    FORE(i,1,n-2){
        FORE(x,1,n-1){ //upleft corner
            bool upb = (i+x)&1;
            int xr = a[i][x]^a[i+1][x]^a[i+2][x]^a[i+2][x+1];
            if(!xr){
                int ww = z(i,x,i+2,x+1);
                int shd = (a[i][x] == a[i+2][x])^ww^(a[i][x]);
                if(a[i+1][x] != shd) rev ^= 1;
                /* if(!ww){ */
                /* } */
                dood = 1;
                break;
            }
            xr = a[i][x]^a[i+1][x]^a[i+1][x+1]^a[i+2][x+1];
            if(!xr){
                /* whatis("love") */
                int ww = z(i,x,i+2,x+1);
                int shd = (a[i][x] == a[i+1][x+1])^ww^a[i][x];
                if(a[i+1][x] != shd) rev ^= 1;
                /* if(!ww){ */
                /* } */
                dood = 1;
                break;
            }
            xr = a[i][x]^a[i][x+1]^a[i+1][x+1]^a[i+2][x+1];
            if(!xr){
                /* whatis("love2") */
                int ww = z(i,x,i+2,x+1);
                int shd = (a[i][x] == a[i+1][x+1])^ww^a[i][x];
                if(a[i][x+1] != shd) rev ^= 1;
                /* if(!ww){ */
                /* } */
                dood = 1;
                break;
            }
        }
        if(dood) break;
    }
    if(rev){
        FORE(i,1,n)
            FORE(x,1,n)
                if((i+x)&1)
                    a[i][x] ^= 1;
    }
    cout << "!" << endl;
    FORE(i,1,n){
        FORE(x,1,n){
            /* cout << ' '; */
            /* if((i+x)%2){ */
            /*     cout << ' '; */
            /*     continue; */
            /* } */
            /* cout << ' '; */
            cout << a[i][x];
        }
        cout << endl;
    }
}