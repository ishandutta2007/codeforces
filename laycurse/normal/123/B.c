#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

void get(ll val, ll mod, int *min, int *max){
  ll res = val / mod;

  while(res * mod <= val) res++;
  *max = (int)res;
  while(res * mod >= val+mod) res--;
  *min = (int)res;
}

ll solve(ll x1, ll y1, ll x2, ll y2){
  ll dx = x1 - x2;
  ll dy = y1 - y2;
  if(dx < 0) dx = -dx;
  if(dy < 0) dy = -dy;

  if(dx > dy) return dx;
  return dy;
}

int main(){
  int i,j,k,l,m,n;
  int a,b,x1,y1,x2,y2;
 
  int X1[2], Y1[2], X2[2], Y2[2];
  int a1,a2,a3,a4;
  ll res, tmp;
  int fg1, fg2;

  while(scanf("%d%d%d%d%d%d",&a,&b,&x1,&y1,&x2,&y2)==6){
    get(x1+y1, 2*a, X1, X1+1);
    get(x1-y1, 2*b, Y1, Y1+1);
    get(x2+y2, 2*a, X2, X2+1);
    get(x2-y2, 2*b, Y2, Y2+1);

    fg1 = fg2 = 0;
    if( (x1+y1)%(2*a)==0 || (x1-y1)%(2*b)==0 ) fg1 = 1;
    if( (x2+y2)%(2*a)==0 || (x2-y2)%(2*b)==0 ) fg2 = 1;

    if(x1==x2 && y1==y2){
      printf("%d\n",fg1); continue;
    }

    res = 1000000000000000LL;
    rep(i,1<<4){
      if(i&1<<0) a1 = X1[0]; else a1 = X1[1];
      if(i&1<<1) a2 = Y1[0]; else a2 = Y1[1];
      if(i&1<<2) a3 = X2[0]; else a3 = X2[1];
      if(i&1<<3) a4 = Y2[0]; else a4 = Y2[1];
      tmp = solve(a1,a2,a3,a4);
      if(res > tmp) res = tmp;
    }

    res += fg1 + fg2;
    printf("%d\n",(int)res);
  }

  return 0;
}