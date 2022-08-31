#include<cstdio>
#define MAX 100001
int n,m,t[MAX],it;
main(){
 scanf("%d%d",&m,&n);
 if(n&1){
  t[0]=n/2+1;it=1;
  for(int i=0;i<n/2;i++){
   t[it++]=n/2-i;
   t[it++]=n/2+i+2;
  }
 }else{
  it=0;
  for(int i=0;i<n/2;i++){
   t[it++]=n/2-i;
   t[it++]=n/2+i+1;
  }
 }
 for(int i=0;i<m;i++){
  printf("%d\n",t[i%n]);
 }
}