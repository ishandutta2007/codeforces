#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <set>
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
#define N 1000001
#define int ll

// function, base val
template<ll op(ll, ll), ll baseval>
class seg{
public:
    ll t[N*2];
    ll n;

    ll query(ll l, ll r){
        ll res = baseval;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1)
                res = op(res,t[l++]);
                //res += t[l++];
            if(r&1)
                res = op(res,t[--r]);
                //res += t[--r];
        }
        return res;
    }

    void modify(ll p, ll val){
        for(t[p += n] = val; p > 1; p>>=1)
            t[p>>1] = op(t[p] , t[p^1]);
    }

    template<typename T>
    seg(T a, int n) : n(n) {
        for(int i = 2*n-1; i >= n; --i)
            t[i] = a[i - n];
        for(int i = n - 1; i > 0; --i)
            t[i] = op(t[i<<1] , t[i<<1|1]);
    }
};

ll segfun(ll a, ll b){
    /* return max(a,b); */
    /* return min(a,b); */
    return a + b;
}


ll fun(ll n){
    /* return n * (n - 1) / 2; */
    // XD.
    return n * (n + 1) / 2;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    sc(n,q);
    int a[n];
    GET(a);
    vector<ll> arr(n, 0);
    /* memset(arr,0,n<<2); */
    set<int> st;
    // what of ind 0?
    /* st.insert(0); */
    st.insert(-1);
    FOR(i,1,n){
        if(a[i] < a[i-1]){
            /* arr[i] = fun(i - *st.rbegin()); */
            /* arr[i] = fun(i - 1 - *st.rbegin()); */
            arr[i - 1] = fun(i - 1 - *st.rbegin());
            /* st.insert(i); */
            st.insert(i - 1);
        }
    }
    /* { */
    /*     arr[n - 1] = fun(i - 1 - *st.rbegin()); */
    /*     st.insert(n - 1); // is it needed tbh? */
    /* } */
    whatis(st)
    static seg<segfun, 0> t(arr, arr.size());
    while(q--){
        int typ, l, r;
        sc(typ, l, r);
        if(typ == 2){
            --l, --r;
            whatis(l)
            whatis(r)
            int res = 0;
            /* auto it = st.lower_bound(l + 1); // edge case end. */
            auto it = st.lower_bound(l); // edge case end.
            int newl;
            /* if(it != st.end()){ */
            if(it != st.end() && *it + 1 <= r){
                /* int newl = *it; */
                newl = (*it) + 1;
                whatis(newl)
                /* whatis(newl) */
                res += t.query(newl, r + 1);
                whatis(t.query(newl, r + 1))
            }
            else{
                /* newl = n; */
                /* newl = r; */
                // luv you samples/
                newl = r + 1;
                /* assert(0); */
            }
            res += fun(newl - l);
            whatis(fun(newl - l))
            auto it2 = st.upper_bound(r); // edge case beg.
            /* if(it2 != st.begin() && *prev(it2) > newl - 1){ */
            if(it2 != st.begin()){
                /* int sth = *prev(it2); */
                int sth = max(*prev(it2), newl - 1); // needless def?
                /* res += fun(r - sth); */
                res += fun(r - sth);
                /* whatis(fun(r - sth)) */
            }
            cout << res << '\n';
        }
        else{
            int xx = l;
            --xx;
            int yy = r;
            a[xx] = yy;
            auto it = st.lower_bound(xx + 1);
            vector<ll> wh = {xx, xx + 1}; // xx + 1 eq n?
            // -> lets also make that special.
            if(it != st.end())
                /* wh.push_back(*it); */
                wh.push_back(*it + 1);
            FORR(i,wh){
                /* if(i == 0y){ */
                if(i == 0 || i >= n){
                    continue;
                }
                st.erase(i - 1);
                arr[i - 1] = 0;
                if(a[i] < a[i-1]){
                    // i == 0 -> rip.
                    // -> special case.
                    auto prit = *prev(st.lower_bound(i - 1));
                    arr[i - 1] = fun(i - 1 - prit);
                    st.insert(i - 1);
                }
                t.modify(i - 1, arr[i - 1]);
            }
            /* if(a[xx] < a[xx - 1]){ */
            /* } */
            /* else if(a[xx] > a[xx + 1]){ */
            /* } */
        }
    }
}