#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int cnt[26];
  char in[1200];

  scanf("%s%d",in,&n);
  rep(i,26) cnt[i] = 0;
  m = strlen(in);
  rep(i,m) cnt[in[i]-'a']++;

  REP(k,1,1200){
    m = 0;
    rep(i,26) m += (cnt[i]+k-1)/k;

    if(m <= n){
      printf("%d\n",k);
      while(m < n) putchar('a'), m++;
      rep(i,26){
        m = (cnt[i]+k-1)/k;
        while(m--) putchar('a'+i);
      }
      puts("");
      break;
    }

  }

  if(k==1200) puts("-1");

  return 0;
}