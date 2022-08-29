#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int in[200000], next[200000][20];
int ap[3000000];

int main(){
  int i,j,k,l,m,n,b;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i);

  rep(i,3000000) ap[i] = 0;

  rep(j,20) next[n-1][j] = -1;
  for(i=n-2;i>=0;i--){
    rep(j,20) next[i][j] = next[i+1][j];
    rep(j,20) if(in[i+1]&(1<<j)) next[i][j] = i+1;
  }

  rep(i,n){
    k = in[i];
    ap[k]=1;
    j = i;
    for(;;){
      m = 1000000000;
      rep(b,20) if(!(k&1<<b)) if(next[j][b]!=-1 && m > next[j][b]) m = next[j][b];
      if(m==1000000000) break;
      j = m;
      k |= in[j];
      ap[k]=1;
    }
  }

  k = 0;
  rep(i,3000000) k += ap[i];
  printf("%d\n",k);

  return 0;
}