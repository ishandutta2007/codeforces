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

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

#define INF 1000100000

int N, A[10000];
int dp[5100][5100];

int main(){
  int i, j, k, res;

  reader(&N);
  A[0] = 0;
  rep(i,N) reader(A+i+1);
  N++;

  rep(i,N+1) rep(j,N+1) dp[i][j] = INF;
  dp[0][0] = 0;
  
  REP(i,1,N) rep(j,i+1) if(dp[i-1][j] != INF){
    if(A[j] >= A[i]){
      dp[i][i] = min(dp[i][i], dp[i-1][j]);
    } else {
      dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      dp[i][i] = min(dp[i][i], dp[i-1][j]+A[i]-A[j]);
    }
  }

  res = INF;
  rep(j,N+1) res = min(res, dp[N-1][j]);
  writer(res, '\n');

  myed;
  return 0;
}