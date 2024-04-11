#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}
int ps, p[1000010], isp[1000010];

int main(){
  int i,j,k,l,m,n;
  int a, b, res, sum;

  ps = getPrime(1000000, p);
  rep(i,1000001) isp[i] = 0;
  rep(i,ps) isp[p[i]] = 1;
  
  scanf("%d%d%d",&a,&b,&k);

  m = 0;
  REP(i,a,b+1) m += isp[i];
  if(m<k){ puts("-1"); return 0; }

  res = 0;
  j = a; sum = 0;
  REP(i,a,b+1){
    while(j <= b && sum < k){
      sum += isp[j];
      j++;
    }
    if(sum < k){
      if(res < j-i+1) res = j-i+1;
      break;
    }
    if(res < j-i) res = j-i;
    sum -= isp[i];
  }

  printf("%d\n",res);

  return 0;
}