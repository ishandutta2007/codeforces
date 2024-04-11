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

int n, deg[100010];
LL ans;
pli w[100010];
void solve(){
    scanf("%d", &n);
    ans=0;
    for(int i=1; i<=n; i++){
        scanf("%lld", &w[i].F);
        w[i].S=i;
        ans+=w[i].F;
    }
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    sort(w+1, w+n+1, greater<pli>());
    printf("%lld ", ans);
    int pv=1;
    for(int i=1; i<n-1; i++){
        for(; pv<=n; pv++){
            if(deg[w[pv].S]>1)break;
        }
        ans+=w[pv].F;
        deg[w[pv].S]--;
        printf("%lld ", ans);
    }
    puts("");
    for(int i=1; i<=n; i++)deg[i]=0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}