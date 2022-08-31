#include<cstdio>
using namespace std;
#define MAX 100010
char z[MAX],wyn[MAX];
main(){
 scanf("\n%s",z);
 int dl=0;
 while(z[dl])dl++;
 char co=0;
 wyn[MAX-1]=0;
 int iwyn=MAX-1;
 for(int i=dl-1;i>=0;i--){
  if(z[i]>=co){
   co=z[i];
   iwyn--;
   wyn[iwyn]=z[i];
  }
 }
 printf("%s\n",wyn+iwyn);
}