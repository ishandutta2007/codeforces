#include<bits/stdc++.h>
#define maxn 5000
using namespace std;
int t;
int n;
int a[maxn];
int z;
int ans=0;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&z);
        ans=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            ans=max(ans,z|a[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}