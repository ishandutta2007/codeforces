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
int n,t[MAX],a,b;
main(){
 scanf("%d",&n);
 for(int i=1;i<n;i++)
 scanf("%d",&t[i]);
 scanf("%d%d",&a,&b);
 int wyn=0; 
 while(a!=b){
  wyn+=t[a];
  a++;
 }
 printf("%d\n",wyn);
}