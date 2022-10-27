#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
 
const int INF=1e9+7;
 
int ps[10];
 
int desire[40][10];
 
int child_deg[40];
int machine_deg[10];
int N,M;
 
//first N are children
//next M*2 are machines
int graph[60][60];
int deg[60];
int match[60];
bool vis[60];
bool need[60];
 
std::vector<std::array<int,4> > segments;
 
void add_edge(int child,int machine,int weight){
  int u=child;
  int v=machine+N;
  graph[u][v]=graph[v][u]=weight;
  deg[u]+=weight;
  deg[v]+=weight;
}
 
bool dfs_match(int u){
  if(vis[u]) return false;
  vis[u]=true;
  if(!need[u]&&match[u]!=-1){
    match[match[u]]=-1;
    match[u]=-1;
    return true;
  }
  for(int v=0;v<60;v++){
    if(!graph[u][v]) continue;
    if(v==match[u]) continue;
    if(match[v]==-1||dfs_match(match[v])){
      match[u]=v,match[v]=u;
      return true;
    }
  }
  return false;
}
 
int find_matching(){
  std::fill(need,need+60,true);
  std::fill(match,match+60,-1);
  for(int i=0;i<60;i++){
    if(match[i]==-1){
      std::fill(vis,vis+60,false);
      dfs_match(i);
    }
  }
  std::fill(deg,deg+60,0);
  for(int i=0;i<60;i++){
    for(int j=0;j<60;j++){
      deg[i]+=graph[i][j];
    }
  }
  int D=*std::max_element(deg,deg+60);
  for(int i=0;i<60;i++){
    need[i]=(deg[i]==D);
  }
  for(int i=0;i<60;i++){
    if(need[i]&&match[i]==-1){
      std::fill(vis,vis+60,false);
      dfs_match(i);
    }
  }
  return D;
}
 
int main(){
  int B;
  scanf("%d %d %d",&N,&M,&B);
  for(int i=0;i<M;i++){
    scanf("%d",&ps[i]);
  }
  for(int i=0;i<N;i++){
    int K;
    scanf("%d",&K);
    while(K-- > 0){
      int X,T;
      scanf("%d %d",&X,&T);
      X--;
      desire[i][X]=T;
      child_deg[i]+=T;
      machine_deg[X]+=T;
    }
  }
  int best_mask=0;
  int best_wait=INF;
  for(int mask=0;mask<(1<<M);mask++){
    int cost=0;
    for(int i=0;i<M;i++){
      if(mask&(1<<i)){
	cost+=ps[i];
      }
    }
    if(cost>B) continue;
    int wait=0;
    for(int i=0;i<N;i++){
      wait=std::max(wait,child_deg[i]);
    }
    for(int i=0;i<M;i++){
      if(mask&(1<<i)){
	wait=std::max(wait,(machine_deg[i]+1)/2);
      }else{
	wait=std::max(wait,machine_deg[i]);
      }
    }
    if(wait<best_wait){
      best_wait=wait;
      best_mask=mask;
    }
  }
  printf("%d\n",best_wait);
  for(int i=0;i<M;i++){
    printf("%d",(best_mask>>i)&1);
  }
  printf("\n");
  for(int j=0;j<M;j++){
    if(best_mask&(1<<j)){
      machine_deg[j]=(machine_deg[j]+1)/2;
    }
    int flag=0;
    for(int i=0;i<N;i++){
      int use=std::min(machine_deg[j],desire[i][j]);
      add_edge(i,(j<<1)|flag,use);
      machine_deg[j]-=use;
      desire[i][j]-=use;
      if(desire[i][j]>0){
	flag=1;
	machine_deg[j]=INF;
	i--;
      }
    }
  }
  /*
  for(int i=0;i<60;i++){
    for(int j=0;j<60;j++){
      printf("%d",graph[i][j]);
    }
    printf("\n");
    }
  */
  int T=0;
  while(true){
    int D=find_matching();
    if(D==0) break;
    int stay=INF;
    for(int i=0;i<60;i++){
      if(match[i]!=-1){
	stay=std::min(stay,graph[i][match[i]]);
      }else{
	stay=std::min(stay,D-deg[i]);
      }
    }
    for(int i=0;i<N;i++){
      if(match[i]!=-1){
	segments.push_back({i+1,(match[i]-N)/2+1,T,stay});
	graph[i][match[i]]-=stay;
	graph[match[i]][i]-=stay;
      }
    }
    T+=stay;
  }
  printf("%d\n",(int)segments.size());
  for(std::array<int,4> seg:segments){
    printf("%d %d %d %d\n",seg[0],seg[1],seg[2],seg[3]);
  }
  return 0;
}