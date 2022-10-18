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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    sc(n,k);
    int a[n];
    GET(a);
    sort(a,a+n,greater<int>());
    // by cur impact at which >= to place block (<= wsm bo neg)
    // iterating over all to see if there's a pattern / ternary search potential

    // z orderem greater<int>() moge max 70 zdoby na 3cim samplu?

    // zdecydowanie zaraz przed danymi resetami, najlepiej aby byy
    // najnegatywniejsze zmiany, czyli moe fixowanie kolejnoci nie jest zbyt
    // dobre?

    // inaczej totalnie, 2 fazy, sum >= 0 i sum < 0,
    // dobieranie od najmniejszego w 2 fazie do each k resetw ez.

    /* FOR(i,0,n){ */
    /*     cerr << a[i] << ' '; */
    /* } */
    /* cerr << endl; */
    ll res = 0;
    ll crsum = 0;
    int it = n;
    for(int i = 0; i < n; ++i){
        res += crsum;
        crsum += a[i];
        /* whatis(i) */
        /* whatis(res) */
        /* whatis(crsum) */
        if(crsum < 0){
            it = i + 1;
            break;
        }
    }
    // na k + 1 wsm, bo mamy "naturalny" reset na pocztku
    ++k;
    vector<int> wh[k];
    int m = 0;
    for(int x = n - 1; x >= it; --x){
        wh[m].push_back(a[x]);
        ++m;
        m %= k;
    }
    int mxlen = 0;
    int mnlen = INF;
    FORR(i,wh){
        mxlen = max<int>(mxlen,i.size());
        mnlen = min<int>(mxlen,i.size());
        // ==rev
        sort(all(i),greater<int>());
        whatis(i)
        ll crs = 0;
        FORR(x,i){
            res += crs;
            crs += x;
        }
    }
    if(crsum < 0)
        res += crsum * mnlen;
    cout << res << '\n';
    /* for(int wh = -100; wh < 0; ++wh){ */
    /*     int crres = 0; */
    /*     int crsum = 0; */
    /*     int klf = k; */
    /*     int nres_od_last = 0; */
    /*     int nsum_od_last = 0; */
    /*     // res cakowity, czy tylko ten ujemny? */
    /*     // nvm, that makes very little sense */
    /*     // by ujemny dodany res na lewo maybe? */
    /*     // or nsum od last? */
    /*     for(int i = 0; i < n; ++i){ */
    /*         int crimp = crsum * (n - i); */
    /*         /1* if(crimp <= wh){ *1/ */
    /*         /1* if(crsum <= wh){ *1/ */
    /*         if(nres_od_last <= wh){ */
    /*         /1* if(nsum_od_last <= wh){ *1/ */
    /*             if(klf > 0){ */
    /*                 --klf; */
    /*                 crsum = 0; */
    /*             } */
    /*         } */
    /*         crres += crsum; */
    /*         nsum_od_last += min(0,a[i]); */
    /*         /1* nres_od_last += crsum; *1/ */
    /*         crsum += a[i]; */
    /*     } */
    /*     cout << wh << ": " << crres << '\n'; */
    /* } */
}