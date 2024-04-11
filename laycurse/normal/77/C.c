#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

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

void llSort(ll d[],int s){int i,j;ll k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;i=-1;j=s;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}llSort(d,i);llSort(d+j+1,s-j-1);}

intVector edge[111111];
int in[111111];
ll dp[111111], amari[111111], st[111111];


void solve(int now,int bef){
  int i,j,k,gogo,sz;
  ll res, amari_sum, tmp;

  rep(i,edge[now].size) if(edge[now].d[i]!=bef) solve(edge[now].d[i], now);

  if(in[now] < 1){ dp[now] = -1; return; }

  dp[now] = 1;
  amari[now] = 0; amari_sum = 0;

  gogo = in[now]-1;
  sz = 0;
  rep(i,edge[now].size){
    j = edge[now].d[i];
    if(j==bef) continue;
    if(dp[j]>=0){
      st[sz++] = dp[j];
      amari_sum += amari[j];
    }
  }
  llSort(st,sz);

  for(i=sz-1;i>=0;i--) if(gogo>0) {
    gogo--;
    dp[now] += st[i]+1;
  }

  if(gogo){
    tmp = gogo;
    if(tmp > amari_sum) tmp = amari_sum;
    gogo -= tmp;
    dp[now] += tmp*2;
  }

  amari[now] = gogo;

/*  printf("%d %d : %lld %lld\n",now,bef,dp[now],amari[now]);*/
}


int main(){
  int i,j,k,l,m,n,st;
  ll res;

  rep(i,111111) edge[i] = intVectorNull();

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);
    rep(i,n) edge[i].size = 0;
    rep(k,n-1){
      scanf("%d%d",&i,&j); i--; j--;
      intVectorPushBack(edge+i,j);
      intVectorPushBack(edge+j,i);
    }
    scanf("%d",&st); st--;

    in[st]++;
    solve(st,-1);
    dp[st]--;
    if(dp[st]<0) dp[st] = 0;
    printf("%I64d\n",dp[st]);
  }



  return 0;
}