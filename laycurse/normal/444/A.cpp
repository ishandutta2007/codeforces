#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}

int N, M;
int X[1000];
int A[1000000], B[1000000], C[1000000];

int main(){
  int i, j, k;
  double res = 0, tmp;

  reader(&N,&M);
  rep(i,N) reader(X+i);
  rep(i,M) reader(A+i,B+i,C+i), A[i]--, B[i]--;

  rep(i,M){
    tmp = (X[A[i]] + X[B[i]]) / (double)C[i];
    res = max(res, tmp);
  }

  printf("%.10f\n",res);

  return 0;
}