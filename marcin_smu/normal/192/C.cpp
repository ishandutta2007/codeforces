#include<cstdio>
#define INF 1000000000
#define MAX 'z'-'a'+1
int n,t[MAX][MAX];
char z[12];
main(){
 for(int i=0;i<MAX;i++)
 for(int j=0;j<MAX;j++)
 t[i][j]=-INF;
 for(int i=0;i<MAX;i++)
 t[i][i]=0;
 scanf("%d",&n);
 while(n--){
  scanf("%s",z);
  int dl=0;
  while(z[dl])dl++;
  for(int i=0;i<MAX;i++){
   if(t[i][z[0]-'a']+dl>t[i][ z[dl-1]-'a' ])
   t[i][ z[dl-1]-'a' ] = t[i][z[0]-'a']+dl;
  }
 }
 int wyn=0;
 for(int i=0;i<MAX;i++)
 if(wyn<t[i][i])
 wyn=t[i][i];
 printf("%d",wyn);
}