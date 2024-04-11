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
#ifdef LOCAL
#define whatis(x) cerr << #x << " is " << (x) << endl;
#else
#define whatis(x) if(0) cerr << #x << " is " << (x) << endl;
#endif

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, array<T,3> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
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
    ll n;
    sc(n);
    pair<ll,ll> a[n];
    ll aor[n];
    FOR(i,0,n){
        sc(a[i].e1), a[i].e2 = i;
        aor[i] = a[i].e1;
    }
    ll b[n];
    GET(b);
    sort(b,b+n);
    sort(a,a+n);
    ll sum = 0;
    FORR(i,a) sum += i.e1;
    FORR(i,b) sum -= i;
    if(sum) REE("NO")
    vector<array<ll,3>> ops;
    set<pair<ll,ll>> mn; //{val,pos}
    vector<pair<ll,ll>> more; //{val,pos}
    FOR(i,0,n){
        if(a[i].e1 > b[i]){
            more.pb({a[i].e1,i});
        }
        else if(a[i].e1 < b[i]){
            mn.insert({a[i].e1,i});
        }
    }
    /* sort(all(more),greater<pair<ll,ll>>()); */
    sort(all(more));
    FORR(i,more){
        while(a[i.e2].e1 != b[i.e2]){
            whatis(a[i.e2])
            whatis(b[i.e2])
            auto it = mn.lower_bound({a[i.e2].e1-1,0});
            if(it == mn.begin()){
                REE("NO")
            }
            --it;
            whatis(*it)
            ll dood = min({a[i.e2].e1-b[i.e2],b[it->e2]-a[it->e2].e1,(a[i.e2].e1-a[it->e2].e1)/2});
            ops.pb({a[it->e2].e2+1,a[i.e2].e2+1,dood});
            assert(dood);
            a[i.e2].e1 -= dood;
            a[it->e2].e1 += dood;
            pair<ll,ll> pp = *it;
            pp.e1 = a[pp.e2].e1;
            mn.erase(it);
            if(a[pp.e2].e1 != b[pp.e2])
                mn.insert(pp);
        }
    }
    cout << "YES\n";
    cout << ops.size() << '\n';
    FORR(i,ops){
        FORR(x,i)
            cout << x << ' ';
        cout << '\n';
    }
}