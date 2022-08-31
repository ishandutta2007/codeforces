#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

/*
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
#define myed ;

#define mygc(c) (c)=_getchar_nolock()
#define mypc(c) _putchar_nolock(c)
#define myed ;

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)
#define myed ;

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];

#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}
 */

#define mygc(c) (c)=_getchar_nolock()
#define mypc(c) _putchar_nolock(c)
#define myed ;

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

ll dp[2100][2100];

int main(){
  int N, K;
  int i, j, m;

  reader(&N);
  reader(&K);

  rep(i,K+1) rep(j,N+1) dp[i][j] = 0;
  rep(j,N+1) dp[1][j]++;
  REP(i,1,K) REP(j,1,N+1){
    dp[i][j] %= M;
    for(m=j;m<=N;m+=j) dp[i+1][m] += dp[i][j];
  }

  m = 0;
  REP(j,1,N+1) m = (m + dp[K][j]) % M;

  writer(m, '\n');

  myed;
  return 0;
}