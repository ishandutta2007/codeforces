#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int n;
ll fib[100];

void brute(int g){
  int i,j,sum;
  int k = 19;
  int cnt[10000] = {};

  rep(i,1<<k){
    sum = 0;
    rep(j,k) if(i&1<<j) sum += fib[j];
    if(sum < 10000) cnt[sum]++;
    if(sum==8934){
      rep(j,k) if(i&1<<j) printf("%lld + ", fib[j]);
      puts("= 8934");
    }
  }

  printf("%d\n",cnt[g]);

/*  rep(i,1000){
    printf("%d \n",i);
    k = i;
    for(j=18; j>=0; j--){
      if(k >= fib[j]){ putchar('1'); k -= fib[j]; }
      else putchar('0');
    }
    printf(" %d\n",cnt[i]);
  }*/
}

ll dp[98][4][4];
char g[98];

ll solve(int depth, int now, int next){
  int i,j,k;
  ll res = 0;
  int a, b, c;

  if(depth==1 && now==1 && next==1) return 1;
  if(depth==1) return 0;
  
  if(dp[depth][now][next] >= 0) return dp[depth][now][next];

  a = g[depth] + (now-1);
  b = g[depth-1] + (next-1);
  c = g[depth-2];
  
  if(a==0 || a==1){
    res += solve(depth-1, next, 1);
  }
  if(a==0 && b!=-1){
    res += solve(depth-1, next-1, 0);
  }
  if( (a==1 || a==2) && b!=2 ){
    res += solve(depth-1, next+1, 2);
  }

  return dp[depth][now][next] = res;
}

int main(){
  int i,j,k,l,m,n;
  ll in, res;
  int size;

  fib[0]=1;
  fib[1]=2;
  REP(i,2,100){
    fib[i]=fib[i-1]+fib[i-2];
    if(fib[i]>1000000000000000000LL){
      n = i;
      break;
    }
  }

  scanf("%d",&size);
  while(size--){
    scanf("%I64d",&in);
/*    brute(in);*/
    rep(i,n+2) rep(j,4) rep(k,4) dp[i][j][k] = -1;
    for(i=n-1;i>=0;i--){
      g[i+2] = 0;
      if(in >= fib[i]) in -= fib[i], g[i+2]++;
    }
    g[0] = g[1] = 0;
    
/*    rep(i,n+2) printf("%d",(int)g[i]); puts("");*/
    res = solve(n+1, 1, 1);

    printf("%I64d\n",res);
  }
  
  return 0;
}