#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define ull unsigned long long

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

ull dp[70][2][70];
ull cntnum(ll C, int k){
  int i, j, d;
  
  rep(d,65) rep(i,2) rep(j,65) dp[d][i][j] = 0;
  dp[63][1][0] = 1;
  for(d=63;d;d--) rep(i,2) rep(j,65) if(dp[d][i][j]){
    if(i && (C&(1ULL<<(d-1)))){
      dp[d-1][0][j] += dp[d][i][j];
      dp[d-1][1][j+1] += dp[d][i][j];
    } else if(i){
      dp[d-1][1][j] += dp[d][i][j];
    } else {
      dp[d-1][i][j] += dp[d][i][j];
      dp[d-1][i][j+1] += dp[d][i][j];
    }
  }
  return dp[0][0][k] + dp[0][1][k];
}

int main(){
  ll m; int k;
  int i, j;
  ull A, B, C, num;

  reader(&m); reader(&k);

  A = 1; B = 1000000000000000000ULL;
  while(A<B){
    C = (A+B)/2;
    num = cntnum(2*C,k) - cntnum(C,k);
    if(num < m){ A = C+1; continue; }
    if(num > m){ B = C-1; continue; }
    A = B = C;
  }

  writer((ll)A, '\n');

  myed;
  return 0;
}