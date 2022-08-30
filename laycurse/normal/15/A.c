#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int i,j,k,l,m,n,t;
  int a[1000],b[1000];
  int res;

  scanf("%d%d",&n,&t);
  rep(i,n) scanf("%d%d",a+i,b+i);
  intIntSort(a,b,n);
  rep(i,n) a[i]*=2;

  res=2;
  REP(i,1,n){
    if(a[i]-b[i]-(a[i-1]+b[i-1])== 2*t) res++;
    if(a[i]-b[i]-(a[i-1]+b[i-1]) > 2*t) res+=2;
  }
  printf("%d\n",res);

  return 0;
}