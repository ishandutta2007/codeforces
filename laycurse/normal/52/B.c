#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char mp[1010][1010];

int main(){
  int i,j,k,l,m,n;
  int x, y, sum_x[1010] = {}, sum_y[1010] = {};
  long long res = 0;

  scanf("%d%d",&x,&y);
  rep(i,x) scanf("%s",mp[i]);
  rep(i,x) rep(j,y) if(mp[i][j]=='*') sum_x[i]++, sum_y[j]++;
  rep(i,x) rep(j,y) if(mp[i][j]=='*') res += (sum_x[i]-1) * (sum_y[j]-1);

  printf("%I64d\n",res);

  return 0;
}