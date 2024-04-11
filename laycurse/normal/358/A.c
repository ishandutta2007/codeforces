#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int main(){
  int n;
  int x[1000];

  int i, j, res;
  int x1_min, x1_max, x2_min, x2_max;
  
  scanf("%d", &n);
  rep(i,n) scanf("%d", x+i);

  res = 1;
  REP(i,1,n) REP(j,1,i){
    x1_min = MIN(x[i-1], x[i]);
    x1_max = MAX(x[i-1], x[i]);
    x2_min = MIN(x[j-1], x[j]);
    x2_max = MAX(x[j-1], x[j]);

    if(x1_min < x2_min && x2_min < x1_max && x1_max < x2_max) res = 0;
    if(x2_min < x1_min && x1_min < x2_max && x2_max < x1_max) res = 0;
  }

  if(res) puts("no"); else puts("yes");

  return 0;
}