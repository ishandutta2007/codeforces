#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long c[2][2019],f[2019],ans;
int k,t,a[2019],n,x;
bool ch[2019];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==-1){
            k++;
        }
        else
            ch[a[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            if(!ch[i])
                t++;
        }
    }
    c[0][0]=1;
    for(int i=1;i<=t;i++){
        x=i&1;
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                c[x][j]=1;
                continue;
            }
            c[x][j]=c[x^1][j]+c[x^1][j-1];
            if(c[x][j]>mod)
                c[x][j]-=mod;
        }
    }
    f[0]=1;
    for(int i=1;i<=k;i++){
        f[i]=f[i-1]*i;
        if(f[i]>mod)
            f[i]%=mod;
    }
    x=t&1;
    int pa=1;
    for(int i=0;i<=t;i++){
        ans+=(f[k-i]*c[x][i]*pa);
        ans%=mod;
        if(ans<0)
            ans+=mod;
        pa=-pa;
    }
    printf("%lld\n",ans);
}