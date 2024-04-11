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
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* vector<ll> vec1,vec2; */
set<ll> vec1,vec2;
ll w,m;
int lim;
int mid;
ll table[101];

void rec(int k, ll sum){
    if(k == mid){
        if(sum >= 0)
            vec1.insert(sum);
            /* vec1.pb(sum); */
        return;
    }
    rec(k+1,sum);
    rec(k+1,sum+table[k]);
    rec(k+1,sum-table[k]);
}

void rec2(int k, ll sum){
    if(k == lim){
        if(sum >= 0)
            vec2.insert(sum);
            /* vec2.pb(sum); */
        return;
    }
    rec2(k+1,sum);
    rec2(k+1,sum+table[k]);
    rec2(k+1,sum-table[k]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //up till 2^29
    sc(w,m);
    if(w == 2 || w == 3) REE("YES")
    ll cur = 1;
    int k = 0;
    for(;;){
        if(cur > m)
            break;
        cur *= w;
        ++k;
    }
    table[0] = 1;
    /* ++k; */
    FORE(i,1,k){
        table[i] = table[i-1] * w;
    }
    ++k;
    mid = k >> 1;
    /* whatis(k) */
    /* whatis(mid) */
    lim = k;
    rec(0,0);
    rec2(mid,0);
    /* sort(all(vec1)); */
    /* whatis(vec1) */
    /* whatis(vec2) */
    FORR(x,vec1)
        if(x == m) REE("YES")
    FORR(i,vec2){
        if(i == m) REE("YES")
        ll des = abs(i-m);
        /* if(binary_search(all(vec1),des)) REE("YES") */
        if(vec1.count(des)) REE("YES")
    }
    cout << "NO\n";
}