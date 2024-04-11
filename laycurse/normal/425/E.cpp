#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define M 1000000007

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

ll dp[510][510];
ll pw[125510];
ll pwpw[510][510];

int main(){
  int N, K;
  int i,j,l,m;

  pw[0] = 1;
  REP(i,1,125510){ pw[i] = pw[i-1] * 2; if(pw[i] >= M) pw[i] -= M; }
  rep(i,501) REP(m,1,i+1) pwpw[i][m] = (pw[m] - 1) * pw[m*(i-m)] % M;
  
  reader(&N);
  reader(&K);

  rep(i,501) rep(j,501) dp[i][j] = 0;
  rep(i,501) dp[i][0] = 1;

  rep(i,501) REP(j,1,i+1){
    dp[i][j] = 0;
    REP(m,1,i+1) if(dp[i-m][j-1]) dp[i][j] = (dp[i][j] + dp[i-m][j-1] * pwpw[i][m]) % M;
  }

  dp[N][K] %= M;
  if(dp[N][K] < 0) dp[N][K] += M;
  writer((int)dp[N][K], '\n');

  myed;
  return 0;
}