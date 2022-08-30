#include<cstdio>
int k;
void q(int a){
 if(a>=k)
 printf("%d",a/k);
 printf("%d ",a%k);
}
main(){
 scanf("%d",&k);
 for(int i=1;i<k;i++){
  for(int j=1;j<k;j++)
   q(i*j);
  printf("\n");
 }
}