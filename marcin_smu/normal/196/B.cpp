#include<cstdio>
#include<queue>
using namespace std;
#define MAX 1501
int n,m;
char z[MAX];
int jakx[MAX][MAX],jaky[MAX][MAX],xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
bool t[MAX][MAX],cz[MAX][MAX];
struct q{
 int x,y;
 int x2,y2;
}pom;
queue<q> kol;
main(){
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++){
  scanf("\n%s",z);
  for(int j=0;j<m;j++){
   if(z[j]=='#')
   t[i][j]=1;
   if(z[j]=='S'){
    pom.x=i;
    pom.y=j;
    pom.x2=0;
    pom.y2=0;
    kol.push(pom);
   }
  }
 }
 while(kol.empty()==0){
  q ak=kol.front();kol.pop();
  if(t[ak.x][ak.y]==1)continue;
  if(cz[ak.x][ak.y]==1){
   if(jakx[ak.x][ak.y]!=ak.x2||
      jaky[ak.x][ak.y]!=ak.y2){
    printf("Yes\n");
    return 0;
   }
  }else{
   cz[ak.x][ak.y]=1;
   jakx[ak.x][ak.y]=ak.x2;
   jaky[ak.x][ak.y]=ak.y2;
   for(int i=0;i<4;i++){
    pom=ak;
    pom.x+=xx[i];
    if(pom.x<0){
     pom.x+=n;
     pom.x2++;
    }
    if(pom.x>=n){
     pom.x-=n;
     pom.x2--;
    }
    pom.y+=yy[i];
    if(pom.y<0){
     pom.y+=m;
     pom.y2++;
    }
    if(pom.y>=m){
     pom.y-=m;
     pom.y2--;
    }
    kol.push(pom);
   }
  }
 }
 printf("No\n");
}