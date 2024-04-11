#include<cstdio>
#include<algorithm>
using namespace std;
int k,b,n,t;
long long ak=1;
main(){
 scanf("%d%d%d%d",&k,&b,&n,&t);
 while(ak<=t){
  ak=k*ak+b;
  n--;
 }
 printf("%d\n",max(n+1,0));
}