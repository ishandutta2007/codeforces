#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int len, can;
char in[111];
int dp_max[200][200], dp_min[200][200], ok[200][200];
int alr[200][200];

void solve(int st, int rest){
  int i,j,k;
  int mx, mn;

  if(alr[st][rest]) return;
  alr[st][rest] = 1;

  ok[st][rest] = 0;
  mx = dp_max[st][rest] = -100000;
  mn = dp_min[st][rest] =  100000;

  if(rest >= 2){
    solve(st, rest-2);
    if(ok[st][rest-2]){
      ok[st][rest] = 1;
      if(mx < dp_max[st][rest-2]) mx = dp_max[st][rest-2];
      if(mn > dp_min[st][rest-2]) mn = dp_min[st][rest-2];
    }
  }

  if(st == len){
    if(rest==0){
      ok[st][rest] = 1;
      mx = mn = 0;
    }
  } else {
    solve(st+1, rest);
    if(rest) solve(st+1, rest-1);

    if(in[st]=='F' && ok[st+1][rest]){
      ok[st][rest] = 1;
      if(mx < dp_max[st+1][rest]+1) mx = dp_max[st+1][rest]+1;
      if(mn > dp_min[st+1][rest]+1) mn = dp_min[st+1][rest]+1;
    }

    if(in[st]=='T' && rest && ok[st+1][rest-1]){
      ok[st][rest] = 1;
      if(mx < dp_max[st+1][rest-1]+1) mx = dp_max[st+1][rest-1]+1;
      if(mn > dp_min[st+1][rest-1]+1) mn = dp_min[st+1][rest-1]+1;
    }

    if(in[st]=='T' && ok[st+1][rest]){
      ok[st][rest] = 1;
      if(mx < -dp_min[st+1][rest]) mx = -dp_min[st+1][rest];
      if(mn > -dp_max[st+1][rest]) mn = -dp_max[st+1][rest];
    }

    if(in[st]=='F' && rest && ok[st+1][rest-1]){
      ok[st][rest] = 1;
      if(mx < -dp_min[st+1][rest-1]) mx = -dp_min[st+1][rest-1];
      if(mn > -dp_max[st+1][rest-1]) mn = -dp_max[st+1][rest-1];
    }
  }

  dp_max[st][rest] = mx;
  dp_min[st][rest] = mn;
}

int main(){
  int i,j,k,l,m,n;

  scanf("%s%d",in,&can);
  len = strlen(in);

  rep(j,200) rep(k,200) alr[j][k] = 0;
  solve(0, can);

/*  printf("%d %d\n",dp_max[0][can],dp_min[0][can]);*/
  k = dp_max[0][can]; if(k<0) k=-k;
  l = dp_min[0][can]; if(l<0) l=-l;
  if(k < l) k = l;

  printf("%d\n",k);

  return 0;
}