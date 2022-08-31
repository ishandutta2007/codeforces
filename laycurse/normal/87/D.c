#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

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

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int sum[],int a,int b){
  a=unionGet(d,a);
  b=unionGet(d,b);
  if(a==b)return 0;
  d[a]=b;
  sum[b] += sum[a];
  return 1;
}



ll res[100000];

intVector edge[100000], edge_num[100000];
int weight[100000];

int reached[100000];
int up_node[100000], num_node[100000];

void go_down1(int now, int bef, int upup){
  int i,j,k;
  
  reached[now] = 1;
  num_node[now] = weight[now];
  up_node[now] = upup;

  rep(i,edge[now].size){
    k = edge[now].d[i];
    if(k==bef) continue;

    go_down1(k,now,upup);
    num_node[now] += num_node[k];
  }
}

void go_down2(int now, int bef, int upup){
  int i,j,k;
  ll go;
  
  reached[now] = 1;

  rep(i,edge[now].size){
    k = edge[now].d[i];
    if(k==bef) continue;

    go_down2(k,now,upup);

    j = edge_num[now].d[i];

    go = num_node[k];
    go *= num_node[upup] - num_node[k];

/*    printf("res %d : %d * %d = %lld (%d %d %d)\n",j,num_node[k],num_node[upup]-num_node[k],go,upup,k,now);*/

    res[j] = go;
  }
}

void solve(int node){
  int i,j,k;

/*  puts("");
  printf("node = %d\n",node);
  rep(i,node) printf("weight %d : %d\n",i,weight[i]);
  rep(i,node) rep(j,edge[i].size) printf("%d <-> %d (num = %d)\n",i,edge[i].d[j],edge_num[i].d[j]);
  puts("");*/

  rep(i,node) reached[i] = 0;
  rep(i,node) if(!reached[i]) go_down1(i,-1,i);

  rep(i,node) reached[i] = 0;
  rep(i,node) if(!reached[i]) go_down2(i,-1,i);
}


int a[100000], b[100000], d[100000];
int edge_val[100000], edge_ind[100000];

int ind[100000], sum[100000];

int use[100000], use_fg[100000], use_size;
int use_num[100000];

int main(){
  int i,j,k,l,m,n,ii;
  int st, ed;
  ll mx; int cnt, br;

  rep(i,100000) edge[i] = edge_num[i] = intVectorNull();

  while(scanf("%d",&n)==1){
    rep(i,n-1) scanf("%d%d%d",a+i,b+i,d+i), a[i]--, b[i]--;

    rep(i,n-1) edge_val[i] = d[i], edge_ind[i] = i;
    intIntSort(edge_val, edge_ind, n-1);

    rep(i,n) ind[i] = i, sum[i] = 1;
    rep(i,n) use_fg[i] = -1;

    for(st=0;st<n-1;){
      ed = st+1;
      while(ed < n-1 && edge_val[ed]==edge_val[st]) ed++;

      use_size = 0;
      REP(ii,st,ed){
        i = edge_ind[ii];
        k = unionGet(ind,a[i]);
        if(use_fg[k]!=st) use[use_size] = k, use_fg[k]=st, use_num[k] = use_size, use_size++;
        k = unionGet(ind,b[i]);
        if(use_fg[k]!=st) use[use_size] = k, use_fg[k]=st, use_num[k] = use_size, use_size++;
      }

      rep(i,use_size) edge[i].size = edge_num[i].size = 0;
      rep(i,use_size) weight[i] = sum[use[i]];
      REP(ii,st,ed){
        i = edge_ind[ii];
        j = use_num[unionGet(ind,a[i])];
        k = use_num[unionGet(ind,b[i])];
        intVectorPushBack(edge+j,k); intVectorPushBack(edge_num+j,edge_ind[ii]);
        intVectorPushBack(edge+k,j); intVectorPushBack(edge_num+k,edge_ind[ii]);
      }

      solve(use_size);

      REP(ii,st,ed){
        i = edge_ind[ii];
        unionConnect(ind,sum,a[i],b[i]);
      }
/*      rep(i,n) printf("::: %d %d %d\n",i,unionGet(ind,i),sum[unionGet(ind,i)]);*/
      st = ed;
    }

    mx = res[0];
    rep(i,n-1) if(mx < res[i]) mx = res[i];
    cnt = 0;
    rep(i,n-1) if(mx==res[i]) cnt++;

/*    rep(i,n-1) printf("[%d %lld]\n",i,res[i]); continue;*/

    br = 0;
    printf("%I64d %d\n",mx*2,cnt);
    rep(i,n-1) if(mx==res[i]){
      if(br) putchar(' '); else br = 1;
      printf("%d",i+1);
    }
    puts("");
  }

  return 0;
}