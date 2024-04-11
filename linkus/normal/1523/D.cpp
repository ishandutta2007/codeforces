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
    int n,m,p;
    sc(n,m,p);
    ll a[n];
    FOR(i,0,n){
        a[i] = 0;
        char tmp;
        FOR(x,0,m){
            getch(tmp);
            a[i] <<= 1;
            a[i] ^= tmp ^ 48;
        }
    }
    random_shuffle(a,a+n);
    srand(time(0));
    pair<int,ll> res{};
    /* FOR(x,0,1000){ */
    /* vector<pair<int,ll>> vec[p+1]; */
    /* FOR(x,0,200000){ */
    /* FOR(x,0,2000000){ */
    FOR(x,0,50){
    /* FOR(x,0,20){ */
        int id = rand()%n;
        int cnt[1 << p];
        memset(cnt, 0, sizeof cnt);
        FOR(i,0,n){
            ll wh = 0;
            int it = -1;
            FOR(j,0,m){
                // bruh
                /* if(a[x] & (1ll << j)){ */
                if(a[id] & (1ll << j)){
                    ++it;
                    if(a[i] & (1ll << j)){
                        wh ^= 1ll << it;
                    }
                }
            }
            /* FOR(k,0,1<<p){ */
            /*     bool kk = 1; */
            /*     /1* FOR(j,0,p){ *1/ */
            /*     /1*     // lol *1/ */
            /*     /1*     /2* kk &= (wh & (1ll << j)) != 0; *2/ *1/ */
            /*     /1*     if(k & (1ll << j)) *1/ */
            /*     /1*         kk &= (wh & (1ll << j)) != 0; *1/ */
            /*     /1*     // lol ten cay for XD *1/ */
            /*     /1* } *1/ */
            /*     // -> : */
            /*     kk = (k & wh) == k; */
            /*     cnt[k] += kk; */
            /* } */
            ++cnt[wh];
        }
        int cnt2[1 << p];
        FOR(k,0,1<<p){
            cnt2[k] = 0;
            int ileit = 1 << (p - __builtin_popcount(k));
            int m = k;
            int pm;
            FOR(i,0,ileit){
                cnt2[k] += cnt[m];
                pm = m;
                ++m;
                m |= k;
            }
            /* whatis(pm) */
        }
        FOR(k,0,1<<p){
            // za ten sam bd XD.
            /* if(cnt[k] * 2 > n){ */
            /* if(cnt[k] * 2 >= n){ */
            if(cnt2[k] * 2 >= n){
                // -> TLE :o.
                // -> O(N*2^p) ~ 1e10 hmmm.
                ll act = 0;
                int it = -1;
                FOR(j,0,m){
                    /* if(a[x] & (1ll << j)){ */
                    if(a[id] & (1ll << j)){
                        ++it;
                        /* if(k & (1ll << j)){ */
                        if(k & (1ll << it)){
                            act ^= 1ll << j;
                        }
                    }
                    res = max(res,{__builtin_popcount(k), act});
                }
            }
        }
        /* ll cr = 0; */
        /* FOR(xx,0,1<<p){ */
        /*     ll cr = 0; */
        /*     int it = -1; */
        /*     FOR(j,0,m){ */
        /*         if(a[id] & (1ll << j)){ */
        /*             if(xx & (1ll << ++it)) */
        /*                 cr ^= 1ll << j; */
        /*             /1* if(rand()%2) *1/ */
        /*             /1*     cr ^= 1ll << j; *1/ */
        /*         } */
        /*     } */
        /*     // -> WA129 aj */
        /*     // -> I guess gotta do the submask sums. */
        /*     /1* int ile = 0; *1/ */
        /*     // shufflowanie listy friendsw, i te randomizowane sprawdzanie tylko */
        /*     // na jakich np. 50 typach, czy jest co najmniej 25? */
        /*     // czy too risky edge case wise z takim czym? */
        /*     // -> raczej przypa jak jest exactly n / 2. */
        /*     // ale perhaps still, jako jaki warunek konieczny (> 15) / */
        /*     // wystarczajcy (> 30)? */
        /*     // albo po prostu pod koniec rozpatrzenie najlepszych paru wynikw. */
        /*     // ^^(od najwikszych popcntw?) */
        /*     /1* FOR(j,0,n){ *1/ */
        /*     /1*     ile += (a[j] & cr) == cr; *1/ */
        /*     /1* } *1/ */
        /*     // xd. */
        /*     /1* FOR(j,0,100){ *1/ */
        /*     // that's the ub i suppose. */
        /*     // although why would it break the sort actually? */
        /*     // przecie tu nie ma zadnych modyfikacji itd, tylko odczyt. */
        /*     // -> moe dlatego u mnie git, ale RTE na cfie? */
        /*     /1* FOR(j,0,min(n,500)){ *1/ */
        /*     /1*     ile += (a[j] & cr) == cr; *1/ */
        /*     /1* } *1/ */
        /*     /1* whatis(ile) *1/ */
        /*     /1* whatis(cr) *1/ */
        /*     /1* res = max(res,{ile, cr}); *1/ */
        /*     /1* if(ile * 2 >= n) *1/ */
        /*     /1*     res = max(res,{__builtin_popcountll(cr), cr}); *1/ */
        /*     /1* assert(__builtin_popcountll(cr) <= p); *1/ */
        /*     /1* assert(__builtin_popcountll(cr) >= 0); *1/ */
        /*     /1* vec[__builtin_popcountll(cr)].push_back({ile, cr}); *1/ */
        /* } */
    }
    /* for(int i = p+1; --i;){ */
    /*     whatis(i) */
    /*     assert(i <= p); */
    /*     assert(i >= 0); */
    /*     sort(all(vec[i])); */
    /*     vec[i].erase(unique(all(vec[i])),vec[i].end()); */
    /*     reverse(all(vec[i])); */
    /*     int it = 0; */
    /*     FORR(x,vec[i]){ */
    /*         if(++it == 1001) */
    /*             break; */
    /*         int ile = 0; */
    /*         FOR(j,0,n){ */
    /*             ile += (a[j] & x.e2) == x.e2; */
    /*         } */
    /*         // bruhh */
    /*         /1* if(ile * 2 > n){ *1/ */
    /*         // -> WA37 :/. */
    /*         if(ile * 2 >= n){ */
    /*             res = max(res,{ile, x.e2}); */
    /*             break; */
    /*         } */
    /*     } */
    /*     if(res.first) */
    /*         break; */
    /* } */
    string s;
    whatis(res)
    /* while(res.second){ */
    FOR(x,0,m){
        s += (res.second & 1) ^ 48;
        res.second >>= 1;
    }
    reverse(all(s));
    cout << s << '\n';
}