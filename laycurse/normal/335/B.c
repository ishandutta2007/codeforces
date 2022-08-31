#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[1000000];
int cnt[26];

int dp[2610][2610];
char res[3000];

int main(){
  int i,j,k,l,m,n,len;
  int a, b;

  scanf("%s",in);
  n = strlen(in);

  rep(i,26) cnt[i] = 0;
  rep(i,n) cnt[in[i]-'a']++;

  rep(i,26) if(cnt[i] >= 100) break;
  if(i==26){
    rep(i,n+1) rep(j,n+1) dp[i][j] = 0;
    rep(i,n) dp[i][i] = 1;
    REP(m,1,n) rep(i,n-m){
      j = i+m;
      if(in[i]==in[j]) dp[i][j] = dp[i+1][j-1]+2;
      if(dp[i][j] < dp[i+1][j]) dp[i][j] = dp[i+1][j];
      if(dp[i][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1];
    }

    i = 0; j = n-1; len = dp[i][j];
    res[len] = '\0';
    a = 0; b = dp[i][j]-1;
    while(i<=j){
      if(i==j){res[a] = in[i]; break;}
      if(in[i]==in[j]){res[a]=res[b] = in[i]; a++; b--; i++; j--; continue;}
      if(dp[i][j]==dp[i+1][j]){i++; continue;}
      j--;
    }
    if(len > 100){
      len = 100;
      rep(i,50) res[99-i] = res[i];
      res[len] = '\0';
    }
    puts(res);
  } else {
    rep(k,100) putchar('a' + i);
    puts("");
  }

  return 0;
}