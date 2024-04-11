#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
main(){
 scanf("%d%d",&n,&m);
 if(n==0){
  if(m==0)
  printf("0 0\n");
  else
  printf("Impossible\n");
 }else{
  printf("%d %d\n",n+m-min(n,m),n+m-(m==0?0:1));
 }
}