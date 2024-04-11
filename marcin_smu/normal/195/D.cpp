#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
#define MAX 100001
#define FI first
#define SE second
int n;
PI t[MAX];
bool q(PI a,PI b){
 if(a.FI*LL(b.FI)>0)
  return a.SE*LL(b.FI)>b.SE*LL(a.FI);
 else
  return a.SE*LL(b.FI)<b.SE*LL(a.FI);
}
bool r(PI a,PI b){
 return a.SE*LL(b.FI)==b.SE*LL(a.FI);
}
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d%d",&t[i].FI,&t[i].SE);
  if(t[i].FI==0){
   i--;
   n--;
  }
 }
 sort(t,t+n,q);
// int j=0;
// LL sum=t[0].FI;
if(n==0){
 printf("0\n");
 return 0;
}
 int wyn=1;
 for(int i=1;i<n;i++){
  if(r(t[i-1],t[i])==0){
 //  sum+=abs(t[i].FI);
  //}else{
  // if(sum!=0)
   wyn++;
 //  j=i;
  // sum=t[j].FI;
  }
 }
// if(sum!=0)wyn++;
 printf("%d\n",wyn);
}