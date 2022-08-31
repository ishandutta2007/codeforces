#include<cstdio>
#include<vector>
using namespace std;
int n,w=1;
vector<int> wyn;
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  int pom;
  scanf("%d",&pom);
  if(pom==w){
   w++;
   wyn.push_back(i+2001);
  }
 }
 printf("%d\n",w-1);
 for(int i=0;i<w-1;i++)
 printf("%d ",wyn[i]);
 printf("\n");
}