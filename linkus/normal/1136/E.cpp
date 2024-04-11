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
#define N 100001

/* int t[N*2]; //set, sum */
/* int n; */

/* int querysum(int l, int r){ */
/*     int res = 0; */
/*     for(l+=n, r+=n; l<r; l>>=1, r>>=1){ */
/*         if(l&1) */
/*             res = max(res,t[l++]); */
/*             //res += t[l++]; */
/*         if(r&1) */
/*             res = max(res,t[--r]); */
/*             //res += t[--r]; */
/*     } */
/*     return res; */
/* } */

/* void modifysum(int p, int val){ */
/*     for(t[p += n] = val; p > 1; p>>=1) */
/*         t[p>>1] = max(t[p] , t[p^1]); */
/* } */
ll t[N << 2];
ll lazy[N << 2];

void build(ll v, ll tl, ll tr, ll arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    ll tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = t[v<<1] + t[v<<1|1];
}

void push(ll v, ll tl, ll tr){
    if(lazy[v]){
        ll tm = (tl+tr)>>1;
        t[v<<1] += (tm-tl+1)*lazy[v];
        t[v<<1|1] += (tr-tm)*lazy[v];
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1] += lazy[v];
        lazy[v] = 0;
    }
}

void modify(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r) return;
    if(tl == l && tr == r){
        lazy[v] += val;
        t[v] += val*(tr-tl+1);
        return;
    }
    push(v,tl,tr);
    ll tm = (tl+tr)>>1;
    modify(v << 1,tl,tm,l,min(tm,r),val);
    modify(v << 1 | 1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = t[v<<1] + t[v<<1|1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    /* whatis(mp(tl,tr)) */
    /* whatis(t[v]) */
    if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v];
    }
    push(v,tl,tr);
    ll tm = (tl+tr)>>1;
    return query(v<<1,tl,tm,l,min(tm,r)) + query(v<<1|1,tm+1,tr,max(l,tm+1),r);
}

ll t1[N << 2]; //l
bool mark1[N << 2];

void build1(ll v, ll tl, ll tr, ll *arr){
    if(tl == tr){
        t1[v] = arr[tl];
        return;
    }
    ll tm = (tl+tr)>>1;
    build1(v<<1,tl,tm,arr);
    build1(v<<1|1,tm+1,tr,arr);
    t1[v] = t1[v<<1] + t1[v<<1|1];
}

void push1(ll v, ll tl, ll tr){
    ll tm = (tl+tr)>>1;
    ll setel = t1[v] / (tr-tl+1);
    t1[v<<1] = setel * (tm-tl+1);
    t1[v<<1|1] = setel * (tr-tm);
    mark1[v<<1] = mark1[v<<1|1] = 1;
    mark1[v] = 0;
}

void modify1(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if(l > r) return;
    if(l == tl && r == tr){
        mark1[v] = 1;
        t1[v] = val*(tr-tl+1);
        return;
    }
    if(mark1[v])
        push1(v,tl,tr);
    ll tm = (tl+tr)>>1;
    modify1(v<<1,tl,tm,l,min(tm,r),val);
    modify1(v<<1|1,tm+1,tr,max(l,tm+1),r,val);
    t1[v] = t1[v<<1] + t1[v<<1|1];
}

ll query1(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t1[v];
    }
    if(mark1[v])
        push1(v,tl,tr);
    ll tm = (tl+tr)>>1;
    return query1(v<<1,tl,tm,l,min(tm,r)) + query1(v<<1|1,tm+1,tr,max(l,tm+1),r);
}

/* int t2[N << 2]; //r */
/* bool mark2[N << 2]; */

/* void build2(int v, int tl, int tr, int *arr){ */
/*     if(tl == tr){ */
/*         t2[v] = arr[tl]; */
/*         return; */
/*     } */
/*     int tm = (tl+tr)>>1; */
/*     build2(v<<1,tl,tm,arr); */
/*     build2(v<<1|1,tm+1,tr,arr); */
/*     t2[v] = t2[v<<1] + t2[v<<1|1]; */
/* } */

/* void push2(int v, int tl, int tr){ */
/*     int tm = (tl+tr)>>1; */
/*     int setel = t2[v] / (tr-tl+1); */
/*     t2[v<<1] = setel * (tm-tl+1); */
/*     t2[v<<1|1] = setel * (tr-tm); */
/*     mark2[v<<1] = mark2[v<<1|1] = 1; */
/*     mark2[v] = 0; */
/* } */

/* void modify2(int v, int tl, int tr, int l, int r, int val){ */
/*     if(l > r) return; */
/*     if(l == tl && r == tr){ */
/*         mark2[v] = 1; */
/*         t2[v] = val*(tr-tl+1); */
/*         return; */
/*     } */
/*     if(mark2[v]) */
/*         push2(v,tl,tr); */
/*     int tm = (tl+tr)>>1; */
/*     modify2(v<<1,tl,tm,l,min(tm,r),val); */
/*     modify2(v<<1|1,tm+1,tr,max(l,tm+1),r,val); */
/*     t2[v] = t2[v<<1] + t2[v<<1|1]; */
/* } */

/* int query2(int v, int tl, int tr, int l, int r){ */
/*     if(l > r) return 0; */
/*     if(l == tl && r == tr){ */
/*         return t2[v]; */
/*     } */
/*     if(mark2[v]) */
/*         push2(v,tl,tr); */
/*     int tm = (tl+tr)>>1; */
/*     return query2(v<<1,tl,tm,l,min(tm,r)) + query2(v<<1|1,tm+1,tr,max(l,tm+1),r); */
/* } */

ll tf[N*2]; //fast query on 1 element
ll n;

ll queryf(ll p){
    ll res = 0;
    for(res += tf[p += n]; p > 1; p>>=1)
        res += tf[p >> 1];
    return res;
}

void modifyf(ll l, ll r, ll val){
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1)
            tf[l++] += val;
            /* res = max(res,t[l++]); */
            //res += t[l++];
        if(r&1)
            tf[--r] += val;
            /* res = max(res,t[--r]); */
            //res += t[--r];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    ll a[n];
    GET(a);
    build(1,0,n-1,a);
    ll k[n-1];
    GET(k);
    /* for(int i = n*2-1; i >= n; --i) */
    /*     t[i] = a[i-n]; */
    /* for(int i = n - 1; i > 0; --i) */
    /*     t[i] = t[i*2]+t[i*2|1]; */
    ll l[n],rrr[n];
    FOR(i,0,n)
        l[i] = rrr[i] = i;
    build1(1,0,n-1,l);
    /* build2(1,0,n-1,r); */
    FOR(i,0,n)
        modifyf(i,i+1,a[i]);
    int q;
    sc(q);
    while(q--){
        char c;
        getch(c);
        int l,r;
        sc(l,r);
        --l;
        if(c == '+'){
            int ll = query1(1,0,n-1,l,l);
            /* int rr = query2(1,0,n-1,l,l); */
            int rr = rrr[ll];
            if(ll != l){
                rrr[ll] = l-1;
                /* modify2(1,0,n-1,ll,l-1,l-1); */
            }
            modify(1,0,n-1,l,rr,r);
            modifyf(l,rr+1,r);
            int pos = rr;
            #define lll long long
            lll df = 0;
            /* while(pos+1 < n && ((df = query(1,0,n-1,pos,pos)+k[pos] - query(1,0,n-1,pos+1,pos+1)) > 0)){ */
            while(pos+1 < n && ((df = queryf(pos)+k[pos] - queryf(pos+1)) > 0)){
                /* int nxp = query2(1,0,n-1,pos+1,pos+1); */
                int nxp = rrr[pos+1];
                modify(1,0,n-1,pos+1,nxp,df);
                modifyf(pos+1,nxp+1,df);
                pos = nxp;
            }
            modify1(1,0,n-1,l,pos,l);
            rrr[l] = pos;
            /* modify2(1,0,n-1,l,pos,pos); */
        }
        else{
            cout << query(1,0,n-1,l,r-1) << '\n';
        }
    }
}