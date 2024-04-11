#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define MX 1000000

int len;
char in[100];
int res;

void solve(int depth, int st, int sum){
  int i,j,k;

  if(depth==3){
    if(st!=len) return;
    if(res < sum) res = sum;
    return;
  }

  k = 0;
  REP(i,st,len){
    k = k * 10 + (in[i] - '0');
    if(k > MX) break;
    solve(depth+1, i+1, sum+k);
    if(in[st]=='0') break;
  }
}

int main(){
  int i,j,k;

  scanf("%s",in);
  len = strlen(in);

  res = -1;
  solve(0,0,0);

  printf("%d\n",res);

  return 0;
}