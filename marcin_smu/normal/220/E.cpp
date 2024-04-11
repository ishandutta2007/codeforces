#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
#define MAX 100001
int n,a[MAX],b[MAX],il=1,dp[MAX],dp2[MAX],war[MAX];
map<int,int> num;
LL k,k2;
void dod(int nr,int il){
 for(;nr<=n;nr+=(nr&-nr))
  dp[nr]+=il;
}
int sum(int nr){
 int w=0;
 for(;nr;nr-=(nr&-nr))
  w+=dp[nr];
 return w;
}
void dod2(int nr,int il){
 for(;nr;nr-=(nr&-nr))
  dp2[nr]+=il;
}
int sum2(int nr){
 int w=0;
 for(;nr<=n;nr+=(nr&-nr))
  w+=dp2[nr];
 return w;
}
inline void add(int nr){
 dod(nr,1);
 dod2(nr,1);
}
inline void us(int nr){
 dod(nr,-1);
 dod2(nr,-1);
}
main(){
 scanf("%d%I64d",&n,&k);
 for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
  b[i]=a[i];
 }
 sort(b,b+n);
 for(int i=0;i<n;i++){
  if(i==0||b[i-1]!=b[i]){
   num[b[i]]=il;
   il++;
  }
 }
 for(int i=0;i<n;i++){
  a[i]=num[a[i]];
  int pom=sum2(a[i]+1);
  k2+=pom;
  war[i]+=pom;
  dod2(a[i],1);
 }
 for(int i=n-1;i>=0;i--){
  war[i]+=sum(a[i]-1);
  dod(a[i],1);
 }
 for(int i=0;i<=n;i++){
  dp[i]=0;
  dp2[i]=0;
 }
 LL wynik=LL(n)*(n-1)/2;
 if(k2<=k){
  printf("%I64d\n",wynik);
  return 0;
 }
 int po=0;int ko=1;
 while(po+1<n){
  while(k2>k&&ko<n){
   k2-=war[ko];
   k2+=sum2(a[ko]+1);
   add(a[ko]);
   ko++;
  }
  ko--;
  k2+=war[ko];
  k2-=sum2(a[ko]+1);
  us(a[ko]);
  if(k2>k)
  wynik-=ko-po;
  if(ko-1>po){
   po++;
   k2+=war[po];
   k2-=sum(a[po]-1);
   us(a[po]);
  }else{
   po++;
   ko++;
  }
 }
 printf("%I64d\n",wynik);
}