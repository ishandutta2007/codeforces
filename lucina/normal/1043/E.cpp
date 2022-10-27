#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v,f,pos[maxn],a[maxn],b[maxn];
long long ans[maxn],sum;
bool cmp(int i,int j){
    return a[i]-b[i]<a[j]-b[j];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        pos[i]=i;
    }
    sort(pos+1,pos+1+n,cmp);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        f=min(a[u]+b[v],a[v]+b[u]);
        ans[u]-=f;
        ans[v]-=f;
    }
    for(int i=1;i<=n;i++){
        ans[pos[i]]+=((long long)1*b[pos[i]])*(i-1)+sum;
        sum+=a[pos[i]];
    }
    sum=0;
    for(int i=n;i>=1;i--){
        ans[pos[i]]+=((long long)1*a[pos[i]])*(n-i)+sum;
        sum+=b[pos[i]];
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
}