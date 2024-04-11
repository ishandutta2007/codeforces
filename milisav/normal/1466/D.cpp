#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int deg[maxn];
int a[maxn];
int n,t;
pair<int,int> ver[maxn];
long long ans[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        long long tot=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            deg[i]=-1;
            tot+=a[i];
        }
        for(int i=0;i<n-1;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            deg[u]++;
            deg[v]++;
        }
        for(int i=1;i<=n;i++) {
            ver[i-1]={a[i],deg[i]};
        }
        sort(ver,ver+n);
        ans[0]=tot;
        int k=1;
        for(int i=n-1;i>=0 && k<n-1;i--) {
            while(ver[i].second>0 && k<n-1) {
                ans[k]=ans[k-1]+ver[i].first;
                k++;
                ver[i].second--;
            }
        }
        for(int i=0;i<n-1;i++) {
            printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}