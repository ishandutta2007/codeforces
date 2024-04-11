#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[101010],ans[101010],cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i+=2) ans[++cnt] = arr[i];
    for(int i=n-n%2;i>1;i-=2) ans[++cnt] = arr[i];

    for(int i=1;i<=n;i++) if(ans[i] >= ans[i==1?n:i-1]+ans[i%n+1]) return !printf("NO");
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}