#include<cstdio>
#define R(i,n) for(int i=0;i<n;i++)
#define M 3011
int n,m,P=1e9+7,d[M][M],e[M][M];
char z[M][M];
main(){scanf("%d%d",&n,&m);R(i,n)scanf("%s",z[i]);d[2][0]=e[0][2]=1;R(i,n)R(j,m)if(z[i][j]-'#')d[i+1][j+1]=(d[i][j+1]+d[i+1][j])%P,e[i+1][j+1]=(e[i][j+1]+e[i+1][j])%P;printf("%d",(1ll*d[n][m-1]*e[n-1][m]%P+P-1ll*e[n][m-1]*d[n-1][m]%P)%P);}