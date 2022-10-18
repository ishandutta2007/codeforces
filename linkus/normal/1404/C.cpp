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

//Lazy Propagation on Increment Modifications, findmin queries

#define N 500000
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
    if(t[v<<1] < t[v<<1|1]){
        return query(v<<1,tl,tm,l,min(tm,r));
    }
    else{
        return query(v<<1|1,tm+1,tr,max(l,tm+1),r);
    }
}
int tt[N];

//1 INDEXED, increment in function if needed

inline void upd(int pos, int val){ //val is delta
    pos += 2;
    for(;pos <= N-3;pos += pos & (-pos))
            //simply for(;posy <= m;posy += posy & (-posy)) for 2nd dimension
        tt[pos] += val;
}

inline int query(int r){ //[0,r]
    r += 2;
    int ret = 0;
    for(;r > 0;r -= r & (-r))
        ret += tt[r];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    sc(n,q);
    int a[n];
    GET(a);
    // 1 - indexing
    FORR(i,a)
        --i;
    int nwa[n];
    FOR(i,0,n){
        nwa[i] = i - a[i];
    }
    build(1,0,n-1,nwa);
    vi wyw;
    for(;;){
        pi cr = query(1,0,n-1,0,n-1);
        /* whatis(cr) */
        if(cr.e1 > 0){
            break;
        }
        if(cr.e1 < 0){
            modify(1,0,n-1,cr.e2,cr.e2,INF);
        }
        else if(cr.e1 == 0){
            wyw.pb(cr.e2);
            modify(1,0,n-1,cr.e2,cr.e2,INF);
            modify(1,0,n-1,cr.e2+1,n-1,-1);
        }
    }
    /* whatis(wyw) */
    /* whatis(wyw.size()) */
    array<int,3> qus[q];
    FOR(i,0,q){
        sc(qus[i][0],qus[i][1]);
        qus[i][2] = i;
    }
    sort(qus,qus+q);
    int wh[n];
    memset(wh,-1,n<<2);
    FOR(i,0,wyw.size()){
        wh[wyw[i]] = i;
        upd(wyw[i],1);
    }
    int ans[q];
    int it = 0;
    int rr = wyw.size()-1;
    FOR(i,0,q){
        while(qus[i][0] > it){
            ++it;
            if(wh[it-1] != -1){
                int nrr = min(rr,wh[it-1]-1);
                if(nrr < rr){
                    for(int x = rr; x > nrr; --x){
                        upd(wyw[x],-1);
                    }
                    rr = nrr;
                }
            }
        }
        ans[qus[i][2]] = query(n-qus[i][1]-1);
    }
    /* int x,y; */
    /* while(q--){ */
    /*     sc(x,y); */
    /*     int ret = 0; */
    /*     // XD SUBMITOWANIE tego...... */
    /*     // ale debilem jestem */
    /*     /1* FORR(i,wyw){ *1/ */
    /*     /1*     if(i < x) break; *1/ */
    /*     /1*     if(i >= n-y) continue; *1/ */
    /*     /1*     ++ret; *1/ */
    /*     /1* } *1/ */
    /*     /1* cout << ret << '\n'; *1/ */
    /*     FORR(i,wyw){ */
    /*         if(i < x) break; */
    /*         if(i >= n-y) continue; */
    /*         ++ret; */
    /*     } */
    /*     cout << ret << '\n'; */
    /* } */
    FORR(i,ans)
        cout << i << '\n';
}