#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}

#define MX 256

int X, K, P_; double P;

int val[MX+1];
double dp[MX][MX], nx[MX][MX];

int main(){
  int i, j, k;
  double res;

  REP(i,1,MX+1){
    j = i; k = 0;
    while(j%2==0) k++, j/=2;
    val[i] = k;
  }

  reader(&X,&K,&P_); P = P_ / 100.0;
  rep(i,MX) rep(j,MX) dp[i][j] = 0;

  if(X%MX==0){
    k = 0;
    while(X%2==0) X/=2,k++;
    dp[k][0] = 1;
  } else {
    k = X%MX;
    X /= MX;
    j = 0;
    while(X%2==1) j++, X/=2;
    dp[j][k] = 1;
  }

  while(K--){
    rep(i,MX) rep(j,MX) nx[i][j] = 0;

    rep(i,MX) rep(j,MX) if(dp[i][j]){
      if(j==0){
        nx[i+1][j] += dp[i][j] * P;
        nx[0][1] += dp[i][j] * (1-P);
        continue;
      }

      if(j*2 > MX)     nx[i+1][j*2%MX] += dp[i][j] * P;
      else if(j*2==MX) nx[val[MX]][0] += dp[i][j] * P;
      else             nx[0][j*2] += dp[i][j] * P;

      if(j != MX-1) nx[i][j+1] += dp[i][j] * (1-P);
      else          nx[val[MX]+i][0] += dp[i][j] * (1-P);
    }

    rep(i,MX) rep(j,MX) dp[i][j] = nx[i][j];
  }

  res = 0;
  rep(i,MX) rep(j,MX) if(dp[i][j]){
    if(j==0) k = i; else k = val[j];
    res += dp[i][j] * k;
  }

  printf("%.9f\n", res);

  return 0;
}