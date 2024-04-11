#include<cstdio>
#define MAX 1000001
char t[MAX],t2[MAX];
int il;
main(){
 scanf("%s %s",t,t2);
 int i=0,il=1,p=0;
 while(t[i]==t2[i]){
  i++;
  if(t[i]==t[i-1]){
  il++;
  }else{
   il=1;
   p=i;
  }
 }
 while(t[i]){
  if(t[i+1]!=t2[i]){
   printf("0\n");
   return 0;
  }
  i++;
 }
 printf("%d\n",il);
 for(int j=1;j<=il;j++)
 printf("%d ",j+p);
 printf("\n");
}