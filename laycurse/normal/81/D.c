#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int br;

void out(int x){
  if(br) putchar(' '); else br = 1;
  printf("%d",x+1);
}

int main(){
  int i,j,k,l,m,n,now;
  int in[50], ind[50], res[1100], sum;

  while(scanf("%d%d",&n,&m)==2){
    rep(i,m) scanf("%d",in+i);
    rep(i,m) ind[i] = i;

    rep(i,m) in[i]*=-1;
    intIntSort(in,ind,m);
    rep(i,m) in[i]*=-1;

    now = 0;
    rep(i,n) res[i] = -1;
    rep(i,m){
      while(in[i]>0){
        if(res[(now+1)%n]==ind[i] || res[(now+n-1)%n]==ind[i]) break;
        res[now] = ind[i]; in[i]--;
        now += 2;
        if(now >= n && now%2) break;
        if(now >= n) now = 1;
      }
      if(now >= n && now%2) break;
    }

    rep(i,n) if(res[i]==res[(i+1)%n] || res[i]==-1) break;
    if(i!=n){puts("-1"); continue;}
    br = 0;
    rep(i,n) out(res[i]);
    puts("");
  }

  return 0;
}