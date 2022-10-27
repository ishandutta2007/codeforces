#include<bits/stdc++.h>
using namespace std;
int n,lf,sum,deg[510],ans;
vector<int> q[510],b[510];

void dfs(int nod,int pa){
    for(auto i:b[nod]){
    if(i!=pa){
     printf("%d %d\n",i,nod);
     dfs(i,nod);
    }
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    scanf("%d",&deg[i]);
    sum+=deg[i];
    q[deg[i]].push_back(i);
    }
  if(sum<2*n-2) return printf("NO"),0;
  int g,la;
  lf=q[1].size();
  if(lf<=2){
    if(lf>=1){
   g=q[1].back(); la=g;q[1].pop_back();
    }else{
    int l=1; while(q[l].empty())l++;
    g=q[l].back();
    la=q[l].back(); q[l].pop_back();
   }
   for(int i=2;i<=n;i++){
   while(!q[i].empty()){
   ans++;
    b[la].push_back(q[i].back());
    b[q[i].back()].push_back(la);
     la=q[i].back();q[i].pop_back();
   }
   }
   if(!q[1].empty()){ ans++;
    b[la].push_back(q[1].back());
    b[q[1].back()].push_back(la);
    q[1].pop_back();
   }
   }
   else{
   g=q[1].back(); la=g;q[1].pop_back();
    for(int i=2;i<=n;i++){
   while(!q[i].empty()){
    ans++;
    b[la].push_back(q[i].back());
     b[q[i].back()].push_back(la);
     la=q[i].back();q[i].pop_back();
        }
    }
    ans++;
    b[la].push_back(q[1].back());
    b[q[1].back()].push_back(la);
    q[1].pop_back();
        for(int i=1;i<=n;i++){
     while(!b[i].empty()&&b[i].size()<deg[i]&&!q[1].empty()){
     b[i].push_back(q[1].back());
     b[q[1].back()].push_back(i);
     q[1].pop_back();
    }
    }
   }
   printf("YES %d\n%d\n",ans,n-1);
   dfs(g,0);

}