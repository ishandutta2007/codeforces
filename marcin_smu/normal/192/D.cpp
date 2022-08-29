#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
#define MAX 100001
#define FI first
#define SE second
LL b;
int n,k;
pair<int,int> t[MAX];
main(){
 ios_base::sync_with_stdio(0);
 cin>>n>>k>>b;
 for(int i=0;i<n;i++){
  //scanf("%d",&t[i].FI);
  cin>>t[i].FI;
  t[i].FI*=-1;
  t[i].SE=i;
 }
 sort(t,t+n-1);
 LL sum=0;
 for(int i=0;i<k;i++)
  sum-=t[i].FI;
 if(sum<=b){
  printf("%d\n",n);
  return 0;
 }
 sum+=t[k-1].FI;
 int wyn=n;
 for(int i=0;i<n-1&&sum-t[i].FI>b;i++)
  wyn=min(t[i].SE,wyn);
 printf("%d\n",wyn+1);
}