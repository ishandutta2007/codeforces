#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
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
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
// 1 << 19 if segtree where merges matter.
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    sc(t);
    while(t--){
        ll n,k;
        sc(n,k);
        /* ll a[n]; */
        vector<ll> a(n);
        GET(a);
        /* sort(a,a+n); */
        sort(all(a));
        multiset<ll> st;
        /* unordered_multiset<ll> st; */
        /* map<int,int> st; */
        FORR(i,a){
            if(i % k == 0 && st.count(i / k)){
            /* if(i % k == 0 && st.contains(i / k)){ */
            /* if(i % k == 0 && st[i / k]){ */
                /* whatis(i / k) */
                /* whatis(st[i / k]) */
                /* --st[i / k]; */
                st.erase(st.find(i / k));
                /* if(!--st[i / k]) */
                /*     st.erase(i / k); */
            }
            /* else if(st.count((ll)i * k)) */
            /*     st.erase(st.find((ll)i * k)); */
            else if(st.contains((ll)i * k))
                assert(0);
            else{
                st.insert(i);
                /* ++st[i]; */
            }
        }
        cout << st.size() << '\n';
        /* int res = 0; */
        /* FORR(i,st) */
        /*     res += i.second; */
        /* cout << res << '\n'; */
        // -> AC in 93ms. Wtf multiset?
        // -> WTF XD? 73ms multiset tera. how?
        // -> tam wczeniej miaem 1. ll 2. else if i * k branch.
        // inty z ll castowaniem i i * k branch -> TLE 4 XD
        // cpp17 te.
        // same lly bez brancha -> 77ms.
        // z assert 0 tak samo.
        // MSVCPP -> te tle xd.
        // -> XDDDDD COOOO
        // multiset::count complexity Logarithmic in size and linear in the
        // number of matches.
        // xdddddddd
        // to nieza implementacja.
        // ale still nie czaje tbh, bo przecie count z i * k to powinno by 0
        // zawsze xd.
        // (nawet assert(0) mam xd)
        // jak zmieni grny count na contains, to jest ac :o
        // czyli ten else if jako wpywa na optymalizacj tego grnego, ciekawe.
    }
    /* // ???? */
    /* int t; */
    /* cin >> t; */
    /* while(t--){ */
    /*     int n, k; */
    /*     cin >> n >> k; */
    /*     int a[n]; */
    /*     FOR(i,0,n) */
    /*         cin >> a[i]; */
    /*     sort(a, a + n); */
    /*     int it = 0; */
    /*     int res = 0; */
    /*     bool pckd[n]; */
    /*     memset(pckd,0,n); */
    /*     FOR(i,0,n){ */
    /*         if(a[i] % k) */
    /*             continue; */
    /*         while(it < i && (a[it] < a[i] / k || pckd[it])) */
    /*             ++it; */
    /*         if(it < i && a[it] == a[i] / k) */
    /*             ++++res, ++it, pckd[i] = 1; */
    /*     } */
    /*     cout << n - res << '\n'; */
    /* } */
}