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
#define N 1000001

/* int t[N]; */
/* inline void upd(int pos, int val){ //val is delta */
/*     for(;pos <= 1000000;pos += pos & (-pos)) */
/*             //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension */
/*         t[pos] += val; */
/* } */

/* inline int query(int r){ //[0,r] */
/*     int ret = 0; */
/*     for(;r > 0;r -= r & (-r)) */
/*         ret += t[r]; */
/*     return ret; */
/* } */
int t[N << 2];
int lazy[N << 2];

void build(int v, int tl, int tr, int arr[]){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    lazy[v] = 0;
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = min(t[v<<1] , t[v<<1|1]);
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
    t[v] = min(t[v<<1],t[v<<1|1]);
}

//rightmost negative
pair<int,int> query(int v, int tl, int tr, int l, int r){
    if(l > r) return {0x7f7f7f7f,0x7f7f7f7f};
    /* if(t[v]){ */
    /*     return {0x7f7f7f7f,0x7f7f7f7f}; */
    /* } */
    if(tl == l && tr == r && tr == tl){
        return {t[v],tl};
        /* if(t[v]){ */
        /*     return {0x7f7f7f7f,1}; */
        /* } */
        /* return {t[v],v}; */
    }
    push(v);
    int tm = (tl+tr)>>1;
    /* if(t[v<<1] < t[v<<1|1]){ */
    if(t[v<<1|1] < 0){
        return query(v<<1|1,tm+1,tr,max(l,tm+1),r);
    }
    else if(t[v<<1] < 0){
        return query(v<<1,tl,tm,l,min(tm,r));
    }
    else{
        return {0x7f7f7f7f,0x7f7f7f7f};
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    sc(n,m);
    /* ordered_set<pi> a,b; */
    /* int mxs = max(n,m); */
    int va[n], vb[m];
    static int aa[N];
    GET(va);
    GET(vb);
    build(1,0,1e6,aa);
    FOR(i,0,n){
        /* upd(va[i],1); */
        /* --aa[va[i]]; */
        /* a.insert({va[i],i}); */
        modify(1,0,1e6,0,va[i],-1);
    }
    FOR(i,0,m){
        /* upd(vb[i],-1); */
        /* ++aa[vb[i]]; */
        modify(1,0,1e6,0,vb[i],1);
    }
    /* int xd = 0; */
    /* FOR(i,n,mxs) */
    /*     a.insert({-1,-1-(++xd)}); */
    /* FOR(i,m,mxs) */
    /*     b.insert({-1,-1-(++xd)}); */
    int q;
    sc(q);
    while(q--){
        /* whatis("a") */
        /* FORR(i,a) */
        /*     cout << i << ' '; */
        /* cout << endl; */
        /* cout << endl; */
        /* whatis("b") */
        /* FORR(i,b) */
        /*     cout << i << ' '; */
        /* cout << endl; */
        /* cout << endl; */
        int typ,ind,v;
        sc(typ);
        sc(ind);
        sc(v);
        --ind;
        if(typ == 1){
            /* upd(va[ind],-1); */
            modify(1,0,1e6,0,va[ind],1);
            va[ind] = v;
            modify(1,0,1e6,0,va[ind],-1);
            /* upd(va[ind],1); */
            /* auto it = a.erase({va[ind],ind}); */
            /* a.insert({v,ind}); */
            /* va[ind] = v; */
        }
        else{
            /* upd(vb[ind],1); */
            modify(1,0,1e6,0,vb[ind],-1);
            vb[ind] = v;
            /* upd(vb[ind],-1); */
            modify(1,0,1e6,0,vb[ind],1);
            /* auto it = b.erase({vb[ind],ind}); */
            /* /1* whatis(mp(v,ind)) *1/ */
            /* b.insert({v,ind}); */
            /* vb[ind] = v; */
        }
        int ans = -1;
        pi xd = query(1,0,1e6,0,1e6);
        /* FOR(i,0,10){ */
        /*     cout << "i: " << */ 
        /* } */
        if(xd.e1 < 0){
            ans = xd.e2;
        }
        /* int ans = -1; */
        /* int low = 1, high = 1000000, mid; */
        /* while(low <= high){ */
        /*     mid = low+(high-low)/2; */
        /*     if(ok(mid)){ */
        /*         ans = mid; */
        /*         /1* high = mid-1; //Jak najmniejsza *1/ */
        /*         low = mid+1; //Jak najwiksza */
        /*     } */
        /*     else{ */
        /*         /1* low = mid+1; //Jak najmniejsza *1/ */
        /*         high = mid-1; //Jak najwiksza */
        /*     } */
        /* } */
        /* auto it1 = a.begin(), it2 = b.begin(); */
        /* int ans = -1; */
        /* while(it1 != a.end()){ */
        /*     /1* whatis(*it1) *1/ */
        /*     /1* whatis(*it2) *1/ */
        /*     if(it1->e1 > it2->e1){ */
        /*         ans = it1->e1; */
        /*     } */
        /*     ++it1,++it2; */
        /* } */
        cout << ans << '\n';
    }
}