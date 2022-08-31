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
#define MAX 101
int n,l,wyn,t[MAX];
main(){
 scanf("%d%d",&n,&l);
 for(int i=0;i<n;i++)
 scanf("%d",&t[i]);
 for(wyn=0;l<=MAX;l++){
  int pom=0;
  for(int i=0;i<n;i++)
   pom+=t[i]/l;
  if(wyn<pom*l)wyn=pom*l;
 }
 printf("%d\n",wyn);
}