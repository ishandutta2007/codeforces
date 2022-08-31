#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define MAX 201
int n,t[MAX],il[MAX],il2[MAX],wyn=10000;
vector<int> d[MAX];
queue<int> pom[4];
main(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 scanf("%d",&t[i]);
 for(int i=1;i<=n;i++){
  scanf("%d",&il[i]);
  for(int j=0;j<il[i];j++){
   int pom;
   scanf("%d",&pom); 
   d[pom].push_back(i);
  }
 }
 for(int i=0;i<3;i++){
  int ak=-1,kt=i;
  for(int i=1;i<=n;i++){
   il2[i]=il[i];
   if(il[i]==0)
    pom[t[i]].push(i);
  }
  while(pom[1].empty()==0||pom[2].empty()==0||pom[3].empty()==0){
   ak++;
   kt=kt+1;if(kt==4)kt=1;
   while(pom[kt].empty()==0){
    int q=pom[kt].front();pom[kt].pop();
    for(int i=0;i<d[q].size();i++){
     il2[d[q][i]]--;
     if(il2[d[q][i]]==0)
     pom[t[d[q][i]]].push(d[q][i]);
    }
   }
  }
  if(ak<wyn)wyn=ak;
 }
 printf("%d",wyn+n);
}