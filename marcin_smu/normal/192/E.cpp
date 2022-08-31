#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100001
#define MAX2 20
#define PB push_back
vector<int> d[MAX];
int n,k;
int g[MAX],prz[MAX][MAX2];
void dfs(int nr,int oj,int gl){
 g[nr]=gl;
 int ak=oj;
 for(int i=0;(1<<i)<=gl;i++){
  prz[nr][i]=ak;
  ak=prz[ak][i];
 }
 for(int i=0;i<d[nr].size();i++)
  if(d[nr][i]!=oj)
  dfs(d[nr][i],nr,gl+1);
}
int lca(int a,int b){
 if(g[b]>g[a])swap(a,b);
 if(g[a]>g[b]){
  for(int i=MAX2-1;i>=0;i--){
   if(g[a]-(1<<i)>=g[b])
    a=prz[a][i];
  }
 }
 if(a==b)return a;
 for(int i=MAX2-1;i>=0;i--){
  if(g[a]>=(1<<i)&&prz[a][i]!=prz[b][i]){
   a=prz[a][i];
   b=prz[b][i];
  }
 }
 return prz[a][0];
}
int a[MAX],b[MAX],il[MAX];
int dfs2(int nr,int oj){
 for(int i=0;i<d[nr].size();i++){
  if(d[nr][i]!=oj)
   il[nr]+=dfs2(d[nr][i],nr);
 }
 return il[nr];
}
main(){
 scanf("%d",&n);
 for(int i=1;i<n;i++){
  scanf("%d%d",&a[i],&b[i]);
  d[a[i]].PB(b[i]);
  d[b[i]].PB(a[i]);
 }
 dfs(1,0,0);
 scanf("%d",&k);
 for(int i=0;i<k;i++){
  int poma,pomb;
  scanf("%d%d",&poma,&pomb);
  il[poma]++;
  il[pomb]++;
  il[lca(poma,pomb)]-=2;
 }
 dfs2(1,0);
 for(int i=1;i<n;i++){
  if(g[a[i]]<g[b[i]])
   printf("%d ",il[b[i]]);
  else
   printf("%d ",il[a[i]]);
 }
 printf("\n");
}