#include<cstdio>
#include<vector>
using namespace std;
#define MAX 500001
#define MAX2 1520
#define PB push_back
int n,m,f[MAX],wyn,g[MAX],g2[MAX];
vector<int> d[MAX],wy[MAX];
int t[MAX2][MAX2];
int find(int a){
 return a==f[a]?a:f[a]=find(f[a]);
}
void Union(int a,int b){
// printf("Unin: %d %d",a,b);
 a=find(a);
 b=find(b);
 if(a!=b){
  wyn--;
  f[a]=b;
 }
}
main(){
 scanf("%d%d",&n,&m);
 for(int i=0;i<m;i++){
  int a,b;
  scanf("%d%d",&a,&b);
  d[a].PB(b);
  d[b].PB(a);
 }
 int mn=1;
 for(int i=2;i<=n;i++){
  if(d[mn].size()>d[i].size())
  mn=i;
 }
 g2[0]=mn;
 wyn=d[mn].size()+1;
 for(int i=0;i<d[mn].size();i++){
  f[d[mn][i]]=d[mn][i];
  g[d[mn][i]]=i+1;
  g2[i+1]=d[mn][i];
 }
 for(int i=1;i<=n;i++){
  if(f[i]!=i){
   f[i]=mn;
  }
 }
// for(int i=0;i<=n;i++){
 // printf("%d %d %d\n",f[i],g[i],g2[i]);
 //}
 for(int i=1;i<=n;i++){
  for(int j=0;j<d[i].size();j++){
   //printf("%d %d\n",g[i],g[d[i][j]]);
   t[g[i]][g[d[i][j]]]++;
  }
 }
 for(int i=1;i<=d[mn].size();i++){
  if(t[0][i]!=(n-d[mn].size()))
  t[0][i]=0;
 }
 for(int i=0;i<=d[mn].size();i++)
 for(int j=0;j<=d[mn].size();j++){
  if(t[i][j]==0)
   Union(g2[i],g2[j]);
 }
 printf("%d\n",wyn);
 for(int i=1;i<=n;i++){
  f[i]=find(f[i]);
  wy[f[i]].PB(i);
 }
 for(int i=1;i<=n;i++){
  if(wy[i].size()!=0){
   printf("%d",wy[i].size());
   for(int j=0;j<wy[i].size();j++)
   printf(" %d",wy[i][j]);
   printf("\n");
  }
 }
 
}