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
int k,a,b,dl;
char t[201];
main(){
 scanf("%d%d%d %s",&k,&a,&b,t);
 dl=0;
 while(t[dl])dl++;
 if(k*a>dl||k*b<dl)
 printf("No solution\n");
 else{
  int pom=dl/k,pom2=dl%k,g=0;
  for(int i=0;i<k;i++){
   for(int j=0;j<pom+(pom2>i);j++,g++)
    printf("%c",t[g]);
   printf("\n");
  }
 }
}