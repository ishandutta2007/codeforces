#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[303030],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n/2;i++) ans+=(arr[i] + arr[n-i+1]) * (arr[i] + arr[n-i+1]);
    printf("%lld",ans);
}