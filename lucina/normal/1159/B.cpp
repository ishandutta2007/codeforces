#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,ans,a[maxn],pre[maxn],suf[maxn];


int main(){
    scanf("%d",&n);
    pre[0]=1e9+7;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pre[i]=min(pre[i-1],a[i]);
        }
    suf[n+1]=1e9+7;
    for(int i=n;i>=1;i--){
        suf[i]=min(suf[i+1],a[i]);
    }
    ans=1e9+7;
    for(int i=1;i<=n-1;i++){
        int c=min(pre[n-i],suf[i+1]);
        ans=min(ans,c/i);
    }
    printf("%d\n",ans);
}