#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[100001], cnt[100001];

  while(scanf("%d",&n)==1){
    rep(i,100001) cnt[i]=0;
    rep(i,n) scanf("%d",in+i), cnt[in[i]]++;
    REP(i,2,100001) if(cnt[i-1]<cnt[i]) break;
    if(i!=100001){puts("-1"); continue;}
    printf("%d\n",cnt[1]);
    rep(i,n){
      if(i) putchar(' ');
      printf("%d",cnt[in[i]]--);
    }
    puts("");
  }

  return 0;
}