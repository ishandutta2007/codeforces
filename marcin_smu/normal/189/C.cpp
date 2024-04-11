#include<cstdio>
#define MAX 200001
int n,t[MAX],j=0;
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 scanf("%d",&t[i]);
 for(int i=0;i<n;i++){
  int pom;
  scanf("%d",&pom);
  if(pom==t[j])
  j++;
 }
 printf("%d\n",n-j);
}