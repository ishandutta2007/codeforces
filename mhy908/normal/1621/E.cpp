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

int n, m;
LL arr[100010];

vector<LL> vc[100010];
LL sum[100010];
pii edge[100010];
int redge[100010];

struct SEG{
    int tree[400010];
    void init(int point, int s, int e){
        tree[point]=INF;
        if(s==e)return;
        init(point*2, s, (s+e)/2);
        init(point*2+1, (s+e)/2+1, e);
    }
    void upd(int point, int s, int e, int num, int val){
        if(s==e){
            tree[point]=val;
            return;
        }
        if(num<=(s+e)/2)upd(point*2, s, (s+e)/2, num, val);
        else upd(point*2+1, (s+e)/2+1, e, num, val);
        tree[point]=min(tree[point*2], tree[point*2+1]);
    }
    int query(int point, int s, int e, int a, int b){
        if(e<a||s>b)return INF;
        if(a<=s&&e<=b)return tree[point];
        return min(query(point*2, s, (s+e)/2, a, b), query(point*2+1, (s+e)/2+1, e, a, b));
    }
}seg;

int get_num(LL sum, int sz){
    int l=1, r=n+1;
    while(l<r){
        int mid=(l+r)/2;
        if(sum<=arr[mid]*(LL)sz)r=mid;
        else l=mid+1;
    }
    return n-l+1;
}

bool query(int num, int val){
    int aval=upper_bound(edge+1, edge+m+1, mp(val-1, INF))-edge;
    int bval=redge[num];
    if(aval<=bval){
        if(val-aval<0)return false;
        if(seg.query(1, 1, m, aval, bval-1)-1<0)return false;
        if(seg.query(1, 1, m, 1, aval-1)<0)return false;
        if(seg.query(1, 1, m, bval+1, m)<0)return false;
        return true;
    }
    else{
        if(val-aval+1<0)return false;
        if(seg.query(1, 1, m, bval+1, aval-1)+1<0)return false;
        if(seg.query(1, 1, m, 1, bval-1)<0)return false;
        if(seg.query(1, 1, m, aval, m)<0)return false;
        return true;
    }
}

void solve(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)scanf("%lld", &arr[i]);
    sort(arr+1, arr+n+1);
    for(int i=1; i<=m; i++){
        int sz;
        scanf("%d", &sz);
        for(int j=1; j<=sz; j++){
            LL a;
            scanf("%lld", &a);
            vc[i].eb(a);
            sum[i]+=a;
        }
        edge[i]=mp(get_num(sum[i], sz), i);
    }
    sort(edge+1, edge+m+1);
    seg.init(1, 1, m);
    for(int i=1; i<=m; i++){
        redge[edge[i].S]=i;
        seg.upd(1, 1, m, i, edge[i].F-i);
    }
    for(int i=1; i<=m; i++){
        for(auto j:vc[i]){
            int poss=get_num(sum[i]-j, vc[i].size()-1);
            if(query(i, poss))printf("1");
            else printf("0");
        }
    }
    puts("");
    for(int i=1; i<=m; i++){
        vc[i].clear();
        sum[i]=0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}