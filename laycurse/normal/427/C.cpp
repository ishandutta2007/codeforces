#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

typedef struct struct_kdyenbxjdhd{
  int node, nodeMemory;
  int *edgeSize, *edgeMemory;
  int **edge;
}ListGraph;

ListGraph NewListGraph(int maxNode,int maxDegree){
  int i; ListGraph res;
  res.node=0; res.nodeMemory=maxNode;
  res.edgeSize   = (int*)malloc(maxNode*sizeof(int));
  res.edgeMemory = (int*)malloc(maxNode*sizeof(int));
  res.edge = (int**)malloc(maxNode*sizeof(int*));
  rep(i,maxNode) res.edgeMemory[i]=maxDegree;
  if(maxDegree) rep(i,maxNode) res.edge[i]=(int*)malloc(maxDegree*sizeof(int));
  return res;
}

void DeleteListGraph(ListGraph g){
  int i;
  rep(i,g.nodeMemory) if(g.edgeMemory[i]) free(g.edge[i]);
  free(g.edgeSize); free(g.edgeMemory); free(g.edge);
}

void ListGraphSetEmpty(ListGraph *g,int node){
  int i;
  g->node = node;
  rep(i,node) g->edgeSize[i]=0;
}

void ListGraphAddEdge(ListGraph *g,int node1,int node2){
  int s=g->edgeSize[node1]++;
  g->edge[node1][s]=node2;
}

void ListGraphAddBidirectedEdge(ListGraph *g,int node1,int node2){
  int s1,s2;
  if(node1==node2){
    s1=g->edgeSize[node1]++;
    g->edge[node1][s1]=node2;
  } else {
    s1=g->edgeSize[node1]++, s2=g->edgeSize[node2]++;
    g->edge[node1][s1]=node2; g->edge[node2][s2]=node1;
  }
}

/* edgeMemory[k]=size */
/* fg=1 edgeMemory[k]>=size */
void ListGraphOneEdgeReallocEasy(ListGraph *g,int k,int size,int fg){
  if(fg==1 && g->edgeMemory[k]>=size) return;
  if(g->edgeMemory[k]==size) return;
  if(g->edgeMemory[k]) free(g->edge[k]);
  g->edgeMemory[k]=size;
  g->edge[k] = (int*)malloc(size*sizeof(int));
}

/* g.nodeedge */
void ListGraphSetDirectEdges(ListGraph *g,int from[],int to[],int size){
  int i,n=g->node;
  rep(i,n) g->edgeSize[i]=0;

  rep(i,size) g->edgeSize[from[i]]++;
  rep(i,n) {ListGraphOneEdgeReallocEasy(g,i,g->edgeSize[i],1); g->edgeSize[i]=0;}
  rep(i,size) ListGraphAddEdge(g,from[i],to[i]);
}

void ListGraphSetBidirectEdges(ListGraph *g,int from[],int to[],int size){
  int i,n=g->node;
  rep(i,n) g->edgeSize[i]=0;

  rep(i,size) g->edgeSize[from[i]]++, g->edgeSize[to[i]]++;
  rep(i,n) {ListGraphOneEdgeReallocEasy(g,i,g->edgeSize[i],1); g->edgeSize[i]=0;}
  rep(i,size) ListGraphAddBidirectedEdge(g,from[i],to[i]);
}

/* stDFSmx+1return */
int ListGraphStronglyConnectedComponentsDFS(ListGraph *g,int num[],int st,int mx){
  int i,j,n=g->node;
  num[st]=-2;
  rep(i,g->edgeSize[st]) {
    j=g->edge[st][i]; if(num[j]==-1) mx=ListGraphStronglyConnectedComponentsDFS(g,num,j,mx);
  }
  num[st]=mx; return mx+1;
}

/*  */
/* grev() */
/* res[i]=res[j]ij */
/* return res+1 =  */
int ListGraphStronglyConnectedComponents(ListGraph *g,ListGraph *rev,int res[],void *WorkMemory){
  int i,j,k,n=g->node,ret=0;
  int *st, st_size, *num, *nrv;

  st  = (int*) WorkMemory; WorkMemory = (void*)(st  + n);
  num = (int*) WorkMemory; WorkMemory = (void*)(num + n);
  nrv = (int*) WorkMemory;

  rep(i,n) res[i]=num[i]=-1; k=0;
  rep(i,n) if(num[i]==-1) k=ListGraphStronglyConnectedComponentsDFS(g,num,i,k);
  rep(i,n) nrv[num[i]]=i;

  for(k=n-1;k>=0;k--) {
    i=nrv[k]; if(res[i]>=0)continue;
    res[i]=ret; st_size=0; st[st_size++]=i;
    while(st_size){
      i=st[--st_size];
      rep(j,rev->edgeSize[i])
        if(res[rev->edge[i][j]]==-1) res[rev->edge[i][j]]=ret, st[st_size++]=rev->edge[i][j];
    }
    ret++;
  }

  return ret;
}

int N, M, u[400000], v[400000], c[200000];
int com[200000];
vector<int> cost[200000];

int main(){
  int i, j, k, x;
  ll res1, res2;
  ListGraph g = NewListGraph(110000, 0);
  ListGraph r = NewListGraph(110000, 0);
  void *mem = malloc(40000000);

  reader(&N);
  rep(i,N) reader(c+i);
  reader(&M);
  rep(i,M) reader(u+i), reader(v+i), u[i]--, v[i]--;

  g.node = r.node = N;
  ListGraphSetDirectEdges(&g, u, v, M);
  ListGraphSetDirectEdges(&r, v, u, M);

  res1 = 0; res2 = 1;
  x = ListGraphStronglyConnectedComponents(&g, &r, com, mem);

  rep(i,N) cost[com[i]].push_back(c[i]);
  rep(i,x){
    sort(cost[i].begin(), cost[i].end());
    res1 += cost[i][0];
    rep(j,cost[i].size()) if(cost[i][0] != cost[i][j]) break;
    res2 = res2 * j % 1000000007;
  }

  writer(res1, ' ');
  writer(res2, '\n');

  myed;
  return 0;
}