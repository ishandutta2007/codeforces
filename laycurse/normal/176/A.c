#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int i,j,k,l,m,n,lim,go;
  int a[10][100], b[10][100], c[10][100];
  int gain[100], num[100];
  int res = 0, tmp;

  scanf("%d%d%d",&n,&m,&lim);
  rep(i,n){
    scanf("%*s");
    rep(j,m) scanf("%d%d%d",a[i]+j, b[i]+j, c[i]+j);
  }
  rep(i,n) rep(j,n) if(i!=j){
    rep(k,m){
      gain[k] = b[j][k] - a[i][k];
      num[k] = c[i][k];
    }
    intIntSort(gain, num, m);
    l = lim;
    tmp = 0;
    for(k=m-1;k>=0;k--){
      if(gain[k] < 0) break;
      go = l;
      if(go > num[k]) go = num[k];
      l -= go;
      tmp += gain[k] * go;
    }
    if(res < tmp) res = tmp;
  }

  printf("%d\n",res);

  return 0;
}