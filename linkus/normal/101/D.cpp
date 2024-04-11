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

// find any case where order matters?

// oh wait, to jest WEIGHTED, to moze duze zmieniac i guess?

// no tak, 2 leafy gdzie 1 ma mniejszy koszt -> lepiej isc od najtanszych
// krawedzi

// poddrzewo ->
// {ile_nodow, koszt_przejscia, expected value || suma odlegoci na nodach}
// ile_nodow, koszt_przejscia stae
// w jakiej kolejnoci je wybra, aby zminimalizowa expected value?

// koszt_przejscia / ile_nodow minimalizowac?
// each subtree has += suma odl jako:
/* // ile_nodow * suma(koszt_przejscia all poddrzew poza nim) */
/* // -> */
/* // ile_nodow * (suma(koszt_przejscia all poddrzew) - koszt_przejscia jego) */
// -> ile_nodow * suma(koszt_przejscia all POPRZEDZAJCYCH poddrzew (i poza nim))
// posortowa jako na pae? xd
// wsm nie, bo chodzi o relative do siebie samego, a nie do reszty

int n;
vector<pi> adj[N];
ll cnt[N];
ll sum[N];
ll cost[N];

void d1(int v, int p){
    vector<pi> vec;
    FORR(i,adj[v]){
        if(i.e1 == p)
            continue;
        d1(i.e1,v);
        vec.pb({i.e1,i.e2});
        /* sum[v] += i.e2; */
        cnt[v] += cnt[i.e1];
    }
    ++cnt[v];
    // ale co z tym edgem? on na pewno ma te znaczenie
    // doda do sum?
    /* sort(all(vec),[&](pi f, pi s){return (ll)cnt[f.e1] * sum[s.e1] > (ll)cnt[s.e1] * sum[f.e1];}); */
    //
    // EXCHANGE ARGUMENTS???
    //
    sort(all(vec),[&](pi f, pi s){return (ll)cnt[f.e1] * (sum[s.e1]+s.e2) > (ll)cnt[s.e1] * (sum[f.e1]+f.e2);});
    ll add_sum = 0;
    // skup si na porwnaniu dwch subtrees
    // kontrybucja jednego na drugim, poza niezalenymi staymi:
    /* // cnt[s] * (sum[f]+edge_w[f]) */
    // wait, ^^ was bad
    // cnt[s] * 2 * (sum[f]+edge_w[f])
    // ^^ that's correct
    // but isn't it skracalne przed dwie strony anyway?
    // yeah
    whatis(vec)
    FORR(i,vec){
        // singular edge te, ale tylko liczy si raz?
        whatis(add_sum)
        cost[v] += cost[i.e1] + cnt[i.e1] * (add_sum * 2 + i.e2);
        add_sum += i.e2;
        add_sum += sum[i.e1];
    }
    // nie dodaem add_sumu do sym[v] XD
    // sum[v] zawsze 0 by, giga way na 20 penalty
    sum[v] += add_sum;
    whatis(cnt[v])
    whatis(sum[v])
    whatis(cost[v])
    // brutem ez porownanie wsm
}

// NAJS <33333333333333333333333
// EXCHANGE ARGUMENTS IS MY FRIEND NOW

// dopiero WA na test 5 damn, better than expected
// ale zazwyczaj ludzie maj wa na 6 a nie na 5 wic hmm
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    FOR(i,1,n){
        int f,s,t;
        sc(f,s,t);
        --f,--s;
        adj[f].pb({s,t});
        adj[s].pb({f,t});
    }
    d1(0,-1);
    /* cout << 1.0 * cost[0] / n << '\n'; */
    cout << fixed << setprecision(9);
    cout << 1.0 * cost[0] / (n-1) << '\n';
}