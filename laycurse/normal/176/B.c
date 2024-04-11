#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

int is_same(char A[], char B[], int len){
  int i;
  rep(i,len) if(A[i] != B[i]) return 0;
  return 1;
}

int main(){
  int i,j,k,l,m,n;
  ll dp[2], next[2];
  ll res = 0, sum;
  char A[2010], B[2010]; int len;

  scanf("%s%s%d",&A,&B,&k);
  len = strlen(A);
  if(len != strlen(B)){ puts("0"); return 0; }

  dp[0] = 1; dp[1] = 0;
  rep(m, k){
    sum = dp[0] + dp[1] * (len-1);
    dp[0] = (sum - dp[0])%M;
    dp[1] = (sum - dp[1])%M;
  }

  rep(i,len) A[i+len] = A[i];
  rep(i,len) if(is_same(A+i, B, len)){
    if(i==0) res += dp[0];
    else     res += dp[1];
  }

  res %= M;
  printf("%d\n",(int)res);

  return 0;
}