#include<cstdio>
int a,b,c;
main(){
 scanf("%d%d%d",&a,&b,&c);
 for(int i=0;1;i++){
  if(i*b+c*b>=a*c){
   printf("%d\n",i);
   return 0;
  }
 }
}