#include<stdio.h>
const int maxn=2e5+10;
int a[15][maxn],pos[15][maxn],b,c,d,n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            pos[i][a[i][j]]=j;
        }
    }
    long long ans=0;
    bool x;
    int j;
    for(int i=1;i<=n;i++){
        j=i;
        x=true;
        while(j<n){
            for(int k=2;k<=m;k++){
                if(a[1][j+1]!=a[k][pos[k][a[1][j]]+1])
                    x=false;
            }
            if(x) j++;
            else break;
        }
        ans+=((long long)1)*(j-i+1)*(j-i+2)/2;
        i=j;
    }
    printf("%lld",ans);
}