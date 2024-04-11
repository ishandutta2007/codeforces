#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 301
#define INF 1000000000
int wyn[MAX*2][MAX][MAX],n,t[MAX][MAX];
inline int licz2(int x,int y){
 return min(x,n-y-1);
}
inline int licz(int nr,int x1,int y1,int x2,int y2){
// printf("%d %d %d %d %d = %d\n",nr,x1,y1,x2,y2,wyn[nr][licz2(x1,y1)][licz2(x2,y2)]);
return  wyn[nr][licz2(x1,y1)][licz2(x2,y2)];
}
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
 scanf("%d",&t[i][j]);
 wyn[0][0][0]=t[0][0];
 int sze=1,x=0,y=0;
 for(int i=1;i<2*n-1;i++){
  if(i<n){
   sze++;
   y++;
  }else{
   sze--;
   x++;
  }
  //printf("%d %d %d %d\n",i,sze,x,y);
  for(int j=0;j<sze;j++){
   for(int k=0;k<sze;k++){
    wyn[i][j][k]=-INF;
    int x1=x+j,y1=y-j;
    int x2=x+k,y2=y-k;
   // printf("%d %d %d\n",j,x1,y1);
    if(x1!=0){
     if(x2!=0)
     wyn[i][j][k]=max(wyn[i][j][k],licz(i-1,x1-1,y1,x2-1,y2));
     if(y2!=0)
     wyn[i][j][k]=max(wyn[i][j][k],licz(i-1,x1-1,y1,x2,y2-1));
    }
    if(y1!=0){
     if(x2!=0)
     wyn[i][j][k]=max(wyn[i][j][k],licz(i-1,x1,y1-1,x2-1,y2));
     if(y2!=0)
     wyn[i][j][k]=max(wyn[i][j][k],licz(i-1,x1,y1-1,x2,y2-1));
    }
    wyn[i][j][k]+=t[x1][y1];
    if(k!=j)
    wyn[i][j][k]+=t[x2][y2];
   }
  }
 }
 printf("%d\n",wyn[2*n-2][0][0]);
}