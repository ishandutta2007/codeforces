#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n;
int mi[10][10], mx[10][10], ac[10][10];
int ind[10];
int now[10];

int res, res_cost;

void solve(int a,int b,int cost){
  int i,j,send;
  int aa = ind[a], bb = ind[b];

  if(a>=n){
    if(now[n-1] < 0) return;
    if(now[n-1] == res && cost > res_cost) res++;
    if(now[n-1] < res) res = now[n-1], res_cost = cost;
    return;
  }

  if(b>=n){
    if(aa!=0 && aa!=n-1 && now[aa]) return;
    solve(a+1,a+2,cost);
    return;
  }

  REP(i,-mx[aa][bb],mx[aa][bb]+1){
    if(-mi[aa][bb]<i && i<mi[aa][bb]) continue;
    if( (bb-aa)*i < 0 ) continue;

    send = cost;
    if(i) send += ac[aa][bb];
    send += i*i;

    now[aa]-=i; now[bb]+=i;
    solve(a,b+1,send);
    now[aa]+=i; now[bb]-=i;
  }
}

int main(){
  int i,j,k,l,m;
  int a,b,c;

  while(scanf("%d",&n)==1){
    m = n*(n-1)/2;
    while(m--){
      scanf("%d%d%d%d%d",&i,&j,&a,&b,&c); i--; j--;
      mi[i][j] = mi[j][i] = a;
      mx[i][j] = mx[j][i] = b;
      ac[i][j] = ac[j][i] = c;
    }
    REP(i,1,n-1) ind[i-1] = i; ind[n-2]=0; ind[n-1]=n-1;
    rep(i,n) now[i] = 0;

    res = 1000000;

    solve(0,1,0);

    if(res == 1000000) res = res_cost = -1;
    printf("%d %d\n",res, res_cost);
  }

  return 0;
}