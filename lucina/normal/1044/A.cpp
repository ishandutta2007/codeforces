#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,u,v,w,a[maxn],b[maxn],t;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    a[n+1]=1e9;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        if(u==1)
        t++,b[t]=v;
    }
    int ans=1e9;
    sort(a+1,a+n+1);
    sort(b+1,b+t+1);
    int j=1;
    for(int i=1;i<=n+1;i++){
        while(j<=t&&b[j]<a[i])
            j++;
        ans=min(ans,i+t-j);
    }
    printf("%d\n",ans);
}