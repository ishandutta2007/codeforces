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
template<class T> ostream& operator<<(ostream &os, deque<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* const int N = 3e5+2; //Sometimes must be scaled into a power of 2!!!!!!!!!!!!! */
/* ll t[2][N*2]; // 0 -> pomidzy nisze; 1 -> pomidzy wysze */
/* ll n; */

/* ll query(ll l, ll r, int wh){ */
/*     /1* ll res = 0; *1/ // giga bania */
/*     ll res = INF; */
/*     for(l+=n, r+=n; l<r; l>>=1, r>>=1){ */
/*         if(l&1) */
/*             res = min(res,t[wh][l++]); */
/*             //res += t[l++]; */
/*         if(r&1) */
/*             res = min(res,t[wh][--r]); */
/*             //res += t[--r]; */
/*     } */
/*     return res; */
/* } */

/* void modify(ll p, ll val, int wh){ */
/*     for(t[wh][p += n] = val; p > 1; p>>=1) */
/*         t[wh][p>>1] = min(t[wh][p] , t[wh][p^1]); */
/* } */


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    int a[n];
    GET(a);
    deque<pi> prelower; //{val,pos}
    deque<pi> prehigher; //{val,pos}
    int flower[n], fhigher[n];
    /* memset(t,127,sizeof t); */
    FOR(i,0,n){
        // I don't need any lower_bounds here...
        /* auto it = upper_bound(all(prelower),pi(a[i],INF)); */
        /* if(it == prelower.begin()){ */
        /*     flower[i] = 0; */
        /* } */
        /* else{ */
        /*     --it; */
        /*     flower[i] = it->e2; */
        /* } */
        /* it = prelower.insert({a[i],i}).e1; */
        while(prelower.size() && prelower.back().e1 >= a[i])
            prelower.pop_back();
        if(prelower.size())
            flower[i] = prelower.back().e2;
        else
            flower[i] = 0;
        prelower.push_back({a[i],i});
        /* it = lower_bound(all(prehigher),pi(a[i],0)); */
        /* if(it == prehigher.end()){ */
        /*     fhigher[i] = 0; */
        /* } */
        /* else{ */
        /*     fhigher[i] = it->e2; */
        /* } */
        while(prehigher.size() && prehigher.front().e1 <= a[i])
            prehigher.pop_front();
        if(prehigher.size())
            fhigher[i] = prehigher.front().e2;
        else
            fhigher[i] = 0;
        prehigher.push_front({a[i],i});
        /* whatis(i) */
        /* whatis(fhigher[i]) */
        /* whatis(flower[i]) */
    }
    prelower.clear();
    prehigher.clear();
    int res[n];
    FOR(i,0,n){
        // here, I also don't need any segment tree.
        /* int cr,cr2; */
        /* if(!i){ */
        /*     cr = cr2 = 0; */
        /* } */
        /* else{ */
        /*     cr = query(fhigher[i],i,0)+1; */
        /*     cr2 = query(flower[i],i,1)+1; */
        /* } */
        /* cr = min(cr,cr2); */
        /* whatis(i) */
        /* whatis(query(0,1,0)) */
        /* whatis(prelower) */
        /* whatis(prehigher) */
        /* whatis(cr) */
        /* modify(i,cr,0); */
        /* modify(i,cr,1); */
        res[i] = INF;
        while(prelower.size() && prelower.back().e1 > a[i]){
            /* modify(prelower.back().e2, INF, 0); */
            /* modify(prelower.back().e2, INF, 1); */
            res[i] = min(res[i], res[prelower.back().e2]+1);
            prelower.pop_back();
        }
        if(prelower.size()){
            res[i] = min(res[i], res[prelower.back().e2]+1);
            if(prelower.back().e1 == a[i])
                prelower.pop_back();
        }
        prelower.push_back({a[i],i});
        while(prehigher.size() && prehigher.front().e1 < a[i]){
            /* modify(prehigher.back().e2, INF, 1); */
            /* modify(prehigher.front().e2, INF, 1); */
            /* modify(prehigher.front().e2, INF, 0); */
            res[i] = min(res[i], res[prehigher.front().e2]+1);
            prehigher.pop_front();
        }
        if(prehigher.size()){
            res[i] = min(res[i], res[prehigher.front().e2]+1);
            if(prehigher.front().e1 == a[i])
                prehigher.pop_front();
        }
        prehigher.push_front({a[i],i});
        if(!i)
            res[i] = 0;
        /* modify(i,cr,0); */
        /* modify(i,cr,1); */
    }
    cout << res[n-1] << '\n';
    /* cout << query(n-1,n,0) << '\n'; // wh doesn't matter here */
}