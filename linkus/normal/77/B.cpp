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
#define N 1000001

// delta = b^2 - 4ac
// -> delta = p - 4q
// -> p - 4q >= 0
// -> p >= 4q *y >= 4x*
// pole jakiegotrjkta? (podzielone przez pole caoci)
// podzia na pod / nad osi ox?
/* // pod: -4b / 2 */
/* // pod: (-4b / 2) * a */
// pod: -4b * a
// bo jakiekolwiek a git^^
// ale czemu 4b a nie b wsm?
// nad: min(4b,a) * a / 2
// -> /= a*(2b)
// czy /= a*(8b) ?


// XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
// RANDOLY CHANGE EVERYTHING UNTIL AC

#define double long double
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        // nan jak a lub b 0 lol
        double a,b;
        cin >> a >> b;
        cout << fixed << setprecision(14);
        /* double pole1 = -4*b * a; */
        double pole1 = 4*b * a;
        // moze ten min jest zy?
        // w samplach 4*b >= a zawsze takze ten
        /* whatis(4*b) */
        /* whatis(a) */
        /* whatis(min(4*b,a)) */
        // min -> rip liniowo or sth?
        // ale chyba nie moze byc pole2 niezalezne od b?
        // or idk
        // podzia na 4b >= a i 4b < a?
        double pole2 = min(4*b,a) * a / 2;
        /* pole2 += (a - min(4*b,a)) * b; */
        // res > 1 z poniszym
        /* pole2 += (a - min(4*b,a)) * 4*b; */
        pole2 += (a - min(4*b,a)) * 4*b / 2;
        // res == 1 z 0.000000001 0.000000001 ^^
        // -> AC XDDDDDDDDDDDDDDDDD
        // ale teraz jak a > b, to jest res > 1 hmm
        /* double pole2 = a * a / 2; */
        // is that better?
        /* double pole2 = min(4*b,4*a) * a / 2; */
        // that doesnt pass sample wait
        double cale = a*8*b;
        /* if(cale == 0){ */
        /*     /1* cout << "0.0000\n"; *1/ */
        /*     // wsmmmm */
        /*     // dy do inf i guess */
        /*     cout << "1.0000\n"; */
        /*     // bruh */
        /* } */
        // eh, nice forgotting that
        if(a == 0 && b == 0){
            cout << "1.0000\n";
        }
        // moglem chociaz order zamienic wsm
        // XD, still
        else if(a == 0){
            // 1/2, bo zalezne tylk od pos/neg b
            cout << "0.5000\n";
            // ??
            /* cout << "0.7500\n"; */
        }
        else if(b == 0){
            // zawsze nieujemna delta
            cout << "1.0000\n";
        }
        // justtttt
        // jeszcze a == 0 i b == 0? xd
        else{
            cout << (pole1 + pole2) / cale << '\n';
        }
    }
}