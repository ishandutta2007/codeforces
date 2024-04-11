#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef struct struct_vector_int{ int size,mem; int *d; }intVector;
intVector intVectorNull(){ intVector v; v.size=v.mem=0; return v; }

void intVectorMemoryExpand(intVector *v){
  int i, *t, m;
  m=v->mem*2; if(m<5) m=5;
  t=(int*)malloc(m*sizeof(int));
  rep(i,v->size) t[i]=v->d[i];
  if(v->mem) free(v->d);
  v->d=t; v->mem=m;
}

void intVectorPushBack(intVector *v,int add){
  if(v->mem==v->size) intVectorMemoryExpand(v);
  v->d[(v->size)++] = add;
}




int a[100000], b[100000];
intVector edge[100000], num[100000];
int deg[100000];
int up[100000], upedge[100000];

void gen(int node, int bef, int e){
  int i, k;
  up[node] = bef;
  upedge[node] = e;

  rep(i,edge[node].size){
    k = edge[node].d[i];
    if(k==bef) continue;
    gen(k, node, num[node].d[i]);
  }

  if(e>=0){
    rep(i,edge[node].size){
      k = edge[node].d[i];
      if(k==bef) continue;
      printf("%d %d\n",e,upedge[k]);
    }
  }
}

int main(){
  int i,j,k,l,m,n;
  int root;

  rep(i,100000) edge[i] = num[i] = intVectorNull();

  scanf("%d",&n);

  rep(i,n) deg[i] = 0;

  rep(i,n-1){
    scanf("%d%d",&j,&k);
    j--; k--;
    a[i] = j; b[i] = k;
    intVectorPushBack(edge+j, k);
    intVectorPushBack(edge+k, j);
    intVectorPushBack(num+j, i+1);
    intVectorPushBack(num+k, i+1);

    deg[j]++; deg[k]++;
  }

  printf("%d\n",n-1);
  rep(i,n-1) printf("2 %d %d\n",a[i]+1,b[i]+1);

  rep(root,n) if(deg[root]==1) break;
  gen(root, -1, -1);

  return 0;
}