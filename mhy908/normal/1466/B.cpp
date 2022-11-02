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

int n, arr[100010], ans;
void solve(){
    scanf("%d", &n);
    ans=0;
    for(int i=1; i<=n; i++)scanf("%d", &arr[i]);
    sort(arr+1, arr+n+1);
    for(int i=1; i<=n; i++){
        if(arr[i-1]>=arr[i])arr[i]++;
        if(arr[i-1]!=arr[i])ans++;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}