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
#define N 800001

//Lazy Propagation on Increment Modifications, Max queries

int t[N << 2];
int lazy[N << 2];

void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = max(t[v<<1] , t[v<<1|1]);
}

void push(int v){
    if(lazy[v]){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        t[v<<1] += lazy[v];
        t[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int inc){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += inc;
        lazy[v] += inc;
        return;
    }
    push(v);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),inc);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,inc);
    t[v] = max(t[v<<1],t[v<<1|1]);
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return -0x7f7f7f7f;
    if(tl == l && tr == r){
        return t[v];
    }
    push(v);
    int tm = (tl+tr)>>1;
    return max(
    query(v<<1,tl,tm,l,min(tm,r)),
    query(v<<1|1,tm+1,tr,max(l,tm+1),r)
    );
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    sc(n,m,k);
    vi at,df;
    pi wep[n];
    pi shl[m];
    FORR(i,wep){
        sc(i.e1,i.e2);
        at.pb(i.e1);
    }
    FORR(i,shl){
        sc(i.e1,i.e2);
        df.pb(i.e1);
    }
    array<int,3> mon[k];
    FORR(i,mon){
        GET(i);
        ++i[0],++i[1];
        at.pb(i[0]);
        df.pb(i[1]);
    }
    sort(all(at));
    sort(all(df));
    at.erase(unique(all(at)),at.end());
    df.erase(unique(all(df)),df.end());
    FORR(i,wep){
        i.e1 = lower_bound(all(at),i.e1)-at.begin();
    }
    FORR(i,shl){
        i.e1 = lower_bound(all(df),i.e1)-df.begin();
    }
    FORR(i,mon){
        i[0] = lower_bound(all(at),i[0])-at.begin();
        i[1] = lower_bound(all(df),i[1])-df.begin();
    }
    sort(wep,wep+n);
    sort(shl,shl+m);
    sort(mon,mon+k);
    int xx = at.size();
    int yy = df.size();
    int arr[yy];
    int it = m-1;
    /* FOR(i,0,yy){ */
    int cr = INF;
    for(int i = yy-1; i >= 0; --i){
        /* whatis(it) */
        /* whatis(shl[it]) */
        while(it >= 0 && shl[it].e1 >= i){
            cr = min(cr,shl[it].e2);
            --it;
        }
        arr[i] = -cr;
        /* arr[i] = (it == m ? -0x7f7f7f7f : -shl[it].e2); */
        /* whatis(i) */
        /* whatis(arr[i]) */
    }
    build(1,0,yy-1,arr);
    int ans = -INF;
    it = 0;
    /* whatis(query(1,0,yy-1,0,yy-1)) */
    FORR(i,wep){
        while(it < k && mon[it][0] <= i.e1){
            modify(1,0,yy-1,mon[it][1],yy-1,mon[it][2]);
            ++it;
        }
        /* whatis(i) */
        /* whatis(query(1,0,yy-1,0,yy-1)) */
        ans = max(ans,query(1,0,yy-1,0,yy-1)-i.e2);
    }
    cout << ans << '\n';
}