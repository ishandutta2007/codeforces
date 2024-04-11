#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int opt[2000000];
int lis(int n,int d[]){
  int i,k,left,right;
  int opt_size;

  if(!n) return 0;

  opt_size=1; opt[0]=d[0];
  REP(i,1,n){
    if(opt[opt_size-1]<d[i]){
      opt[opt_size]=d[i]; opt_size++;
      continue;
    }
    if(opt[0]>=d[i]){
      opt[0]=d[i]; continue;
    }
    left=1; right=opt_size-1;
    for(;;){
      k=(left+right)/2;
      if(d[i]<=opt[k]&&opt[k-1]<d[i]) break;
      if(d[i]<=opt[k]) right=k-1; else left=k+1;
    }
    opt[k]=d[i];
  }

  return opt_size;
}


int in[2000000];
int a[2000000], b[2000000];
int A[2000000], B[2000000];

int main(){
  int i,j,k,l,m,n;

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",a+i), a[i]--;
    rep(i,n) scanf("%d",b+i), b[i]--;

    rep(i,n) A[a[i]]=i, B[b[i]]=i;
    rep(i,n) in[A[i]] = B[i];

    rep(i,n) in[i] = -in[i];
    k = lis(n,in);
    printf("%d\n",k);
  }

  return 0;
}