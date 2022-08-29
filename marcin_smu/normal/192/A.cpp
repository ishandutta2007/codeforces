#include<cstdio>
#include<map>
using namespace std;
typedef long long LL;
#define MAX 100000
LL t[MAX],n;
map<LL,LL> pom;
main(){
 for(LL i=1;i<MAX;i++){
  t[i]=i*(i+1)/2;
  pom[t[i]]=1;
 }
 scanf("%d",&n);
 for(int i=1;n>t[i];i++){
  if(pom[n-t[i]]==1){
   printf("YES\n");
   return 0;
  }
 }
 printf("NO\n");
}