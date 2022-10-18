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
#define N 300000

int q;
/* int lnk[N], sz[N], ilex[N], iley[N]; */
int lnk[N << 1], ilex[N << 1], iley[N << 1];

int find(int x){
    while(x != lnk[x]) x = lnk[x];
    return x;
}

int sz(int a){
    return ilex[a] + iley[a];
}

struct upd {
    int whb;
    int whlnkb;
    int wha;
    int whx;
    int why;
};

vector<upd> st;
ll res;
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return; // quite key.
    bool hasx = ilex[a] != 0;
    bool hasy = iley[b] != 0;
    if(sz(a) < sz(b))
        swap(a,b);
    int xdf = ilex[b];
    int ydf = iley[b];
    if(!hasx){
        ++xdf;
    }
    if(!hasy){
        ++ydf;
    }
    st.push_back({b, lnk[b], a, ilex[a], iley[a]});
    res -= 1ll * ilex[a] * iley[a];
    res -= 1ll * ilex[b] * iley[b];
    ilex[a] += xdf;
    iley[a] += ydf;
    lnk[b] = a;
    res += 1ll * ilex[a] * iley[a];
}

vector<pi> t[N << 2];
void modify(int v, int tl, int tr, int l, int r, pair<int,int> val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v].push_back(val);
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm), val);
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
}

ll ans[N];

void dfs(int v, int tl, int tr){
    ll origres = res;
    int origsz = st.size();
    FORR(i,t[v]){
        unite(i.e1, i.e2 + N);
    }
    if(tl == tr){
        ans[tl] = res;
    }
    else{
        int tm = (tl + tr) >> 1;
        dfs(v << 1, tl, tm);
        dfs(v << 1 | 1, tm + 1, tr);
    }
    /* FORR(i,t[v]){ */
    int ilerem = st.size() - origsz;
    FOR(i,0,ilerem){
        auto [whb,whlnkb,wha,whax,whay] = st.back();
        lnk[whb] = whlnkb;
        ilex[wha] = whax;
        iley[wha] = whay;
        st.pop_back();
    }
    res = origres;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(q);
    map<pi, int> wh;
    /* FOR(i,0,N) */
    FOR(i,0,N << 1)
        lnk[i] = i;
    FOR(i,0,q){
        int f,s;
        sc(f,s);
        --f,--s;
        if(wh.count({f,s})){
            modify(1,0,q-1,wh[{f,s}],i-1,{f,s});
            wh.erase({f,s});
        }
        else{
            wh[{f,s}] = i;
        }
    }
    FORR(i,wh){
        modify(1,0,q-1,i.e2,q-1,i.e1);
    }
    dfs(1,0,q-1);
    FOR(i,0,q)
        cout << ans[i] << ' ';
    cout << '\n';
}