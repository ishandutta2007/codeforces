#include<cstdio>
#include<algorithm>
using namespace std;
int w,h;
long long wyn;
main(){
 scanf("%d%d",&w,&h);
 for(int i=1;i<w;i++)
 for(int j=1;j<h;j++)
  wyn+=min(i,w-i)*min(j,h-j);
 printf("%I64d\n",wyn);
}