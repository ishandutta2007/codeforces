#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int GCD(int a,int b){int r; while(a){r=b; b=a; a=r%a;} return b;}
int LCM(int a,int b){ return a*b/GCD(a,b); }

double  dp[120][210][210];
double sum[120][210][210];

int hp1, dt1, l1, r1, p1; double P1;
int hp2, dt2, l2, r2, p2; double P2;
int turn_size, turn[670];

double inv[20000];

double get_ave(int t, int a1, int a2, int b1, int b2){
  int area = (a2-a1+1) * (b2-b1+1);
  double res = 0;

  if(b2 < 0){
    return 1;
  }
  if(b1 < 0){
    res += (-b1)*(a2-a1+1);
    b1 = 0;
  }
  if(a2 < 0){
    return 0;
  }
  if(a1 < 0){
    a1 = 0;
  }

  res += sum[t][a2+1][b2+1] - sum[t][a1][b2+1] - sum[t][a2+1][b1] + sum[t][a1][b1];

  return res * inv[area];
}

int main(){
  int i,j,k,l,m,n;
  int t, s, ss, mt;
  int h1, h2;
  double pp;
  double ave1[200], ave2[200];

  REP(i,1,20000) inv[i] = 1.0/i;

  scanf("%d%d%d%d%d",&hp1,&dt1,&l1,&r1,&p1);
  scanf("%d%d%d%d%d",&hp2,&dt2,&l2,&r2,&p2);

  if(p1==100){puts("0"); return 0;}
  if(p2==100){puts("1"); return 0;}
  P1 = p1 / 100.0;
  P2 = p2 / 100.0;

  turn_size = 0;
  mt = LCM(dt1,dt2);
  rep(t,mt){
    if(t%dt1==0) turn[turn_size++] = 1;
    if(t%dt2==0) turn[turn_size++] = 2;
  }

  rep(h1,hp1) rep(h2,hp2){
    rep(t,turn_size){
      ave1[t] = get_ave( t, h1, h1, h2-r1, h2-l1 );
      ave2[t] = get_ave( t, h1-r2, h1-l2, h2, h2 );
    }
    
    rep(t,turn_size){
      pp = 1;
      rep(s,turn_size){
        ss = turn[(t+s)%turn_size];
        if(ss==1){
          dp[t][h1][h2] += pp * (1-P1) * ave1[(t+s+1)%turn_size];
          pp *= P1;
        } else {
          dp[t][h1][h2] += pp * (1-P2) * ave2[(t+s+1)%turn_size];
          pp *= P2;
        }
      }
      dp[t][h1][h2] /= (1-pp);
/*      printf("%d %d %d : %f\n",t,h1,h2,dp[t][h1][h2]);*/
      sum[t][h1+1][h2+1] = sum[t][h1+1][h2] + sum[t][h1][h2+1] - sum[t][h1][h2];
      sum[t][h1+1][h2+1] += dp[t][h1][h2];
    }
  }

  printf("%.15f\n",dp[0][hp1-1][hp2-1]);

  return 0;
}