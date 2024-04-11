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

int n, arr[110], cnt[110], ans;
void solve(){
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        for(int j=1; j<i; j++)cnt[arr[i]-arr[j]]++;
    }
    ans=0;
    for(int i=1; i<=100; i++){
        if(cnt[i])ans++;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}