#include<cstdio>
#include<vector>
using namespace std;
int n,m,k,m2[101],k2[101],mi=101;
vector<int> wyn;
main(){
 scanf("%d%d%d",&n,&m,&k);
 for(int i=0;i<m;i++)
 scanf("%d",&m2[i]);
 for(int i=0;i<k;i++)
 scanf("%d",&k2[i]);
 for(int i=0;i<m;i++){
  int pom=0;
  for(int j=0;j<k;j++)
  if(k2[j]%m2[i]==0)pom++;
  if(pom<mi){
   mi=pom;
   wyn.clear();
  }
  if(pom==mi)wyn.push_back(i+1);
 }
 printf("%d\n",wyn.size());
 for(int i=0;i<wyn.size();i++)
 printf("%d ",wyn[i]);
}