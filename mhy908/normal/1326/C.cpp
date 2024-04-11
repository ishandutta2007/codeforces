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
int n, k;
LL arr[200010];
int main(){
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)scanf("%lld", &arr[i]);
    int pv=0;
    LL ans1=0, ans2=1;
    for(int i=1; i<=n; i++){
        if(arr[i]>(LL)n-k){
            ans1+=arr[i];
            if(pv){
                ans2*=(LL)(i-pv);
                ans2%=998244353ll;
            }
            pv=i;
        }
    }
    printf("%lld %lld", ans1, ans2);
}