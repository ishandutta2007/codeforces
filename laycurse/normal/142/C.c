#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x, y;
int mp[10][10];
int res[10][10], opt;

int dx[4][5] = { {0,0,0,1,2}, {0, 1, 1,1,2}, {0,1, 2,2,2}, {0,1,1,1,2} };
int dy[4][5] = { {0,1,2,1,1}, {0,-2,-1,0,0}, {0,0,-1,0,1}, {0,0,1,2,0} };

int is_ok(int a, int b, int k){
  int i,na,nb;
  rep(i,5){
    na = a + dx[k][i];
    nb = b + dy[k][i];
    if(na < 0 || nb < 0 || na >= x || nb >= y || mp[na][nb]>=0) return 0;
  }
  return 1;
}

void go_put(int a, int b, int k, int c){
  int i,na,nb;
  rep(i,5){
    na = a + dx[k][i];
    nb = b + dy[k][i];
    mp[na][nb] = c;
  }
}

void solve(int a, int b, int now){
  int i,j,k;

  if(a==x){
    if(opt < now){
      opt = now;
      rep(i,x) rep(j,y) res[i][j] = mp[i][j];
    }
    return;
  }
  if(b==y){
    solve(a+1,0,now);
    return;
  }

  k = 0;
  REP(i,a,x) rep(j,y){
    if(i==a && j<b) continue;
    if(mp[i][j]==-1) k++;
  }
  if(now + k/5 <= opt) return;

  rep(k,4) if(is_ok(a,b,k)){
    go_put(a,b,k,now);
    solve(a,b+1,now+1);
    go_put(a,b,k,-1);
  }
  solve(a,b+1,now);
}

int main(){
  int i,j,k,l,m,n;

  while(scanf("%d%d",&x,&y)==2){
    rep(i,x) rep(j,y) res[i][j] = mp[i][j] = -1;
    opt = 0;

    solve(0,0,0);
    printf("%d\n",opt);
    rep(i,x){
      rep(j,y){
        if(res[i][j] == -1) putchar('.');
        else                putchar('A'+res[i][j]);
      }
      puts("");
    }
  }

  return 0;
}