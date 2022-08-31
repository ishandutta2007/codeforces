#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000000
#define PI pair<int,int>
#define PB push_back
#define MP make_pair
int n,wyn;
vector<int> x[MAX*2+1],y[MAX*2+1];
//map<PI,int > pom;
bool czd[MAX*5];
bool pom(int xx,int yy){
 if(xx<0)return 0;
 int p=0,k=x[xx].size();
 if(k==0)return 0;
 while(p+1!=k){
  if(x[xx][(p+k)/2]<=yy)
  p=(p+k)/2;
  else
  k=(p+k)/2;
 }
 return x[xx][p]==yy;
}
main(){
 scanf("%d",&n);
 int p=1;
 while(p*p<n)p++;
 wyn=0;
 for(int i=0;i<n;i++){
  int a,b;
  scanf("%d%d",&a,&b);
  a+=MAX;
  b+=MAX;
  //pom[MP(a,b)]=1;
  x[a].PB(b);
 }
 for(int i=0;i<=MAX*2;i++){
  if(x[i].size()>p)czd[i]=1;
  sort(x[i].begin(),x[i].end());
 }
 for(int i=0;i<=MAX*2;i++){
  if(czd[i]==0){
   for(int k=0;k<x[i].size();k++)
   for(int l=k+1;l<x[i].size();l++){
    int odl=x[i][l]-x[i][k];
    if(pom(i-odl,x[i][k])&&
       pom(i-odl,x[i][l]))
    wyn++;
    if(czd[i+odl]==1&&
       pom(i+odl,x[i][k])&&
       pom(i+odl,x[i][l]))
    wyn++;
   }
  }else
  for(int j=0;j<x[i].size();j++)
  y[x[i][j]].PB(i);
 }
 for(int i=0;i<=MAX*2;i++){
  for(int k=0;k<y[i].size();k++)
  for(int l=k+1;l<y[i].size();l++){
   int odl=abs(y[i][k]-y[i][l]);
    if(pom(y[i][k],i-odl)&&
       pom(y[i][l],i-odl))
    wyn++;
  }
 }
 printf("%d\n",wyn);
}