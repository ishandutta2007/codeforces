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
#define N 200000

int t[32][N*2];
int t2[32][N*2];
int n;

int query(int xd, int l, int r){
    int res = -INF;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            res = max(res,t[xd][l++]);
            //res += t[l++];
        if(r&1)
            res = max(res,t[xd][--r]);
            //res += t[--r];
    }
    return res;
}

void modify(int xd, int p, int val){
    for(t[xd][p += n] = val; p > 1; p>>=1)
        t[xd][p>>1] = max(t[xd][p] , t[xd][p^1]);
}

int query2(int xd, int l, int r){
    int res = INF;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            res = min(res,t2[xd][l++]);
            //res += t2[l++];
        if(r&1)
            res = min(res,t2[xd][--r]);
            //res += t2[--r];
    }
    return res;
}

void modify2(int xd, int p, int val){
    for(t2[xd][p += n] = val; p > 1; p>>=1)
        t2[xd][p>>1] = min(t2[xd][p] , t2[xd][p^1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int k;
    sc(n,k);
    int km = 1 << k;
    int tmp;
    FOR(i,0,n){
        int a[k];
        GET(a);
        FOR(c,0,km){
            int ss = 0;
            FOR(x,0,k){
                if(c & (1 << x))
                    ss += a[x];
                else
                    ss -= a[x];
            }
            t[c][n+i] = ss;
            t2[c][n+i] = ss;
        }
    }
    FOR(xd,0,km){
    for(int i = n - 1; i > 0; --i)
        t[xd][i] = max(t[xd][i*2] , t[xd][i*2|1]);
    for(int i = n - 1; i > 0; --i)
        t2[xd][i] = min(t2[xd][i*2] , t2[xd][i*2|1]);
    }
    int q;
    sc(q);
    int tt;
    while(q--){
        sc(tt);
        if(tt == 1){
            int wh;
            sc(wh);
            --wh;
            int a[k];
            GET(a);
            FOR(i,0,km){
                int ss = 0;
                FOR(x,0,k){
                    if(i & (1 << x))
                        ss += a[x];
                    else
                        ss -= a[x];
                }
                modify(i,wh,ss);
                modify2(i,wh,ss);
            }
        }
        else{
            int l,r;
            sc(l,r);
            --l;
            int anss = 0;
            FOR(i,0,km){
                int mx = query(i,l,r);
                int mn = query2(i,l,r);
                anss = max(anss,mx-mn);
            }
            cout << anss << '\n';
        }
    }

}