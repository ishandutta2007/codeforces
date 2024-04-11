#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,n;
  int cnt[101] = {};
  int res = 0;

  scanf("%d",&n);
  while(n--){
    scanf("%d",&i);
    cnt[i]++;
  }

  rep(i,101) res += cnt[i]/2;
  res /= 2;
  printf("%d\n",res);

  return 0;
}