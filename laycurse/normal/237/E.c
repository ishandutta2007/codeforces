#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef struct struct_listgraphintcostintflow{
  int node, nodeMemory;
  int *edgeSize, *edgeMemory;
  int **edge, **cost, **flow, **reverse;
} ListGraphIntCostIntFlow;

ListGraphIntCostIntFlow NewListGraphIntCostIntFlow(int maxNode,int maxDegree){
  int i; ListGraphIntCostIntFlow res;
  res.node=0; res.nodeMemory=maxNode;
  res.edgeSize   = (int*)malloc(maxNode*sizeof(int));
  res.edgeMemory = (int*)malloc(maxNode*sizeof(int));
  res.edge = (int**)malloc(maxNode*sizeof(int*));
  res.cost = (int**)malloc(maxNode*sizeof(int*));
  res.flow = (int**)malloc(maxNode*sizeof(int*));
  res.reverse = (int**)malloc(maxNode*sizeof(int*));
  if(maxDegree){
    rep(i,maxNode) res.edge[i]=(int*)malloc(maxDegree*sizeof(int));
    rep(i,maxNode) res.cost[i]=(int*)malloc(maxDegree*sizeof(int));
    rep(i,maxNode) res.flow[i]=(int*)malloc(maxDegree*sizeof(int));
    rep(i,maxNode) res.reverse[i]=(int*)malloc(maxDegree*sizeof(int));
  }
  rep(i,maxNode) res.edgeMemory[i]=maxDegree;
  return res;
}

void DeleteListGraphIntCostIntFlow(ListGraphIntCostIntFlow g){
  int i;
  rep(i,g.nodeMemory) if(g.edgeMemory[i]){free(g.edge[i]); free(g.cost[i]); free(g.flow[i]); free(g.reverse[i]);}
  free(g.edgeSize); free(g.edgeMemory); free(g.edge); free(g.cost);
}

void ListGraphIntCostIntFlowSetEmpty(ListGraphIntCostIntFlow *g,int node){
  int i;
  g->node = node;
  rep(i,node) g->edgeSize[i]=0;
}

/* edgeMemory[k]=size */
/* fg=1 edgeMemory[k]>=size */
void ListGraphIntCostIntFlowOneEdgeReallocEasy(ListGraphIntCostIntFlow *g,int k,int size,int fg){
  if(fg==1 && g->edgeMemory[k]>=size) return;
  if(g->edgeMemory[k]==size) return;
  if(g->edgeMemory[k]){free(g->edge[k]); free(g->cost[k]); free(g->flow[k]); free(g->reverse[k]);}
  g->edgeMemory[k]=size;
  g->edge[k] = (int*)malloc(size*sizeof(int));
  g->cost[k] = (int*)malloc(size*sizeof(int));
  g->flow[k] = (int*)malloc(size*sizeof(int));
  g->reverse[k] = (int*)malloc(size*sizeof(int));
}

void ListGraphIntCostIntFlowAddEdge(ListGraphIntCostIntFlow *g,int node1,int node2,int cost,int flow){
  int s1,s2;
  s1=g->edgeSize[node1]++, s2=g->edgeSize[node2]++;
  g->edge[node1][s1]=node2; g->cost[node1][s1]= cost; g->flow[node1][s1]=flow; g->reverse[node1][s1]=s2;
  g->edge[node2][s2]=node1; g->cost[node2][s2]=-cost; g->flow[node2][s2]=0;    g->reverse[node2][s2]=s1;
}



void intHeapGoUp(int n,int hp[],int hpi[],int d[]){
  int k,m;
  if(!n) return;
  m=(n-1)/2;
  if(d[hp[m]]<=d[hp[n]]) return;
  k=hp[m]; hp[m]=hp[n]; hp[n]=k;
  hpi[hp[m]]=m; hpi[hp[n]]=n;
  intHeapGoUp(m,hp,hpi,d);
}

void intHeapGoDown(int n,int hp[],int hpi[],int hp_size,int d[]){
  int k,m;
  m=2*n+1; if(m>=hp_size) return;
  if(hp_size>m+1 && d[hp[m]]>d[hp[m+1]]) m++;
  if(d[hp[m]]>=d[hp[n]]) return;
  k=hp[m]; hp[m]=hp[n]; hp[n]=k;
  hpi[hp[m]]=m; hpi[hp[n]]=n;
  intHeapGoDown(m,hp,hpi,hp_size,d);
}

void intHeapInsert(int n,int hp[],int hpi[],int *hp_size,int d[]){
  hp[*hp_size]=n; hpi[n]=(*hp_size)++;
  intHeapGoUp((*hp_size)-1,hp,hpi,d);
}

int intHeapDelete(int hp[],int hpi[],int *hp_size,int d[]){
  int r=hp[0]; hpi[r]=-1;
  if( *hp_size==1 ){(*hp_size)--; return r;}
  hp[0]=hp[--(*hp_size)]; hpi[hp[0]]=0;
  intHeapGoDown(0,hp,hpi,*hp_size,d);
  return r;
}


/* INF=1000000000=unreachable */
/* ed=-1 */
/* flow */
void ListGraphIntCostIntFlowDijkstra(ListGraphIntCostIntFlow g,int st,int ed,int res_dist[],int res_back_node[],int res_back_edge[],void *WorkMemory){
  int i,j,k,n=g.node,hp_size=0; int c;
  int *hp, *hpi;

  hp  = (int*) WorkMemory; WorkMemory = (void*)( hp  + n );
  hpi = (int*) WorkMemory; WorkMemory = (void*)( hpi + n );

  rep(i,n) hpi[i]=-1, res_dist[i]=1000000000, res_back_node[i]=-1; res_dist[st]=0;
  intHeapInsert(st,hp,hpi,&hp_size,res_dist);
  while(hp_size){
    i = intHeapDelete(hp,hpi,&hp_size,res_dist);
    if(i==ed) break;
    rep(j,g.edgeSize[i]) if(g.flow[i][j]>0) {
      k=g.edge[i][j]; c=res_dist[i]+g.cost[i][j];
      if(res_dist[k] <= c) continue; res_dist[k]=c; res_back_node[k]=i; res_back_edge[k]=j;
      if(hpi[k]<0) intHeapInsert(k,hp,hpi,&hp_size,res_dist);
      else         intHeapGoUp(hpi[k],hp,hpi,res_dist);
    }
  }
}

/* g */
void ListGraphIntCostIntFlowMinCostFlow(ListGraphIntCostIntFlow g,int st,int ed,int flowLimit,int *res_flow,int *res_cost,void *WorkMemory){
  int i,j,k,l,flow_max;
  int *dist, *back_node, *back_edge;

  dist = (int*) WorkMemory; WorkMemory = (void*) (dist + g.node);
  back_node = (int*) WorkMemory; WorkMemory = (void*) (back_node + g.node);
  back_edge = (int*) WorkMemory; WorkMemory = (void*) (back_edge + g.node);
  
  *res_flow = *res_cost = 0;
  for(;;){
    if(flowLimit==0) break;
    
    ListGraphIntCostIntFlowDijkstra(g,st,-1,dist,back_node,back_edge,WorkMemory);
    if(back_node[ed]==-1) break;
    
    flow_max = flowLimit;
    k=ed;
    while(back_node[k]!=-1){
      i=back_node[k]; j=back_edge[k];
      if(flow_max > g.flow[i][j]) flow_max = g.flow[i][j];
      k=i;
    }
    k=ed;
    while(back_node[k]!=-1){
      i=back_node[k]; j=back_edge[k]; l=g.reverse[i][j];
      g.flow[i][j] -= flow_max; g.flow[k][l] += flow_max;
      k=i;
    }
    *res_flow += flow_max; *res_cost += flow_max * dist[ed];
    flowLimit -= flow_max;
  }
}



int main(){
  int i,j,k,l,m,n;

  int dic_size;
  char in[120]; int len;
  char dic[120][120]; int dic_len[120], dic_del[120];

  int in_c[120];
  int dic_c[120][120];

  int node, st, ed;
  ListGraphIntCostIntFlow g = NewListGraphIntCostIntFlow(3000, 110);
  int flow, cost;
  void *mem = malloc(30000000);

  scanf("%s",in);
  len = strlen(in);

  scanf("%d",&dic_size);
  rep(i,dic_size) scanf("%s%d",dic[i], dic_del+i), dic_len[i] = strlen(dic[i]);

  node = 26 + dic_size * 26 + dic_size;
  st = node++; ed = node++;
  ListGraphIntCostIntFlowSetEmpty(&g, node);

  rep(k,26) in_c[k] = 0;
  rep(i,dic_size) rep(k,26) dic_c[i][k] = 0;

  rep(i,len) in_c[in[i]-'a']++;
  rep(i,dic_size) rep(j,dic_len[i]) dic_c[i][dic[i][j]-'a']++;

  rep(i,26) if(in_c[i]) ListGraphIntCostIntFlowAddEdge(&g, st, i, 0, in_c[i]);
  rep(i,26) rep(j,dic_size){
    m = in_c[i];
    if(m > dic_c[j][i]) m = dic_c[j][i];
    if(m) ListGraphIntCostIntFlowAddEdge(&g, i, 26+26*j+i, 0, m);
  }

  rep(i,dic_size) rep(j,26) if(dic_c[i][j]) ListGraphIntCostIntFlowAddEdge(&g, 26+i*26+j, 26+26*dic_size+i, 0, dic_c[i][j]);

  rep(i,dic_size) ListGraphIntCostIntFlowAddEdge(&g, 26+26*dic_size+i, ed, i+1, dic_del[i]);

  ListGraphIntCostIntFlowMinCostFlow(g, st, ed, len, &flow, &cost, mem);

  if(flow != len) puts("-1");
  else            printf("%d\n", cost);

  return 0;
}