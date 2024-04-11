#include<cstdio>
#define INF 1000001
int n,m,r,o[61][61],w[61][61][61];//z//do//licz
main(){
 scanf("%d%d%d",&n,&m,&r);
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 w[i][j][0]=INF;
 for(int i=0;i<m;i++){
  for(int j=0;j<n;j++)
  for(int k=0;k<n;k++)
  scanf("%d",&o[j][k]);
  
  for(int j=0;j<n;j++)
  for(int k=0;k<n;k++)
  for(int l=0;l<n;l++)
  if(o[k][l]>o[k][j]+o[j][l])
  o[k][l]=o[k][j]+o[j][l];
  
  for(int j=0;j<n;j++)
  for(int k=0;k<n;k++)
  if(w[j][k][0]>o[j][k])
  w[j][k][0]=o[j][k];
 }
 for(int l=1;l<n;l++)
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++){
  w[i][j][l]=w[i][j][l-1];
  for(int k=0;k<n;k++)
  if(w[i][j][l]>w[i][k][l-1]+w[k][j][0])
  w[i][j][l]=w[i][k][l-1]+w[k][j][0];
 }
 while(r--){
  int s,t,k;
  scanf("%d%d%d",&s,&t,&k);
  if(k>=n)k=n-1;
  printf("%d\n",w[s-1][t-1][k]);
 }
}