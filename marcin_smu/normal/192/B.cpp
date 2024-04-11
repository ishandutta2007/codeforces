#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 1001
int n,t[MAX],wyn;
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++)
  scanf("%d",&t[i]);
 wyn=min(t[0],t[n-1]);
 for(int i=1;i<n;i++)
 wyn=min(wyn,max(t[i-1],t[i]));
 printf("%d\n",wyn);
}