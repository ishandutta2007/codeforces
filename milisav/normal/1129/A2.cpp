#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[6000];
int s[6000];
int b[6000];
int dist(int u,int v) {
    if(v>u) return v-u;
    else return n-(u-v);
}
int g[21000];
int h[21000];
int main() {
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++) {
            scanf("%d %d",&g[i],&h[i]);
    }
    for(int j=1;j<=n;j++) {
        for(int i=1;i<=n;i++) {
            a[i]=0;
            b[i]=0;
            s[i]=-1;
        }
        for(int i=0;i<m;i++) {
            u=g[i];
            v=h[i];
            if(u>=j) u=u-j+1;
            else u=u+n-j+1;
            if(v>=j) v=v-j+1;
            else v=v+n-j+1;
            if(a[u]==0 || dist(u,a[u])>dist(u,v)) a[u]=v;
            s[u]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            b[i]=s[i];
            if(a[i]<i) b[i]++;
            ans=max(ans,b[i]*n+a[i]-1);
        }
        printf("%d ",ans);
    }
}