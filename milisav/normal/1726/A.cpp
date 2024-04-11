#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
int t;
int n;
int a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        int ans=a[n]-a[1];
        for(int i=2;i<=n;i++) ans=max(ans,a[i-1]-a[i]);
        for(int i=2;i<=n;i++) ans=max(ans,a[i]-a[1]);
        for(int i=1;i<=n-1;i++) ans=max(ans,a[n]-a[i]);
        printf("%d\n",ans);
    }
    return 0;
}