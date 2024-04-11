#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int n, m;
LL arr[100010], ans;
int zero[100010], re, pl, mi;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
        if(arr[i]>=1){
            ans+=arr[i]-1;
            arr[i]=1;
            pl++;
        }
        if(arr[i]<=-1){
            ans+=-1-arr[i];
            arr[i]=-1;
            mi++;
        }
        if(arr[i]==0){
            zero[++re]=i;
        }
    }
    if(mi%2==0)printf("%lld", ans+(LL)re);
    else if(mi%2&&re)printf("%lld", ans+(LL)re);
    else printf("%lld", ans+2);
}