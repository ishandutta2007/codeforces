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
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, M, W;
int A[200000];

int now[200000], sum[200000];

int ok(int tar){
  int i, j, k, add=0, rest = M;

  rep(i,N) now[i] = A[i], sum[i] = 0;
  rep(i,N){
    add += sum[i];
    now[i] += add;

    if(now[i] < tar){
      k = tar - now[i];
      rest -= k;
      if(rest < 0) return 0;
      add += k; sum[i+W] -= k;
    }
  }

  return 1;
}

int main(){
  int i, j, k;
  int a, b, c;

  reader(&N,&M,&W);
  rep(i,N) reader(A+i);

  a = 0;
  b = 1010000000;
  while(a<b){
    c = (a+b+1) / 2;
    if(ok(c)) a = c; else b = c-1;
  }

  writer(a,'\n');

  myed;
  return 0;
}