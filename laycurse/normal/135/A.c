#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int in[110000];

int main(){
  int i,j,k,l,m,n;

  scanf("%d",&n);
  rep(i,n) scanf("%d",in+i);
  intSort(in,n);

  if(in[n-1]==1){
    in[n-1] = 2;
  } else {
    for(i=n-2;i>=0;i--) in[i+1] = in[i];
    in[0] = 1;
  }

  rep(i,n){
    if(i) putchar(' ');
    printf("%d",in[i]);
  }
  puts("");

  return 0;
}