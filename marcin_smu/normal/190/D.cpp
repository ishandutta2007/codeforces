#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
#define MAX 400001
typedef long long LL;
int k,n,t[MAX];
LL wyn;
map<int,int> pom;
main(){
 scanf("%d%d",&n,&k);
 for(int i=0;i<n;i++)
  scanf("%d",&t[i]);
 int po=0,ko=-1;
 while(1){
  do{
   ko++;
   pom[t[ko]]++;
  }while(ko<n&&pom[t[ko]]!=k);
  if(ko==n){
   cout<< wyn;
   return 0;
  }
  bool x=1;
  do{
   wyn+=n-ko;
   if(pom[t[po]]==k)
   x=0;
   pom[t[po]]--;
   po++;
  }while(x);
 }
}