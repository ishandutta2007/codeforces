#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef pair<int,int> PI;
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define MAX 200001
int n,il[MAX*2],g[MAX*2],im=0,wyn[MAX];
map<int,int> aa,bb;
vector<PI> d[MAX*2];
void dfs(int nr){
 int co=1;
 do{
  while(wyn[d[nr][g[nr]].SE]!=0)g[nr]++;
  wyn[d[nr][g[nr]].SE]=co;
  il[nr]--;
  nr=d[nr][g[nr]].FI;
  il[nr]--;
  co=3-co;
 }while(il[nr]!=0);
}
main(){
 scanf("%d",&n);
 for(int i=0;i<n;i++){
  int a,b;
  scanf("%d%d",&a,&b);
  if(aa[a]==0)
   aa[a]=++im;
  a=aa[a];
  if(bb[b]==0)
   bb[b]=++im;
  b=bb[b];
  d[a].PB(MP(b,i));
  il[a]++;
  d[b].PB(MP(a,i));
  il[b]++;
 }
 for(int i=1;i<=im;i++)
  if(il[i]&1)dfs(i);
 for(int i=1;i<=im;i++)
  if(il[i])dfs(i);
 for(int i=0;i<n;i++)
  putchar(wyn[i]==1?'b':'r');
 puts("");
}