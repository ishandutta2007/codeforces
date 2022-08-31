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
#define MAX 3001
#define INF 4000000000000ll
int n,m;
LL wyn[MAX];
PI t[MAX];
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 scanf("%d%d",&t[i].FI,&t[i].SE);
 sort(t,t+n);
 wyn[0]=t[0].SE;
 for(int i=1;i<n;i++){
  LL pom=INF;
  for(int j=0;j<i;j++){
   if(wyn[j]<pom)pom=wyn[j];
   wyn[j]+=t[i].FI-t[j].FI;
  }
  wyn[i]=pom+t[i].SE;
 }
 LL pom=INF;
 for(int i=0;i<n;i++)
 if(pom>wyn[i])pom=wyn[i];
 printf("%d\n",pom);
}