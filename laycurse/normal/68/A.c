#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int main(){
  int in[4], a, b;

  while(scanf("%d%d%d%d%d%d",in,in+1,in+2,in+3,&a,&b)==6){
    intSort(in,4);
    if(b > in[0]-1) b = in[0] - 1;
    a = b - a + 1;
    if(a < 0) a = 0;
    printf("%d\n",a);
  }

  return 0;
}