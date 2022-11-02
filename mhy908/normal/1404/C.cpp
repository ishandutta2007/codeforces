#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n, q, arr[300010], ac[300010], dp[300010];
struct PST{
    struct NODE{
        NODE *l, *r;
        int sum;
        NODE(){l=r=0; sum=0;}
    }*rt[300010];
    int re;
    void init(NODE *nd, int s, int e){
        if(s==e)return;
        nd->l=new NODE();
        nd->r=new NODE();
        init(nd->l, s, (s+e)/2);
        init(nd->r, (s+e)/2+1, e);
    }
    void init_pst(){
        rt[0]=new NODE();
        init(rt[0], 0, n);
    }
    void upd(NODE *prv, NODE *nw, int s, int e, int num){
        if(s==e){
            nw->sum=prv->sum+1;
            return;
        }
        if(num<=(s+e)/2){
            nw->l=new NODE();
            nw->r=prv->r;
            upd(prv->l, nw->l, s, (s+e)/2, num);
        }
        else{
            nw->l=prv->l;
            nw->r=new NODE();
            upd(prv->r, nw->r, (s+e)/2+1, e, num);
        }
        nw->sum=nw->l->sum+nw->r->sum;
    }
    void upd(int num){
        rt[++re]=new NODE();
        upd(rt[re-1], rt[re], 0, n, num);
    }
    int query(NODE *nd, int s, int e, int a, int b){
        if(a<=s&&e<=b)return nd->sum;
        if(e<a||s>b)return 0;
        return query(nd->l, s, (s+e)/2, a, b)+query(nd->r, (s+e)/2+1, e, a, b);
    }
    int query(int lv, int a, int b){
        return query(rt[lv], 0, n, a, b);
    }
}pst;

int ans[300010];
vector<pii> pnt[300010], upd[300010];
struct FENWICK{
    int tree[300010];
    int sum(int i){
        int ans=0;
        for(; i; i-=(i&-i))ans+=tree[i];
        return ans;
    }
    void update(int i, int num){
        for(; i<=300000; i+=(i&-i))tree[i]+=num;
    }
}fen;

int main(){
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        ac[i]=i-arr[i];
        if(ac[i]<0)ac[i]=n+1;
    }
    for(int i=1; i<=q; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        pnt[1+x].eb(n-y, i);
    }
    pst.init_pst();
    for(int i=1; i<=n; i++){
        int l=0, r=i;
        while(l<r){
            int mid=(l+r)/2+1;
            if(pst.query(i-1, mid, n)-pst.query(mid-1, mid, n)>=ac[i])l=mid;
            else r=mid-1;
        }
        upd[0].eb(i, 1);
        upd[l+1].eb(i, -1);
        pst.upd(l);
    }
    for(int i=0; i<=n; i++){
        for(auto j:upd[i])fen.update(j.F, j.S);
        for(auto j:pnt[i])ans[j.S]=fen.sum(j.F);
    }
    for(int i=1; i<=q; i++)printf("%d\n", ans[i]);
}