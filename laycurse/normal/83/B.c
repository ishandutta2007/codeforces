#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int i,j,k,l,m,n,rest;
  ll sum, all;
  int in[120000], num[120000];
  ll a, b, c, tmp;

  while(scanf("%d%I64d",&n,&all)==2){
    rep(i,n) scanf("%d",in+i);
    sum = 0; rep(i,n) sum += in[i];

    if(sum < all){ puts("-1"); continue; }

    a = 0; b = 10000000000LL;
    while(a<b){
      c = (a+b+1)/2;
      tmp = 0;
      rep(i,n){
        if(c < in[i]) tmp += c;
        else          tmp += in[i];
      }

      if(tmp > all) b = c-1; else a = c;
    }

    rep(i,n){
      tmp = in[i];
      if(in[i] > a) tmp = a;
      all -= tmp; in[i] -= tmp;
    }

    rest = 0;
    rep(i,n) if(in[i]) num[rest] = in[i], in[rest++] = i;

    rep(i,rest){
      if(all+i >= rest && num[(all+i)%rest]==1) continue;
      if(i) putchar(' ');
      printf("%d",in[(all+i)%rest]+1);
    }
    puts("");
  }

  return 0;
}