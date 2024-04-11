#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <numeric>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
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
 
int main(){
    int n;
    cin >> n;
    if(n&1){
        cout << "Second" << endl;
        vi a[n];
        vi wh[n]; // where with said mod n
        FOR(i,0,2*n){
            int tmp;
            cin >> tmp;
            a[tmp-1].pb(i+1);
            wh[(i+1)%n].pb(tmp-1);
        }
        int picked[n];
        memset(picked,-1,n<<2);
        picked[0] = 0;
        int cr = 0;
        /* unordered_set<int> free; // set dla 1..n, giga idea */
        bool free[n];
        memset(free,1,n);
        /* FOR(i,0,n) */
        /*     free.insert(i); */
        /* free.erase(0); // nie cr... */
        /* free.erase(a[0][0] % n); */
        free[a[0][0] % n] = 0;
        FORR(i,a)
            whatis(i)
        /* FOR(ii,0,n){ */
        int frcnt = n-1;
        /* while(!free.empty()){ */
        int it = 0;
        while(frcnt){
            int nxval = (a[cr][picked[cr] ^ 1]) % n;
            whatis(nxval)
            // pominem tu jeszcze case, e wczeniej zabraem ju ten nxval z
            // tego samego cra...
            /* if(find_if(all(wh[nxval]),[&](int x){return x != cr;}) == wh[nxval].end()){ */
            // that's gonna be a better metric...
            /* if(!free.count(nxval)){ */
            if(!free[nxval]){
                /* assert(!free.count(nxval)); */
                // any free, won't have any by cr so fine
                /* nxval = *free.begin(); */
                // hmm, that actually is better with a set i guess...
                /* nxval = *free.begin(); */
                // nested for loops go brrrrr
                // rip
                /* for(int i = 0; i < n; ++i){ */
                // const it, jak mogem na to nie wpa...
                for(;it < n; ++it){
                    if(free[it]){
                        nxval = it;
                        break;
                    }
                }
            }
            /* free.erase(nxval); */
            free[nxval] = 0;
            --frcnt;
            cr = *find_if(all(wh[nxval]),[&](int x){return x != cr;});
            whatis(cr)
            picked[cr] = find_if(all(a[cr]),[&](int x){return x % n == nxval;}) - a[cr].begin();
            assert(picked[cr] < 2);
        }
        ll crsum = 0;
        FOR(i,0,n){
            crsum += a[i][picked[i]];
        }
        whatis(crsum)
        assert(crsum % n == 0);
        // giga eb z knapsackiem btw
        if(crsum % (2*n)){
            // omg, wtedy po prostu bierzesz odwrt wowow
            // ale eleganckie
            FORR(i,picked)
                i ^= 1;
        }
        FOR(i,0,n){
            cout << a[i][picked[i]] << ' ';
        }
        cout << endl;
    }
    else{
        cout << "First" << endl;
        FOR(i,0,2*n){
            cout << i%n+1 << ' ';
        }
        cout << endl;
    }
}