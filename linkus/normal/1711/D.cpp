/* #pragma GCC optimize("O3,unroll-loops") */
/* #pragma GCC optimize("Ofast,unroll-loops") */
/* #pragma GCC target("avx2,popcnt") */
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
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
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
#define debug(x...) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) { return o << '(' << p.first << ", " << p.second << ')'; }
template<class T, enable_if_t<!is_same<T, string>::value, bool> = true> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) { o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}'; }
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        int n,m;
        sc(n,m);
        array<int,3> a[n];
        vi wh;
        FOR(i,0,n){
            sc(a[i][0], a[i][1]);
            a[i][2] = i;
            wh.push_back(a[i][0]);
        }
        sort(all(wh));
        wh.erase(unique(all(wh)), wh.end());
        /* int cum[wh.size()]; */
        ll cum[n];
        sort(a,a+n);
        multiset<int> expr;
        ll curp = 0;
        int prev = 0;
        int it = 0;
        FORR(i,a){
            while(expr.size() && *expr.begin() <= i[0]){
                curp -= (*expr.begin() - prev);
                expr.erase(expr.begin());
            }
            curp -= expr.size() * (i[0] - prev);
            curp += i[1];
            expr.insert(i[0] + i[1]);
            prev = i[0];
            /* cum[i[0]] = curp; */
            cum[it] = curp;
            ++it;
        }
        expr.clear();
        curp = 0;
        prev = 0;
        it = n - 1;
        reverse(a,a+n);
        /* FORR(i,cum){ */
        /*     cout << i << ' '; */
        /* } */
        /* cout << endl; */
        FORR(i,a){
            while(expr.size() && *expr.rbegin() >= i[0]){
                curp -= -(*expr.rbegin() - prev);
                expr.erase(--expr.end());
            }
            curp -= expr.size() * -(i[0] - prev);
            /* curp += i[1]; */
            expr.insert(i[0] - i[1]);
            prev = i[0];
            /* cum[i[0]] = curp; */
            /* cum[it] = curp; */
            cum[it] += curp;
            curp += i[1];
            --it;
        }
        /* FORR(i,cum){ */
        /*     cout << i << ' '; */
        /* } */
        /* cout << endl; */
        pair<ll,ll> bs1,bs2;
        bs1 = {LONG_LONG_MIN,LONG_LONG_MIN};
        bs2 = bs1;
        it = 0;
        reverse(a,a+n);
        FORR(i,a){
            ll cr = cum[it] - m;
            if(cr > 0){
                whatis(bs1)
                bs1 = max(bs1, pair<ll,ll>{cr - i[0], i[0]});
                whatis(bs1)
                bs2 = max(bs2, pair<ll,ll>{cr + i[0], i[0]});
            }
            ++it;
        }
        if(bs1.e1 == LONG_LONG_MIN){
            cout << string(n,'1') << '\n';
        }
        else{
            whatis(bs1)
            whatis(bs2)
            string kk(n,'0');
            vector<ll> sth = {bs1.e2, bs2.e2};
            ll xd[2] = {bs1.e1 + bs1.e2, bs2.e1 - bs2.e2}; // just crs.
            FORR(i,a){
                bool git = 1;
                FOR(k,0,2){
                    git &= max<ll>(0, i[1] - abs(i[0] - sth[k])) >= xd[k];
                }
                if(git)
                    kk[i[2]] = '1';
            }
            cout << kk << '\n';
        }
    }
}