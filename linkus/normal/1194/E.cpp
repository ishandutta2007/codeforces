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
template<class T> ostream& operator<<(ostream &os, array<T,4> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 12000

int n = N;
int t[N+4];
vector<array<int,4>> poz,pion;

//1 INDEXED, increment in function if needed
//ilosc segmentow calych wewnatch l,r xowo xdd

inline void upd(int pos, int val){ //val is delta
    for(;pos <= n;pos += pos & (-pos))
            //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
        t[pos] += val;
}

inline int query(int r){ //[0,r]
    int ret = 0;
    for(;r > 0;r -= r & (-r))
        ret += t[r];
    return ret;
}

/* void ins(int i){ //insert iponline */

/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    /* if(n == 5000){ */
    /*     n = 4081;// */
    /* } */
    FOR(i,0,n){
        int x1,y1,x2,y2;
        sc(x1,y1,x2,y2);
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
/* #warning FUCK */
        x1 += 5500;
        x2 += 5500;
        y1 += 5500;
        y2 += 5500;
        /* if(n == 4081 && i+1 == n){ */
        /*     cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl; */
        /*     return 0; */
        /* } */
        if(y1 == y2){
            poz.pb({x1,y1,x2,y2});
        }
        else{
            pion.pb({x1,y1,x2,y2});
        }
    }
    sort(all(poz),[](array<int,4> f,array<int,4> s){return f[1] < s[1];}); //od najnizszego
    sort(all(pion),[](array<int,4> f,array<int,4> s){return f[1] < s[1];}); //od najniszego bega //WTTFFFFFFFFFFFFFF
    ll ans = 0;
    /* auto it = pion.begin(); */
    FOR(i,0,poz.size()){
        /* while(it+1 < pion.end() && (*(it+1))[1] <= poz[i][1]){ */
        /*     ++it; */
        /* } */
        //do it wlacznie maja poczatek nie wyzej
        vector<array<int,4>> xd; //dobre piony
        FORR(x,pion){
            if(x[1] <= poz[i][1] && x[3] >= poz[i][1])
                xd.pb(x);
        }
        sort(all(xd),[](array<int,4> f,array<int,4> s){return f[3] > s[3];}); //od najwyszego
        auto it = xd.begin();
        /* whatis(poz[i]) */
        /* whatis(xd) */
        vi lol;
        /* vector<array<int,4>> kurwa; //czemu to krwa zapomnialem */
        /* FOR(x,i+1,poz.size()){ */
        /*     kurwa.pb(poz[x]); */
        /* } */
        /* sort(aint(kurwa),[](array<int,4> f,array<int,4> s){return f[1] > s[1];}); //od najwyszego */
        /* FOR(x,i+1,poz.size()){ */
        for(int x = poz.size()-1; x > i; --x){
            while(it < xd.end() && (*it)[3] >= poz[x][1]){
                /* whatis(*it) */
                upd((*it)[0],1);
                lol.pb((*it)[0]);
                ++it;
            }
            /* whatis(poz[x]) */
            int l = max(poz[i][0],poz[x][0]);
            int r = min(poz[i][2],poz[x][2]);
            if(l > r) continue;
            /* whatis(l) */
            /* whatis(r) */
            /* if(n == 5000){ */
            /*     assert(!query(r)); */
            /* } */
            int ile = query(r)-query(l-1);
            /* whatis(ile) */
            ans += (ll)ile*(ile-1)/2;
        }
        FORR(i,lol)
            upd(i,-1);
    }
    cout << ans << '\n';
}