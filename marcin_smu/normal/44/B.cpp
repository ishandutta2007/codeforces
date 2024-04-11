#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define LL long long
#define PI pair<int,int>
#define D double
#define MAX 
int n,a,b,c;
LL wyn;
main(){
 scanf("%d%d%d%d",&n,&a,&b,&c);
 a/=2;
 for(int i=0;i<=c;i++){
  int pom=n-2*i;
  if(pom>=0&&a+b>=pom){
   wyn+=min(a,pom)-max(0,pom-b)+1;
  }
 }
 printf("%lld",wyn);
}