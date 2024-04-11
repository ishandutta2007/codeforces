#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int a[10000];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        if(k>=m-1) k=m-1;
        int ans=-1;
        for(int i=0;i<=k;i++) {
            int cans=-1;
            for(int j=0;j<=m-1-k;j++) {
                int tans=max(a[i+j],a[n-1-(k-i)-(m-1-k-j)]);
                if(cans==-1 || tans<cans) cans=tans;
            }
            if(ans==-1 || cans>ans) ans=cans;
        }
        printf("%d\n",ans);
    }
    return 0;
}