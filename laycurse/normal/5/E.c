#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef struct struct_int_minimul_search_tree{
  int node, memory, range;
  int *left, *right, *a, *b, *min_element;
  int *data;
} intMinSearchTree;

intMinSearchTree intMinSearchTreeMake(int memory){
  intMinSearchTree t;
  int m2 = memory*2-1;

  t.memory= memory;
  t.left  = (int*) malloc(m2 * sizeof(int));
  t.right = (int*) malloc(m2 * sizeof(int));
  t.a     = (int*) malloc(m2 * sizeof(int));
  t.b     = (int*) malloc(m2 * sizeof(int));
  t.min_element = (int*) malloc(m2 * sizeof(int));
  t.data  = (int*) malloc(memory * sizeof(int));

  return t;
}

void intMinSearchTreeDelete(intMinSearchTree t){
  free(t.left); free(t.right); free(t.a); free(t.b); free(t.min_element); free(t.data);
}

void intMinSearchTreeSetInitializeSub(intMinSearchTree *t, int node){
  int n1,n2,size;
  size = t->b[node] - t->a[node];
  if(size==1) return;

  t->left[node]  = n1 = t->node++;
  t->right[node] = n2 = t->node++;

  t->a[n1] = t->a[node]; t->b[n2] = t->b[node];
  t->b[n1] = t->a[n2] = t->a[node]+size/2;

  intMinSearchTreeSetInitializeSub(t,n1);
  intMinSearchTreeSetInitializeSub(t,n2);
}

void intMinSearchTreeSetInitialize(intMinSearchTree *t, int element_size){
  t->node=1; t->range=element_size; t->a[0]=0; t->b[0]=element_size;
  intMinSearchTreeSetInitializeSub(t,0);
}


void intMinSearchTreeSetConstructionSub(intMinSearchTree *t, int st, int ed, int node){
  int size,n1,n2;
  if(ed <= t->a[node] || t->b[node]<=st) return;
  size = t->b[node] - t->a[node];
  n1=t->left[node]; n2=t->right[node];

  if(size==1){ t->min_element[node]=t->a[node]; return; }
  intMinSearchTreeSetConstructionSub(t,st,ed,n1); intMinSearchTreeSetConstructionSub(t,st,ed,n2);
  if( t->data[ t->min_element[n1] ] <= t->data[ t->min_element[n2] ] ) t->min_element[node] = t->min_element[n1];
  else t->min_element[node] = t->min_element[n2];
}

/*  [st,ed) data */
/* initialize  st=0, ed=element_size  */
void intMinSearchTreeSetConstruction(intMinSearchTree *t, int st, int ed){
  intMinSearchTreeSetConstructionSub(t,st,ed,0);
}

int intMinSearchTreeSearchSub(intMinSearchTree *t, int st, int ed, int node){
  int n1,n2,res,k1,k2;

  if(st < t->a[node]) st = t->a[node];
  if(ed > t->b[node]) ed = t->b[node];
  if(st >= ed) return -1;
  if( st==t->a[node] && ed==t->b[node] ) return t->min_element[node];

  n1 = t->left[node]; n2 = t->right[node];
  k1 = intMinSearchTreeSearchSub(t,st,ed,n1); k2 = intMinSearchTreeSearchSub(t,st,ed,n2);
  if(k1==-1) return k2; if(k2==-1) return k1;
  if(t->data[k1] <= t->data[k2]) return k1; return k2;
}

int intMinSearchTreeSearch(intMinSearchTree *t, int st, int ed){
  return intMinSearchTreeSearchSub(t,st,ed,0);
}



#define ll long long

intMinSearchTree t;
int in[2222222], lis[2222222], liss;
ll res;

int st_st[5222222], st_ed[5222222], st_fg[5222222], st_size;

void solve(void){
  int i,j,k,m,sz; ll go;
  int st,ed,fg;

  while(st_size){
    st=st_st[--st_size]; ed=st_ed[st_size]; fg=st_fg[st_size];

    if(st>ed) continue;
    k=intMinSearchTreeSearch(&t,st,ed+1);
    
    sz=0;
    lis[sz++]=st-1; lis[sz++]=k;
    for(;;){
      m=lis[sz-1];
      if(m==ed) break;
      k=intMinSearchTreeSearch(&t,m+1,ed+1);
      if(in[k]!=in[m]) break;
      lis[sz++]=k;
    }
    lis[sz++]=ed+1;

    go = fg + sz - 2;
    res += go*(go-1)/2;
    if(fg==2) res--;
    
    REP(i,1,sz) st_st[st_size]=lis[i-1]+1, st_ed[st_size]=lis[i]-1, st_fg[st_size]=2, st_size++;
  }
}

int main(){
  int i,j,k,l,m,n;
  int mx, mxs;
  ll go;

  t = intMinSearchTreeMake(2222222);
  res=0;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i);
  rep(i,n) in[n+i]=in[i];

  intMinSearchTreeSetInitialize(&t,2*n);
  rep(i,2*n) t.data[i]=-in[i];
  intMinSearchTreeSetConstruction(&t,0,2*n);

  mx=-1; liss=0;
  rep(i,n) if(mx<in[i]) mx=in[i];
  rep(i,n) if(mx==in[i]) lis[liss++]=i;

  st_size=0;
  lis[liss]=lis[0]+n;
  if(liss==1){
    st_st[st_size]=lis[0]+1; st_ed[st_size]=lis[1]-1; st_fg[st_size]=1; st_size++;
  } else {
    go=liss; res += go*(go-1)/2;
    rep(i,liss) st_st[st_size]=lis[i]+1, st_ed[st_size]=lis[i+1]-1, st_fg[st_size]=2, st_size++;
  }

  solve();
  printf("%I64lld\n",res);
  
  return 0;
}