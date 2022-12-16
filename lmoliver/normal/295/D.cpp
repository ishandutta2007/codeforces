//NO UKE!
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
inline int add(int a,int b){return (a+b)%MOD;}
inline int sub(int a,int b){return (a-b+MOD)%MOD;}
inline int mul(int a,int b){return ((long long)a*(long long)b)%MOD;}
const int N=2020;
int w[N][N]={0};
int pf0[N]={0};
int pf[N]={0};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m;i++)w[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            pf0[j]=add((j?pf0[j-1]:0),w[i-1][j]);
        }
        for(int j=0;j<=m;j++){
            pf[j]=add((j?pf[j-1]:0),mul(j-1+MOD,w[i-1][j]));
        }
        for(int j=0;j<=m;j++){
            w[i][j]=sub(add(1,mul(j,pf0[j])),pf[j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m-2;j++){
            ans=add(ans,mul(
                m-2-j+1,
                mul(
                    sub(
                        w[i-1][j],
                        i>=2?w[i-2][j]:0
                    ),
                    w[n-i][j]
                )
            ));
        }
    }
    printf("%d\n",ans);
    return 0;
}