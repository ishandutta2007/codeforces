#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int i,j,k,l,m,n,ok;
  int a,b,c,d;
  int edge[30][30];
  int node[30];

  node[0]=1; node[1]=2; k=3;
  REP(i,2,20){
    for(;;){
      node[i]=node[i-1]+k++;
      ok=1;
      rep(a,i+1) REP(b,a+1,i+1) rep(c,i+1) REP(d,c+1,i+1){
        if(a==c && b==d) continue;
        if(node[a]+node[b]==node[c]+node[d]) ok=0;
      }
      if(ok) break;
    }
  }

  scanf("%d",&n); k=1;
  rep(i,n) edge[i][i]=0;
  rep(i,n) REP(j,i+1,n) edge[i][j]=edge[j][i]=node[i]+node[j];
  rep(i,n) {
    rep(j,n){
      if(j) putchar(' ');
      printf("%d",edge[i][j]);
    }
    puts("");
  }

  /*
  int loop=10;
  int go[30], ind[30];
  rep(i,n) go[i]=i;
  while(loop--){
    rep(i,n) ind[i]=rand()%10000;
    intIntSort(ind,go,n);
    k=0;
    rep(i,n) k += edge[go[i]][go[(i+1)%n]];
    printf("%d\n",k);
  }
  */
  return 0;
}