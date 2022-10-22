#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t,n,k;
int a[maxn];
int b[maxn];
int c[maxn];
int pos[maxn];
int p[maxn];
long long mod=998244353;
int main() {
    scanf("%d",&t);
    while(t--) {
        long long ans=1;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
            c[i]=0;
        }
        for(int i=0;i<k;i++) {
            scanf("%d",&b[i]);
            p[i]=pos[b[i]];
            c[p[i]]=i;
        }
        for(int i=0;i<k;i++) {
            int j=p[i];
            long long cnt=0;
            c[j]=0;
            if(j>0 && c[j-1]==0) cnt++;
            if(j<n-1 && c[j+1]==0) cnt++;
            ans=(ans*cnt)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}