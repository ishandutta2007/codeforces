#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void intIntSort(int d[],int m[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;t=m[i];m[i]=m[j];m[j]=t;}intIntSort(d,m,i);intIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int i,j,l,m,n;
  int k[2000], c[2000];
  ll p[110], t, f, num, go;
  ll res;

  scanf("%d",&n);
  rep(i,n) scanf("%d%d",k+i,c+i);
  scanf("%I64d",&t);
  rep(i,t) scanf("%I64d",p+i);
  p[t] = 1000000000000000000LL;

  intIntSort(c,k,n);

  res = 0;
  num = 0;
  f = 0;

  m = 0;
  while(m < n){
    go = p[f] - num;
    if(go > k[m]) go = k[m];

    res += go * c[m] * (f+1);
    k[m] -= go;
    num += go;

    if(k[m] <= 0) m++;
    while(num == p[f]) f++;
  }

  printf("%I64d\n",res);

  return 0;
}