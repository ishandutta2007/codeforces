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
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int n,m;
int adj[101][101];
/* int arr[101][101]; */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,m);
    FOR(i,0,n){
        FOR(x,0,m){
            sc(adj[i][x]);
        }
    }
    bool g = 0;
    int mncol[m];
    int mnrow[n];
    vector<pair<bool,int>> ans;
    while(!g){
        g = 1;
        memset(mncol,63,sizeof mncol);
        memset(mnrow,63,sizeof mnrow);
        FOR(i,0,n){
            FOR(x,0,m){
                mnrow[i] = min(mnrow[i],adj[i][x]);
                mncol[x] = min(mncol[x],adj[i][x]);
            }
        }
        FOR(i,0,n){
            int x = 0;
            int mn = mnrow[i];
            if(mn == SINF) continue;
            while(x < m){
                if(adj[i][x] > mn){
                    int dif = adj[i][x] - mn;
                    FOR(i,0,dif)
                        ans.push_back({0,x+1});
                        /* cout << "col " << x+1 << '\n'; */
                    g = 0;
                    FOR(c,0,n){
                        if((adj[c][x] -= dif) < 0){
                            REE(-1)
                        }
                    }
                    /* FOR(i,0,n){ */
                    /*     FOR(x,0,m){ */
                    /*         cout << adj[i][x] << ' '; */
                    /*     } */
                    /*     cout << '\n'; */
                    /* } */
                }
                ++x;
            }
        }
        FOR(i,0,m){
            int x = 0;
            int mn = mncol[i];
            if(mn == SINF) continue;
            while(x < n){
                if(adj[x][i] > mn){
                    int dif = adj[x][i] - mn;
                    FOR(i,0,dif)
                        ans.push_back({1,x+1});
                        /* cout << "row " << x+1 << '\n'; */
                    g = 0;
                    FOR(c,0,m){
                        if((adj[x][c] -= dif) < 0){
                            REE(-1)
                        }
                    }
                    /* FOR(i,0,n){ */
                    /*     FOR(x,0,m){ */
                    /*         cout << adj[i][x] << ' '; */
                    /*     } */
                    /*     cout << '\n'; */
                    /* } */
                }
                ++x;
            }
        }
    }
    int val;
    if(m > n)
    FOR(i,0,n){
        val = INF;
        FOR(x,0,m){
            val = min(val,adj[i][x]);
        }
        if(val){
            FOR(q,0,val)
            ans.push_back({1,i+1});
            FOR(x,0,m){
                adj[i][x] -= val;
            }
        }
    }
    else
    FOR(i,0,m){
        val = INF;
        FOR(x,0,n){
            val = min(val,adj[x][i]);
        }
        if(val){
            FOR(q,0,val)
            ans.push_back({0,i+1});
            FOR(x,0,n){
                adj[x][i] -= val;
            }
        }
    }
    cout << ans.size() << '\n';
    FORR(i,ans){
        if(i.e1){
            cout << "row ";
        }
        else{
            cout << "col ";
        }
        cout << i.e2 << '\n';
    }
}