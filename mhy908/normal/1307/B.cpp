#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t, n;
LL d;
LL arr[100010];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %lld", &n, &d);
        LL ans=llinf;
        for(int i=1; i<=n; i++)scanf("%lld", &arr[i]);
        for(int i=1; i<=n; i++){
            if(d%arr[i]==0)ans=min(ans, d/arr[i]);
            else if(d<arr[i])ans=min(ans, 2ll);
            else ans=min(ans, d/arr[i]+1);
        }
        printf("%lld\n", ans);
    }
}