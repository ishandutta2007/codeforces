#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define MAX 100001
#define PB push_back
int n,m,k,s,t,f[MAX],odl[MAX],wyn;
vector<int> d[MAX];
vector<pair<int,int> > wyny;
queue<int> ko;
int find(int a){
 return f[a]==a?a:f[a]=find(f[a]);
}
void Union(int a,int b){
 f[find(a)]=find(b);
}
main(){
 scanf("%d%d%d",&n,&m,&k);
 for(int i=0;i<n;i++)f[i]=i;
 for(int i=0;i<k;i++){
  int pom;
  scanf("%d",&pom);
  ko.push(pom);
  odl[pom]=1;
 }
 for(int i=0;i<m;i++){
  int a,b;
  scanf("%d%d",&a,&b);
  d[a].PB(b);
  d[b].PB(a);
 }
 scanf("%d%d",&s,&t);
 if(odl[t]==0){
  odl[t]=1;
  ko.push(t);
 }
 while(ko.empty()==0){
  int ak=ko.front();ko.pop();
  if(wyn<odl[ak]){
   for(int i=0;i<wyny.size();i++)
   Union(wyny[i].first,wyny[i].second);
   if(find(t)==find(s)){
    printf("%d\n",wyn*2);
    return 0;
   }
   wyny.clear();
  }
  for(int i=0;i<d[ak].size();i++){
   if(odl[d[ak][i]]==odl[ak]){
    Union(d[ak][i],ak);
    if(find(s)==find(t)){
     printf("%d\n",2*odl[ak]-1);
     return 0;
    }
   }
   if(odl[d[ak][i]]==odl[ak]+1){
    wyn=odl[ak];
    wyny.PB(make_pair(ak,d[ak][i]));
   }
   if(odl[d[ak][i]]==0){
    Union(ak,d[ak][i]);
    odl[d[ak][i]]=odl[ak]+1;
    ko.push(d[ak][i]);
   }
  }
 }
 for(int i=0;i<wyny.size();i++)
  Union(wyny[i].first,wyny[i].second);
 if(find(t)==find(s)){
   printf("%d\n",wyn*2);
   return 0;
 }
 printf("-1\n");
}