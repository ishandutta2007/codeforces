#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
int n,m,u,v,ma,a[maxn],r,x,y,s[maxn];

main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        s[i]=1e9;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&x,&y);
        a[x]++;
        s[x]=min(s[x],x>y?n-x+y:y-x);
    }
    for(int i=1;i<=n;i++){
        ma=max(ma,a[i]);
    }
    if(ma==0){
        for(int i=1;i<=n;i++)
            printf("0 ");
        return 0;
    }
    for(int i=1;i<=n;i++){
        u=0;
        for(int j=1;j<=n;j++){
                if(a[j]){
                    u=max(u,(i>j?n-i+j:j-i)+s[j]+(a[j]-1)*n);
                }
        }
        printf("%lld ",u);
        }
    }