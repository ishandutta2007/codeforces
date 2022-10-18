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

vi adj[N];
ll a[N];
int leafd[N];
ll xr[N];
ll resa[N];

int mex(vi &vec){
    sort(all(vec));
    vec.erase(unique(all(vec)),vec.end());
    if(vec.empty() || vec[0] != 0)
        return 0;
    FOR(i,1,vec.size()){
        if(vec[i] != vec[i-1] + 1){
            return vec[i-1] + 1;
        }
    }
    return vec.back() + 1;
}

void d1(int v){
    /* leafd[v] = 0; */
    /* FORR(i,adj[v]){ */
    /*     /1* d1(i); *1/ */
    /*     if(leafd[i] == -1){ */
    /*         d1(i); */
    /*     } */
    /*     leafd[v] = max(leafd[v], leafd[i] + 1); */
    /* } */
    /* xr[leafd[v]] ^= a[v]; */
    vi vec;
    FORR(i,adj[v]){
        /* d1(i); */
        if(leafd[i] == -1){
            d1(i);
        }
        vec.push_back(leafd[i]);
        /* leafd[v] = max(leafd[v], leafd[i] + 1); */
    }
    leafd[v] = mex(vec);
    xr[leafd[v]] ^= a[v];
}

// that can be reached from v using a single road omg xd
// passes 6 cases while having thought that just any reachability is fine

// fix -> mex adj leafd (czy ich mexw wsm?)
// mexw i guess
// -> WA8 lol
// no tak, bo nie zaktualizowaem d2()
// chocia wait, w tym tecie:
// 3 0
// 4 1 4
// nie powinno to mieznaczenia right?
/* void d2(int v){ */
void d2(int v, bool nxt = 1){
    // wait, przecie tutaj jak jestem rootem to nie mog tego zwiksza xd
    // (musi by zmniejszone exactly)
    // -> choose taki spord all rootw o (w sumie dowolnym, niekoniecznie
    // najwyszym?) leafd, aby dao si go zmniejszyeby xor na tej pozycji
    // by 0
    // w sumie musi by z max leafd nvmind
    // no i fix e tylko raz id do adj typw
    // no i do all adj, nie tylko do jednego pathu

    // -> na pae check all z max leafd czy po zmianie jest mniejsze, musi
    // jaki taki by def
    resa[v] = a[v] ^ xr[leafd[v]];
    // update needed, bo moe by wiele o rwnym leafd wrd adj childw
    xr[leafd[v]] ^= a[v] ^ resa[v];
    // zawsze 0 wsm
    assert(xr[leafd[v]] == 0);
    /* whatis(v) */
    /* whatis(leafd[v]) */
    /* if(leafd[v] == 0) */
    if(!nxt)
        return;
    /* pi mx = {-1,-1}; */
    FORR(i,adj[v]){
        d2(i,0);
        /* mx = max(mx, mp(leafd[i],i)); */
    }
    /* d2(mx.e2); */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    FOR(i,0,n)
        sc(a[i]);
    int f,s;
    FOR(i,0,m){
        sc(f,s);
        --f,--s;
        adj[f].pb(s);
        // lol
        /* adj[s].pb(f); */
    }
    memset(leafd,-1,n << 2);
    FOR(i,0,n){
        if(leafd[i] == -1){
            d1(i);
        }
    }
    int tp = -1;
    FOR(i,0,n){
        if(xr[i]){
            tp = i;
        }
    }
    if(tp == -1){
        cout << "LOSE\n";
    }
    else{
        cout << "WIN\n";
        memcpy(resa,a,n << 3);
        FOR(i,0,n){
            /* if(leafd[i] == tp){ */
            /*     tp = i; */
            /*     break; */
            /* } */
            // musi by zmniejszone
            if(leafd[i] == tp && ((a[i] ^ xr[tp]) < a[i])){
                tp = i;
                break;
            }
            // -> WA14 damnn
            // wait, bo wrd childw tego roota moe by wiele nodw o rwnym
            // leafd[] -> albo check czy ju nie processowaem jakiego, albo
            // updatowanie xr[] po prostu doda -> git surely
        }
        d2(tp);
        FOR(i,0,n){
            cout << resa[i] << ' ';
        }
        cout << '\n';
    }
    // WA7
}