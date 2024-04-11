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

intVector edge[200000];

int chk[200000];

int both_ele[200000];
int acon_ele[200000];
int bcon_ele[200000];

int main(){
  int i,j,k,l,m,n;
  int h, t;
  int a, an, b;
  int acon, bcon, both, husoku;
  int fin = 0;

  rep(i,200000) edge[i] = intVectorNull();

  scanf("%d%d%d%d",&n,&m,&h,&t);
  rep(i,n) edge[i].size = 0;

  while(m--){
    scanf("%d%d",&i,&j);
    i--; j--;
    intVectorPushBack(edge+i,j);
    intVectorPushBack(edge+j,i);
  }

  rep(i,n) chk[i] = -1;
  
  rep(a,n) if(!fin) {
    if(edge[a].size - 1 < h) continue;
    rep(k,edge[a].size) chk[edge[a].d[k]] = a;
    
    rep(an,edge[a].size) if(!fin) {
      b = edge[a].d[an];
      if(edge[b].size - 1 < t) continue;
      both = 0;
      rep(k,edge[b].size){
        l = edge[b].d[k];
        if(chk[l]==a) both++;
      }
      acon = edge[a].size - both - 1;
      bcon = edge[b].size - both - 1;
      husoku = 0;
      if(h-acon > 0) husoku += h-acon;
      if(t-bcon > 0) husoku += t-bcon;

      if(husoku <= both){
        acon = bcon = both = 0;
        rep(k,edge[b].size){
          l = edge[b].d[k];
          if(chk[l]==a) both_ele[both++] = l;
          else if(l!=a) bcon_ele[bcon++] = l;
          chk[l] = n+1;
        }
        rep(k,edge[a].size){
          l = edge[a].d[k];
          if(chk[l] != n+1 && l!=b) acon_ele[acon++] = l;
        }

        while(acon < h) acon_ele[acon++] = both_ele[--both];
        while(bcon < t) bcon_ele[bcon++] = both_ele[--both];

        puts("YES");
        printf("%d %d\n", a+1, b+1);
        rep(i,h){
          if(i) putchar(' ');
          printf("%d",acon_ele[i]+1);
        }
        puts("");
        rep(i,t){
          if(i) putchar(' ');
          printf("%d",bcon_ele[i]+1);
        }
        puts("");
        fin = 1;
      }
    }
  }

  if(!fin) puts("NO");

  return 0;
}