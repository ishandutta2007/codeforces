#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100001
#define PB push_back
int n,m,t[MAX],p[MAX],k[MAX],wyn[MAX],il[MAX],pre[MAX];
vector<int> sp;
main(){
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++){
  scanf("%d",&t[i]);
  if(t[i]<=n){
   il[t[i]]++;
   if(t[i]==il[t[i]])
   sp.PB(t[i]);
  }
 }
 for(int i=0;i<m;i++)
  scanf("%d%d",&p[i],&k[i]);
 for(int j=0;j<sp.size();j++){
  for(int i=1;i<=n;i++)
  pre[i]=pre[i-1]+(sp[j]==t[i]);
  for(int i=0;i<m;i++){
   if(pre[k[i]]-pre[p[i]-1]==sp[j])
   wyn[i]++;
  }
 }
 for(int i=0;i<m;i++)
 printf("%d\n",wyn[i]);
}