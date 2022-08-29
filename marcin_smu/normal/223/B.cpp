#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define F(I,N) for(int I=0;I<N;I++)
#define R(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A);
#define MAX 200001
char s[MAX],t[MAX];
int dls,dlt,wyn[MAX];
vector<int> ds[30],dt[30];
main(){
 scanf(" %s %s",s,t);
 dls=0;
 while(s[dls]){
  s[dls]-='a';
  ds[s[dls]].PB(dls);
  dls++;
 }
 dlt=0;
 while(t[dlt]){
  t[dlt]-='a';
  dt[t[dlt]].PB(dlt);
  dlt++;
 }
 int pre=0;
 F(i,dls){
  int ak=s[i];
  int p=-1,k=dt[ak].size();
 // F(j,dt[ak].size()){
 //  printf("%d ",dt[ak][j]);
 // }
 // printf("\n");
  while(p+1<k){
   int m=(p+k)/2;
   if(dt[ak][m]<=pre)
   p=m;
   else
   k=m;
  }
  if(p==-1){
   printf("NO\n");
   return 0;
  }
  wyn[i]=dt[ak][p];
 // printf("%d\n",wyn[i]);
  if(dt[ak][p]==pre)pre++;
 }
// printf("\n");
 pre=dlt-1;
 R(i,dls){
  int ak=s[i];
  int p=-1,k=dt[ak].size();
  while(p+1<k){
   int m=(p+k)/2;
   if(dt[ak][m]<pre)
   p=m;
   else
   k=m;
  }
  if(k==dt[ak].size()||wyn[i]<dt[ak][k]){
   printf("NO\n");
   return 0;
  }
  if(dt[ak][k]==pre)pre--;
 }
 printf("YES\n");
}