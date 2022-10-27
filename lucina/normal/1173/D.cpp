#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
int mul(int a, int b) {
  long long re=(long long) a*b;
  return re>=mod?(int)(re%mod):(int)re;
  }
int n,u,v,f[maxn],deg[maxn];
int main(){
    f[0]=1;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        f[i]=mul(f[i-1],i);
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
    }
    f[n]=mul(f[n-1],n);
    int ans=n;
    for(int i=1;i<=n;i++)
        ans=mul(ans,f[deg[i]]);
    printf("%d\n",ans);
}