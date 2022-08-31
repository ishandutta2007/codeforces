#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}
void intIntIntSort(int d[],int m1[],int m2[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m1[i];m1[i]=m1[j];m1[j]=t;t=m2[i];m2[i]=m2[j];m2[j]=t;}intIntIntSort(d,m1,m2,i);intIntIntSort(d+j+1,m1+j+1,m2+j+1,s-j-1);}

int a[200000], b[200000], ind[200000];
int res[100000];

int main(){
  int i,j,k,l,m,n,nn,add;
  long long sa;
  int size;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n); nn=n*2-1;
    rep(i,nn) scanf("%d%d",a+i,b+i), ind[i]=i+1;
    intIntIntSort(a,b,ind,nn);

    sa = 0;
    rep(i,nn-1){
      if(i%2==0) sa += b[i];
      else       sa -= b[i];
    }
    if(sa < 0) add = 1; else add = 0;
    rep(i,n-1) res[i] = ind[2*i+add];
    res[n-1] = ind[nn-1];
    intSort(res,n);

    puts("YES");
    rep(i,n){
      if(i) putchar(' ');
      printf("%d",res[i]);
    }
    puts("");
  }

  return 0;
}