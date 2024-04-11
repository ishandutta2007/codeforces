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
#define N 1000001

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    vi a(n);
    GET(a);
    sort(all(a));
    ll sum = 0;
    FORR(i,a) sum += i;
    int nn = n+1;
    int bg = sum&1;
    //first good (not too small)
    int low = bg, high = n, mid, ans = INF;
    if((high^low)&1) --high;
    while(low <= high){
        mid = (high+low)/2;
        if((mid^low)&1) --mid;
        /* whatis(mid) */
        vi cr = a;
        cr.pb(mid);
        sort(all(cr),greater<int>());
        /* ll sall = sum+mid; */
        ll s = 0;
        bool kk = 1;
        bool lg = 0;
        ll ssum = 0;
        int it = n; //first where k >= di
        //za tym all di < k
        /* whatis(cr) */
        FOR(k,0,nn){
            s += cr[k];
            while(it > k && cr[it] < k+1){
                ssum += cr[it];
                --it;
            }
            if(it == k-1){
                ++it;
                ssum -= cr[it];
            }
            ll r = (ll)(it-k)*(k+1)+ssum;
            /* whatis(k) */
            /* whatis(r) */
            /* whatis(ssum) */
            if(s <= ((ll)(k))*(k+1) + r){
            }
            else{
                /* kk = 0; */
                if(cr[k] > mid){
                    kk = 0;
                    break;
                    /* whatis("too small") */
                }
                else{
                    /* whatis("too large") */
                    lg = 1;
                }
            }
        }
        /* if(n == 500000){ */
        /* cout << "mid: " << mid << '\n'; */
        /* cout << "kk: " << kk << '\n'; */
        /* cout << "lg: " << lg << '\n'; */
        /* } */
        if(kk){
            high = mid-2;
            ans = mid;
        }
        else{
            low = mid+2;
        }
        /* whatis(high) */
        /* whatis(low) */
    }
    /* whatis(ans) */
    int ans1 = ans;
    //ostatnie dobre
    low = ans1, high = n, ans = -1;
    if((high^low)&1) --high;
    while(low <= high){
        mid = (high+low)/2;
        if((mid^low)&1) --mid;
        whatis(mid)
        vi cr = a;
        cr.pb(mid);
        sort(all(cr),greater<int>());
        /* ll sall = sum+mid; */
        ll s = 0;
        bool kk = 1;
        ll ssum = 0;
        int it = n; //first where k >= di
        FOR(k,0,nn){
            s += cr[k];
            while(it > k && cr[it] < k+1){
                ssum += cr[it];
                --it;
            }
            if(it == k-1){
                ++it;
                ssum -= cr[it];
            }
            ll r = (ll)(it-k)*(k+1)+ssum;
            if(s <= ((ll)(k))*(k+1) + r){
            }
            else{
                /* kk = 0; */
                if(cr[k] > mid){
                    assert(0);
                    /* kk = 0; */
                    /* break; */
                    /* whatis("too small") */
                }
                else{
                    kk = 0;
                    break;
                    /* whatis("too large") */
                }
            }
        }
        if(kk){
            low = mid+2;
            ans = mid;
        }
        else{
            high = mid-2;
        }
        /* whatis(high) */
        /* whatis(low) */
    }
    /* whatis(ans1) */
    /* whatis(ans) */
    /* for(int i = bg; i <= n; i += 2){ */
    /*     vi cr = a; */
    /*     cr.pb(i); */
    /*     sort(all(cr),greater<int>()); */
    /*     ll sall = sum+i; */
    /*     ll s = 0; */
    /*     bool kk = 1; */
    /*     FOR(k,0,n){ */
    /*         s += cr[k]; */
    /*         if(s <= k*(k+1) + sall-s){ */
    /*         } */
    /*         else{ */
    /*             kk = 0; */
    /*             if(cr[k] > i){ */
    /*                 whatis("too small") */
    /*             } */
    /*             else{ */
    /*                 whatis("too large") */
    /*             } */
    /*         } */
    /*     } */
    /* } */
    if(ans1 > ans || ans == -1 || ans1 == -1) REE(-1)
    for(int i = ans1; i <= ans; i += 2)
        cout << i << ' ';
}