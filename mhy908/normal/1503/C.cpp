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

int n;
pll arr[100010];
LL ans, dp[100010];

struct SEG{
    LL tree[400010];
    void upd(int point, int s, int e, int a, int b, LL val){
        if(e<a||s>b)return;
        if(a<=s&&e<=b){
            tree[point]=min(tree[point], val);
            return;
        }
        upd(point*2, s, (s+e)/2, a, b, val);
        upd(point*2+1, (s+e)/2+1, e, a, b, val);
    }
    LL query(int point, int s, int e, int num){
        if(s==e)return tree[point];
        LL ret=tree[point];
        if(num<=(s+e)/2)ret=min(ret, query(point*2, s, (s+e)/2, num));
        else ret=min(ret, query(point*2+1, (s+e)/2+1, e, num));
        return ret;
    }
    SEG(){
        for(int i=1; i<=400000; i++)tree[i]=LLINF;
    }
}seg1, seg2;

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld %lld", &arr[i].F, &arr[i].S);
        ans+=arr[i].S;
    }
    sort(arr+1, arr+n+1);
    seg1.upd(1, 1, n, 1, 1, 0ll);
    for(int i=1; i<=n; i++){
        dp[i]=min(seg1.query(1, 1, n, i), seg2.query(1, 1, n, i)+arr[i].F);
        int l=i, r=n;
        while(l<r){
            int mid=(l+r)/2+1;
            if(arr[mid].F>arr[i].F+arr[i].S)r=mid-1;
            else l=mid;
        }
        seg1.upd(1, 1, n, i, l, dp[i]);
        seg2.upd(1, 1, n, l+1, n, dp[i]-arr[i].F-arr[i].S);
    }
    printf("%lld", ans+dp[n]);
}