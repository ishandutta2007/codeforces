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
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
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

//0/1 Flip or Set modifications, Sum queries

#define MAX 300000
int t[MAX << 2];
bool mark[MAX << 2]; //set
bool flip[MAX << 2]; //flip
int xd = 100000; //compensation

void build(int v, int tl, int tr, int *arr){
    if(tl == tr){
        t[v] = arr[tl];
        return;
    }
    int tm = (tl+tr)>>1;
    build(v<<1,tl,tm,arr);
    build(v<<1|1,tm+1,tr,arr);
    t[v] = t[v<<1] + t[v<<1|1];
}

void flp(int v, int tl, int tr){
    t[v] = (tr-tl+1)-t[v];
    if(!mark[v]){
        flip[v] ^= 1;
    }
}

void push(int v, int tl, int tr){
    int tm = (tl+tr)>>1;
    if(mark[v]){
        assert(!flip[v]);
        int setel = t[v] / (tr-tl+1);
        t[v<<1] = setel * (tm-tl+1);
        t[v<<1|1] = setel * (tr-tm);
        mark[v<<1] = mark[v<<1|1] = 1;
        flip[v<<1] = flip[v<<1|1] = 0;
        mark[v] = 0;
    }
    else if(flip[v]){
        flp(v<<1,tl,tm);
        flp(v<<1|1,tm+1,tr);
        /* t[v<<1] = (tm-tl+1)-t[v<<1]; */
        /* t[v<<1|1] = (tr-tm)-t[v<<1|1]; */
        /* flip[v<<1] ^= 1; */
        /* flip[v<<1|1] ^= 1; */
        flip[v] = 0;
    }
}

void modify(int v, int tl, int tr, int l, int r, int val){ //0,1 -> set values ; -1 -> flip
    if(l > r) return;
    if(r > tr) return;
    if(l < tl) return;
    if(l == tl && r == tr){
        if(val == -1){
            flp(v,tl,tr);
        }
        else{
            mark[v] = 1;
            t[v] = val*(tr-tl+1);
            flip[v] = 0;
        }
        return;
    }
    if(mark[v] || flip[v])
        push(v,tl,tr);
    int tm = (tl+tr)>>1;
    modify(v<<1,tl,tm,l,min(tm,r),val);
    modify(v<<1|1,tm+1,tr,max(l,tm+1),r,val);
    t[v] = t[v<<1] + t[v<<1|1];
}

int query(int v, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    if(mark[v] || flip[v])
        push(v,tl,tr);
    int tm = (tl+tr)>>1;
    return query(v<<1,tl,tm,l,min(tm,r)) + query(v<<1|1,tm+1,tr,max(l,tm+1),r);
}

void mod(int v, int tl, int tr, int l, int r, int val){
    modify(v,tl,tr,l+xd,r+xd,val);
}

int qu(int v, int tl, int tr, int l, int r){
    return query(v,tl,tr,l+xd,r+xd);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    /* int arr[] = {5,-1,32,-6,31,42,3,41,0,-4,44,8}; */
    /* FORR(i,arr) */
    /*     cerr << i << ' '; */
    /* cerr << '\n'; */
    /* int n = sizeof arr / sizeof *arr; */
    /* build(1,0,n-1,arr); */
    int n,q;
    sc(n,q);
    int in[n];
    GET(in);
    int a[200001];
    int N = 200000;
    for(int i = -100000; i <= 100000; ++i){
        a[i+xd] = i < 0;
    }
    build(1,0,200000,a);
    while(q--){
        char c;
        int xd;
        getch(c);
        sc(xd);
        if(c == '>'){
            if(xd >= 0){
                mod(1,0,N,-100000,-xd-1,1);
                mod(1,0,N,xd+1,100000,1);
            }
            else{
                mod(1,0,N,-100000,-abs(xd),1);
                mod(1,0,N,abs(xd),100000,1);
                mod(1,0,N,-abs(xd)+1,abs(xd)-1,-1);
            }
        }
        else{
            if(xd < 0){
                mod(1,0,N,-100000,-abs(xd)-1,0);
            mod(1,0,N,abs(xd)+1,100000,0);
            }
            else{
                mod(1,0,N,-100000,-abs(xd),0);
                mod(1,0,N,abs(xd),100000,0);
                mod(1,0,N,-abs(xd)+1,abs(xd)-1,-1);
            }
        }
    }
    FORR(i,in){
        cout << abs(i) * (qu(1,0,N,i,i) ? -1 : 1) << ' ';
    }
}