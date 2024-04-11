#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int N, K;
string in[110000];
char buf[110000];

int solve_win(int a, int b, int len){
  int i, j, k;
  int st, ed;
  int res = 0;

  while(a <= b && in[a].size() == len) a++;
  if(a > b) return 0;

  st = a;
  REP(k,'a','z'+1){
    if(st > b) break;
    if(in[st][len] != k) continue;

    ed = st;
    while(ed <= b && in[ed][len] == k) ed++;

    if(solve_win(st, ed-1, len+1)==0){
      res = 1;
      break;
    }

    st = ed;
  }

  return res;
}

int solve_lose(int a, int b, int len){
  int i, j, k;
  int st, ed;
  int res = 0;

  while(a <= b && in[a].size() == len) a++;
  if(a > b) return 1;

  st = a;
  REP(k,'a','z'+1){
    if(st > b) break;
    if(in[st][len] != k) continue;

    ed = st;
    while(ed <= b && in[ed][len] == k) ed++;

    if(solve_lose(st, ed-1, len+1)==0){
      res = 1;
      break;
    }

    st = ed;
  }

  return res;
}

int main(){
  int i, j, k;
  int win, lose;

  scanf("%d%d",&N,&K);
  rep(i,N){
    scanf("%s",buf);
    in[i] = (string)buf;
  }

  sort(in, in+N);

  win = solve_win(0, N-1, 0);
  lose = solve_lose(0, N-1, 0);

  if(win == 1 && lose == 1){
    puts("First");
  } else if(win == 0 && lose == 0){
    puts("Second");
  } else if(win == 1 && lose == 0){
    if(K%2==1) puts("First");
    else       puts("Second");
  } else {
    puts("Second");
  }

  return 0;
}