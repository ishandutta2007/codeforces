#include <stdio.h>
#include <algorithm>
#include <vector>
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

vi adj1[N], adj2[N];
int de2[N];
int stt[N], endt[N];
int p[N][20];
int it1, it2;
int t[N << 1];
int t2[N << 1];
int n;

int query(int l, int r){
    int ret = INF;
    l += n, r += n;
    while(l < r){
        if(l&1)
            // XD, guess it's been a while since I wrote a segment tree.
            /* ret = min(ret,t[l--]); */
            ret = min(ret,t[l++]);
        if(r&1)
            ret = min(ret,t[--r]);
        l >>= 1, r >>= 1;
    }
    return ret;
}

void update(int pos, int val){
    pos += n;
    t[pos] = val;
    pos >>= 1;
    while(pos >= 1){
        t[pos] = min(t[pos << 1], t[(pos << 1) ^ 1]);
        pos >>= 1;
    }
}

int query2(int l, int r){
    int ret = -1;
    l += n, r += n;
    while(l < r){
        if(l&1)
            // Xd v2.
            /* ret = max(ret,t2[l--]); */
            ret = max(ret,t2[l++]);
        if(r&1)
            ret = max(ret,t2[--r]);
        l >>= 1, r >>= 1;
    }
    return ret;
}

void update2(int pos, int val){
    pos += n;
    t2[pos] = val;
    pos >>= 1;
    while(pos >= 1){
        // nice
        /* t2[pos] = max(t[pos << 1], t2[(pos << 1) ^ 1]); */
        t2[pos] = max(t2[pos << 1], t2[(pos << 1) ^ 1]);
        pos >>= 1;
    }
}


int res;
/* vector<pi> vec; // {node, whoreplaced ?? -1} */
/* set<pi> vec; // {node, whoreplaced ?? -1} */
set<int> vec; // node
// int cnt[N], a[N];
int repl[N];
/* int stttov[N]; */
int endttov[N];

void rem(int v){
    /* auto it = vec.lower_bound({v, -1}); // bez przywracania tutaj. */
    /* auto it = vec.lower_bound({v, -1}); // bez przywracania tutaj. */
    vec.erase(v);
    update(stt[v], INF);
    update2(stt[v], 0);
    /* a[v] = -1; */
    /* for(;;){ */
    /*     assert(a[v] == -1); */
    /*     /1* if(a[v] != -1){ *1/ */
    /*     /1*     rem(a[v]); *1/ */
    /*     /1* } *1/ */
    /*     --cnt[v]; */
    /*     if(!v) */
    /*         break; */
    /*     v = p[v][0]; */
    /* } */
}

void add(int v){
    int tmp = query2(0, stt[v]);
    /* whatis(tmp) */
    /* whatis(stt[v]) */
    if(tmp > endt[v]){
        repl[v] = endttov[tmp];
        rem(endttov[tmp]);
    }
    update(stt[v], endt[v]);
    update2(stt[v], endt[v]);
    vec.insert(v);
}

void tryadd(int v){
    /* whatis(v) */
    /* whatis(cnt[v]) */
    // if(!cnt[v])
    //     add(v);
    /* whatis(query(stt[v], n)) */
    /* whatis(endt[v]) */
    /* whatis(stt[v]) */
    /* if(query(stt[v],n) >= 0 && query(stt[v],n) < n) */
    /*     whatis(endttov[query(stt[v], n)]) */
    if(query(stt[v], n) > endt[v])
        add(v);
}

void d1(int v){
    tryadd(v);
    res = max<int>(res, vec.size());
    /* whatis(vec) */
    FORR(i,adj1[v]){
        d1(i);
    }
    /* if(vec.back().e1 == v){ */
    /*     rem(vec.back().e1); */
    /*     if(vec.back().e2 != -1) */
    /*         add(vec.back().e2); */
    /*     vec.pop_back(); */
    /* } */
    /* auto it = vec.lower_bound({v, -1}); */
    auto it = vec.lower_bound(v);
    /* if(it != vec.end() && it->e1 == v){ */
    /*     rem(it->e1); // rem wywala juz z seta, so gotta remember here. */
    /*     int e2 = it->e2; */
    /*     if(e2 != -1) */
    /*         add(e2); // wait, ale co z nodem, ktry on zastpi wczeniej??? */
    // wsm starczyloy ustawienie boola na topie tej funkcji ale ok.
    /* whatis(repl[v]) */
    if(it != vec.end() && *it == v){
        rem(*it); // rem wywala juz z seta, so gotta remember here.
        if(repl[*it] != -1)
            add(repl[*it]);
        /* int e2 = it->e2; */
        /* if(e2 != -1) */
        /*     add(e2); // wait, ale co z nodem, ktry on zastpi wczeniej??? */
            // -> let's actually just remember that in a tablica.
        /* if(it->e2 != -1) */
        /*     add(it->e2); */
        /* vec.erase(it); */
    }
}

void d2(int v){
    FOR(x,1,20){
        p[v][x] = p[p[v][x-1]][x-1];
    }
    stt[v] = it1++;
    FORR(i,adj2[v]){
        de2[i] = de2[v] + 1;
        p[i][0] = v;
        d2(i);
    }
    endt[v] = it2++;
    endttov[endt[v]] = v;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tt;
    sc(tt);
    while(tt--){
        it1 = it2 = 0;
        sc(n);
        res = 0;
        memset(t,127,n<<3);
        memset(t2,0,n<<3);
        FOR(i,0,n){
            adj1[i].clear(), adj2[i].clear();
            repl[i] = -1;
        }
        int p;
        FOR(i,1,n){
            sc(p);
            --p;
            adj1[p].pb(i);
        }
        FOR(i,1,n){
            sc(p);
            --p;
            adj2[p].pb(i);
        }
        d2(0);
        d1(0);
        cout << res << '\n';
    }
}