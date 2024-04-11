#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100010
#define MOD 1000000007
#define PB push_back
#define zmod(X) if(X<0)X+=MOD;if(X>=MOD)X-=MOD;
int n,a[MAX],b[MAX],c[MAX],il=0,f[MAX],pre[MAX],post[MAX],io=-1,dp[MAX],wyn;
vector<int> d[MAX];
int find(int a){
 return f[a]==a?a:f[a]=find(f[a]);
}
void Union(int a,int b){
 f[find(a)]=find(b);
}
void dfs(int nr){
 io++;
 pre[nr]=io;
 for(int i=0;i<d[nr].size();i++)
 dfs(d[nr][i]);
 post[nr]=io;
}
void add(int nr,int il){
// printf("add:%d %d\n",nr,il);
 for(;nr<=n;nr+=(nr&-nr)){
  dp[nr]+=il;
  zmod(dp[nr]);
 }
}
int sum(int nr){
 int wyn=0;
 for(;nr;nr-=(nr&-nr)){
  wyn+=dp[nr];
  zmod(wyn);
 }
 return wyn;
}
main(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 f[i]=i;
 for(int i=0;i<n;i++){
  int pom;
  scanf("%d",&pom);
  for(int j=0;j<pom;j++){
   int a2,b2;
   scanf("%d%d",&a2,&b2);
   a[il]=find(a2);
   b[il]=a2;
   c[il]=b2;
   il++;
   d[i+1].PB(find(a2));
   Union(a2,i+1);
  }
 }
 for(int i=1;i<=n;i++){
  if(f[i]==i){
   d[0].PB(i);
  }
 }
 dfs(0);
// for(int i=1;i<=n;i++){
 // printf("%d %d\n",pre[i],post[i]);
 //}
 for(int i=0;i<il;i++){
//  printf("%d %d %d\n",a[i],b[i],c[i]);
//  printf("sum:%d\n",pre[b[i]]);
  int pom=sum(pre[b[i]])+c[i];
 // printf("%d\n",pom);
  zmod(pom);
  wyn+=pom;
  zmod(wyn);
 // printf("pre %d post %d\n",pre[a[i]],post[a[i]]);
  add(pre[a[i]],pom);
  //if(pre[a[i]]>1)
  add(post[a[i]]+1,-pom);
 // for(int i=1;i<=n;i++){
 //  printf("%d ",sum(i));
 // }
  ///printf("\n");
 }
 printf("%d\n",wyn);
}