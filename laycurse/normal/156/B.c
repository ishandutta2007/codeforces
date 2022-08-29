#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int res[110000], res_sum;
char in[110000][10]; int gn[110000];
int pp[110000], mm[110000];

int main(){
  int i,j,k,l,m,n;
  int plus, minus;

  while(scanf("%d%d",&n,&m)==2){
    rep(i,n) scanf("%s",in[i]);
    rep(i,n) gn[i] = atoi(in[i]+1) - 1;

    rep(i,n) pp[i] = mm[i] = 0;

    plus = minus = 0;
    rep(i,n){
      if(in[i][0]=='+'){
        plus++;
        pp[gn[i]]++;
      } else {
        minus++;
        mm[gn[i]]++;
      }
    }

    res_sum = 0;
    rep(i,n){
      k = pp[i] + minus - mm[i];
      if(k == m) res[i] = 1; else res[i] = 0;
      res_sum += res[i];
    }

    rep(i,n){
      if(in[i][0]=='+'){
        if(res[gn[i]]==0){ puts("Lie"); continue; }
        if(res_sum == 1){ puts("Truth"); continue; }
        puts("Not defined");
      } else {
        if(res[gn[i]]==0){ puts("Truth"); continue; }
        if(res_sum > 1){ puts("Not defined"); continue; }
        puts("Lie");
      }
    }
  }

  return 0;
}