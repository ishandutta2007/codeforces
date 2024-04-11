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
LL arr[510][510], ans;

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){
            scanf("%lld", &arr[i][j]);
        }
    }
    ans=LLINF;
    ans=min(ans, arr[1][n+1]);
    ans=min(ans, arr[1][2*n]);
    ans=min(ans, arr[n][n+1]);
    ans=min(ans, arr[n][2*n]);
    ans=min(ans, arr[n+1][1]);
    ans=min(ans, arr[2*n][1]);
    ans=min(ans, arr[n+1][n]);
    ans=min(ans, arr[2*n][n]);
    for(int i=n+1; i<=2*n; i++){
        for(int j=n+1; j<=2*n; j++)ans+=arr[i][j];
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}