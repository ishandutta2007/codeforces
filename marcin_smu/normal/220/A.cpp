#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100001
int n,t[MAX],t2[MAX],il=0;
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d",&t[i]);
  t2[i]=t[i];
 }
 sort(t,t+n);
 for(int i=0;i<n;i++)
  if(t[i]!=t2[i])il++;
 if(il<=2)
 printf("YES\n");
 else
 printf("NO\n");
}