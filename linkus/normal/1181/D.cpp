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

class treap{
public:
    class node{
    public:
        int x,y,c; 
        node *l,*r; 
        node(int data=0):x(data),c(0),l(0),r(0){y=((rand()<<15)+rand())%INF;}
    };
    node *root, *null; 
public:
        int sz;
    ll size(){
        return sz;
    }
    treap(){null=new node(); null->l=null->r=null; null->y=INF; root=null; }
    void update(node*&p){ if(p!=null){p->c=p->l->c+p->r->c+1; }}
    void lr(node *&p){ node *q=p->l; p->l=q->r; q->r=p; update(p); update(q); p=q; }
    void rr(node *&p){ node *q=p->r; p->r=q->l; q->l=p; update(p); update(q); p=q; }
    void ins(node *&p, int x){
        if (p==null){ p=new node(x); p->l=p->r=null; p->c=1; } else
        if (x<p->x) { ins(p->l,x); if(p->l->y<p->y) lr(p); } else
                    { ins(p->r,x); if(p->r->y<p->y) rr(p); }
        update(p);
    }
    void del(node *&p, int x){
        if (p==null) return; 
        if (p->x==x) del(p); else
        if (x<p->x) del(p->l,x); else del(p->r,x);
        if (p!=null) update(p);
    }
    void del(node *&p){
        if (p->l==null&&p->r==null) {delete p; p=null; return; }
        if (p->l->y<p->r->y) {lr(p); del(p->r); } else {rr(p); del(p->l); }
        update(p); 
    }
    bool find(node *&p, int x){
        if(p==null) return false; 
        if (x==p->x) return true; 
        if (x<p->x) return find(p->l,x); else return find(p->r,x); 
    }
    int rfs(node *&p, int k){
        if (k<=p->l->c) return rfs(p->l,k); else
        if (k==p->l->c+1) return p->x; else return rfs(p->r,k-p->l->c-1); 
    }
    
    void ins(int x){ ++sz, ins(root,x); }
    void del(int x){ --sz,del(root,x); }
    bool find(int x){ return find(root,x); }
    int rfs(int k){if (k>=1&&k<=root->c) return rfs(root,k); else return -1; }
};

treap st;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    srand(time(0));
    int n,m,q;
    sc(m,n,q);
    int ild[n];
    memset(ild,0,n << 2);
    ll wh;
    FOR(i,0,m){
        sc(wh); --wh;
        ++ild[wh];
    }
    map<int,vi> sp;
    FOR(i,0,n)
        sp[ild[i]].pb(i);
    vector<pair<ll,ll>> qus;
    int ans[q];
    FOR(i,0,q){
        sc(wh);
        qus.pb({wh,i});
    }
    sort(all(qus));
    auto it = qus.begin();
    FORR(i,sp.begin()->e2) st.ins(i);
    ll day = m+1; //rano
    ll linf = 0;
    memset(&linf,127,8);
    auto spit = sp.begin(); //nxt
    ll upl;
    if(sp.size() > 1){
        ++spit;
        upl = (ll)st.size()*(spit->e1-prev(spit)->e1);
    }
    else{
        upl = linf;
    }
    while(it < qus.end()){
        ll dif;
        while((dif = it->e1 - day) >= upl){
            /* whatis(dif) */
            /* whatis(upl) */
            FORR(i,spit->e2)
                st.ins(i);
            day += upl;
            ++spit;
            if(spit != sp.end()){
                upl = (ll)st.size()*(spit->e1-prev(spit)->e1);
            }
            else{
                upl = linf;
            }
        }
        /* whatis(dif) */
        /* whatis(st.size()) */
        /* whatis(dif%st.size()) */
        /* int whel = *st.find_by_order(dif%st.size()); */
        int whel = st.rfs(1+dif%st.size());
        ans[it->e2] = whel;
        ++it;
    }
    FORR(i,ans)
        cout << i+1 << '\n';
}