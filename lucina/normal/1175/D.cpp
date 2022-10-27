#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[maxn];
long long pre[maxn],ans;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=pre[i-1]+a[i];
    }
    ans=1ll*k*pre[n];
    sort(pre+1,pre+n);
    for(int i=1;i<k;i++)
        ans-=pre[i];
    printf("%lld\n",ans);
}