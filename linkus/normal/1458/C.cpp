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

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
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
/* #define N 1000001 */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // very meme greedy
    int t;
    sc(t);
    while(t--){
        /* int N, M; */
		/* /1* cin >> N >> M; *1/ */
        /* sc(N,M); */
		/* vector<int> val[3] = {vector<int>(N*N), vector<int>(N*N), vector<int>(N*N)}; */
		/* for(int i = 0; i < N*N; i++) { */
			/* val[0][i] = i/N; */
			/* val[1][i] = i%N; */
			/* /1* cin >> val[2][i]; *1/ */
        /*     sc(val[2][i]); */
			/* val[2][i]--; */
		/* } */
		/* int P[3] = {0, 1, 2}; */
		/* int sh[3] = {0, 0, 0}; */
		/* string S; */
		/* /1* cin >> S; *1/ */
        /* getstr(S); */
		/* for(int i = 0; i < M; i++) { */
			/* if(S[i] == 'R') sh[P[1]]++; */
			/* if(S[i] == 'L') sh[P[1]]--; */
			/* if(S[i] == 'D') sh[P[0]]++; */
			/* if(S[i] == 'U') sh[P[0]]--; */
			/* if(S[i] == 'I') swap(P[1], P[2]); */
			/* if(S[i] == 'C') swap(P[0], P[2]); */
		/* } */
		/* vector< vector<int> > ans(N, vector<int>(N)); */
		/* for(int i = 0; i < N*N; i++) { */
			/* int v[3] = {val[P[0]][i]+sh[P[0]], val[P[1]][i]+sh[P[1]], val[P[2]][i]+sh[P[2]]}; */
			/* v[0] %= N; */
			/* if(v[0] < 0) v[0] += N; */
			/* v[1] %= N; */
			/* if(v[1] < 0) v[1] += N; */
			/* v[2] %= N; */
			/* if(v[2] < 0) v[2] += N; */
			/* ans[v[0]][v[1]] = v[2]; */
		/* } */
		/* for(int i = 0; i < N; i++) */
			/* for(int j = 0; j < N; j++) */
				/* cout << ans[i][j]+1 << ((j == N-1) ? "\n" : " "); */
        /* cout.put(10); */
        int n,m;
        sc(n,m);
        int a[n][n];
        /* int a[1000][n]; */
        FORR(i,a){
            GET(i);
            FORR(x,i)
                --x;
        }
        int val[3][n*n]; // warto danego koordynatu dla punktu z danym id
        // {nr_rowa, nr_cola, val}
        // mniej ifologii potem, jeli to w 1d storuje
        FOR(i,0,n){
            /* FOR(x,0,m){ */
            FOR(x,0,n){
                val[0][i*n+x] = i;
                val[1][i*n+x] = x;
                val[2][i*n+x] = a[i][x];
            }
        }
        // surely thats the same...
        /* FOR(i,0,n*n){ */
        /*     val[0][i] = i/n; */
        /*     val[1][i] = i%n; */
        /*     val[2][i] = a[i/n][i%n];; */
        /* } */
        // keep track of (0,0,0)
        int cord_swp[3] = {0,1,2};
        int shft[3] = {0,0,0};
        string s;
        getstr(s);
        FORR(i,s){
            if(i == 'L')
                --shft[cord_swp[1]];
            else if(i == 'R')
                ++shft[cord_swp[1]];
            else if(i == 'U')
                /* ++dpion; */
                --shft[cord_swp[0]];
            else if(i == 'D')
                ++shft[cord_swp[0]];
            else if(i == 'I')
                swap(cord_swp[2], cord_swp[1]);
            else if(i == 'C')
                swap(cord_swp[2], cord_swp[0]);
        }
        /* int nw[n][n]; */
        FOR(i,0,n*n){
            /* FOR(x,0,n){ */
                /* int ni = i + shft[cord_swp[0]]; */
                /* ni = (ni % n + n) % n; */
                /* int nx = x + shft[cord_swp[1]]; */
                /* nx = (nx % n + n) % n; */
                /* /1* nw[ni][nx] = a[i][x]; *1/ */
                /* int nv = a[i][x] + shft[cord_swp[2]]; */
                /* nv = (nv % n + n) % n; */
                /* nw[ni][nx] = nv; */
            /* int ni = val[0][i] + shft[cord_swp[0]]; */
            // forgot to include the cord_swps in left parts
            int ni = val[cord_swp[0]][i] + shft[cord_swp[0]];
            ni = (ni % n + n) % n;
            int nx = val[cord_swp[1]][i] + shft[cord_swp[1]];
            nx = (nx % n + n) % n;
            /* nw[ni][nx] = a[i][x]; */
            int nv = val[cord_swp[2]][i] + shft[cord_swp[2]];
            nv = (nv % n + n) % n;
            /* nw[ni][nx] = nv; */
            a[ni][nx] = nv;
            /* whatis(ni) */
            /* whatis(nx) */
            /* whatis(nv) */
            /* } */
            /* int v[3] = {val[cord_swp[0]][i] + shft[cord_swp[0]], val[cord_swp[1]][i] + shft[cord_swp[1]], val[cord_swp[2]][i] + shft[cord_swp[2]]}; */
            /* v[0] %= n; */
            /* if(v[0] < 0) v[0] += n; */
            /* v[1] %= n; */
            /* if(v[1] < 0) v[1] += n; */
            /* v[2] %= n; */
            /* if(v[2] < 0) v[2] += n; */
            /* a[v[0]][v[1]] = v[2]; */
        }
        /* memcpy(a,nw,n*n<<2); */
        FOR(i,0,n){
            FOR(x,0,n){
                /* cout << a[i][x] << ' '; */
                cout << a[i][x] + 1 << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}