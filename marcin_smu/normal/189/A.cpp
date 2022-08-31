#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 4001
int n,a,b,c,t[MAX];
main(){
 scanf("%d%d%d%d",&n,&a,&b,&c);
 t[0]=1;
 for(int i=0;i+a<=n;i++){
  if(t[i]!=0)
  t[i+a]=t[i]+1;
 }
 for(int i=0;i+b<=n;i++){
  if(t[i]!=0)
  t[i+b]=max(t[i]+1,t[i+b]);
 }
 for(int i=0;i+c<=n;i++){
  if(t[i]!=0)
  t[i+c]=max(t[i]+1,t[i+c]);
 }
 printf("%d\n",t[n]-1);
}