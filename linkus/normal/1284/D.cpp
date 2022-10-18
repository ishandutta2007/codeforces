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
#define N 1002001

ll t1[N],t2[N];

const ll B = 2305843009213693951;
const int n = N-1;
inline void upd2(int pos, ll val){ //val is delta
    for(;pos <= n;pos += pos & (-pos))
            //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
        t2[pos] += val, t2[pos] %= B;
}
inline void upd1(int pos, ll val){ //val is delta
    for(;pos <= n;pos += pos & (-pos))
            //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
        t1[pos] += val, t1[pos] %= B;
}

inline ll query1(int r){ //[0,r]
    ll ret = 0;
    for(;r > 0;r -= r & (-r))
        ret += t1[r], ret %= B;
    return ret;
}
inline ll query2(int r){ //[0,r]
    ll ret = 0;
    for(;r > 0;r -= r & (-r))
        ret += t2[r], ret %= B;
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    srand(time(0));
    int n;
    sc(n);
    array<int,3> a[n],b[n];
    ll wh[n];
    FOR(i,0,n){
        wh[i] = (rand()%B*rand()%B*rand()%B)%B+B%B;
    }
    vi xd1,xd2;
    FOR(i,0,n){
        sc(a[i][0],a[i][1],b[i][0],b[i][1]);
        a[i][2] = b[i][2] = i;
        xd1.pb(a[i][0]);
        xd1.pb(a[i][1]);
        xd2.pb(b[i][0]);
        xd2.pb(b[i][1]);
    }
    sort(all(xd1));
    xd1.erase(unique(all(xd1)),xd1.end());
    sort(all(xd2));
    xd2.erase(unique(all(xd2)),xd2.end());
    bool df = 0;
    FOR(i,0,n){
        a[i][0] = lower_bound(all(xd1),a[i][0])-xd1.begin();
        a[i][1] = lower_bound(all(xd1),a[i][1])-xd1.begin();
        b[i][0] = lower_bound(all(xd2),b[i][0])-xd2.begin();
        b[i][1] = lower_bound(all(xd2),b[i][1])-xd2.begin();
        a[i][0] += 2;
        a[i][1] += 2;
        b[i][0] += 2;
        b[i][1] += 2;
        df |= a[i][0] != b[i][0];
        df |= a[i][1] != b[i][1];
    }
    sort(a,a+n);
    sort(b,b+n);
    /* int it = -1; */
    ll r1[n];
    ll r2[n];
    memset(r1,0,n<<3);
    memset(r2,0,n<<3);
    {
        memset(t1,0,sizeof t1);
        memset(t2,0,sizeof t2);
        FOR(i,0,n){
            upd1(a[i][0],wh[a[i][2]]);
            upd2(a[i][1],wh[a[i][2]]);
        }
        FOR(i,0,n){
            r1[a[i][2]] += query2(a[i][0]-1);
            r1[a[i][2]] += query1(N-1)-query1(a[i][1]);
        }
    }
    {
        memset(t1,0,sizeof t1);
        memset(t2,0,sizeof t2);
        FOR(i,0,n){
            upd1(b[i][0],wh[b[i][2]]);
            upd2(b[i][1],wh[b[i][2]]);
        }
        FOR(i,0,n){
            r2[b[i][2]] += query2(b[i][0]-1);
            r2[b[i][2]] += query1(N-1)-query1(b[i][1]);
        }
    }
    /* ll hh = 0; */
    /* FOR(i,0,n){ */
    /*     if(it < i){ */
    /*         hh = wh[a[i][2]]; */
    /*         it = i; */
    /*     } */
    /*     while(it+1 < n && a[it+1][0] <= a[i][1]){ */
    /*         ++it; */
    /*         hh += wh[a[it][2]]; */
    /*         hh = (hh%B+hh)%B; */
    /*     } */
    /*     r1[a[i][2]] = hh; */
    /*     hh -= wh[a[i][2]]; */
    /*     hh = (hh%B+hh)%B; */
    /* } */
    /* hh = 0; */
    /* it = -1; */
    /* FOR(i,0,n){ */
    /*     if(it < i){ */
    /*         hh = wh[b[i][2]]; */
    /*         it = i; */
    /*     } */
    /*     while(it+1 < n && b[it+1][0] <= b[i][1]){ */
    /*         ++it; */
    /*         hh += wh[b[it][2]]; */
    /*         hh = (hh%B+hh)%B; */
    /*     } */
    /*     r2[b[i][2]] = hh; */
    /*     hh -= wh[b[i][2]]; */
    /*     hh = (hh%B+hh)%B; */
    /* } */
    /* hh = 0; */
    /* it = n; */
    /* for(int i = n-1; i >= 0; --i){ */
    /*     if(it > i){ */
    /*         hh = wh[a[i][2]]; */
    /*         it = i; */
    /*     } */
    /*     while(it-1 >= 0 && a[it-1][1] >= a[i][0]){ */
    /*         ++it; */
    /*         hh += wh[a[it][2]]; */
    /*         hh = (hh%B+hh)%B; */
    /*     } */
    /*     r1[a[i][2]] += hh; */
    /*     hh -= wh[a[i][2]]; */
    /*     hh = (hh%B+hh)%B; */
    /* } */
    bool df2 = 0;
    FOR(i,0,n){
        df2 |= r1[i] != r2[i];
    }
    cout << (df2 ? "NO" : "YES");
}