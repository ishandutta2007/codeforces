#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int p[maxn],n,qs[maxn],m;
char a[maxn],b[maxn];

int main(){
    p[0]=1;
    for(int i=1;i<=200000;i++){
        p[i]=p[i-1]<<1;
        if(p[i]>=mod)
            p[i]-=mod;
        }
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
    reverse(a,a+n);reverse(b,b+m);
    for(int i=0;i<n;i++){
        if(i>=1)
        qs[i]=qs[i-1];
        if(a[i]=='1'){
            qs[i]+=p[i];
            if(qs[i]>=mod)
                qs[i]-=mod;
        }
    }
    for(int i=n;i<=max(n,m);i++)
        qs[i]=qs[i-1];
    int ans=0;
    for(int i=0;i<m;i++){
        if(b[i]=='1'){
            ans+=(qs[i]);
            if(ans>=mod)
                ans-=mod;
        }
    }
    printf("%d\n",ans);
}