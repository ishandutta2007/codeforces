#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 2000000

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

void eratosthenes(int n,int p[]){
  int i,j;
  p[0]=p[1]=0; REP(i,2,n) p[i]=1;
  for(i=4;i<n;i+=2) p[i]=0;
  for(i=3;i*i<n;i+=2) if(p[i]) for(j=i;i*j<n;j+=2) p[i*j]=0;
}

int p[N];
int in[200000];

int main(){
  int i,j,k,l,m,n,x;
  int st, res;

  eratosthenes(N,p);

  while(scanf("%d%d",&n,&x)==2){
    rep(i,n) scanf("%d",in+i);
    intSort(in,n);

    if(x==2){ puts("0"); continue; }
    if(n && in[0]==1){ puts("1"); continue; }

    if(x >= N-10){ puts("-1"); continue; }

    res = 0;
    st = 0;
    REP(i,2,x) if(p[i]){
      while(st < n && in[st] < i) st++;
      if(st==n || in[st]>i){ res=-1; break; }

      res++;
    }

    printf("%d\n",res);
  }


  return 0;
}