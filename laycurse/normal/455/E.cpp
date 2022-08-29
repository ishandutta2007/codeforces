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
void reader(int *x, int *y){reader(x);reader(y);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

void doublingRMQBuild(int arr[], int n, int res[]){
  int i, k, hf;

  rep(i,n) res[i] = i;
  for(k=1;;k++){
    hf = (1<<(k-1)); if(hf >= n) break;
    rep(i,n){
      res[n*k+i] = res[n*(k-1)+i];
      if(i+hf < n && arr[res[n*k+i]] >= arr[res[n*(k-1)+i+hf]]) res[n*k+i] = res[n*(k-1)+i+hf];
    }
  }
}

int doublingRMQQuery(int arr[], int n, int rmq[], int a, int b){
  int dep, wid = b-a+1, A, B;
  for(dep=0;(1<<(dep+1))<=wid;dep++);
  A = rmq[n*dep+a];
  B = rmq[n*dep+b-(1<<dep)+1];
  if(arr[A] >= arr[B]) A = B;
  return A;
}

int N, M, A[110000];

int RMQ[4000000];

int sum[110000];
int go_decrease[110000];
int upup[110000];

int main(){
  int i, j, k, r;
  int x, y, mm, cur;
  int res;

  reader(&N);
  rep(i,N) reader(A+i);

  doublingRMQBuild(A, N, RMQ);

  sum[0] = 0;
  rep(i,N) sum[i+1] = sum[i] + A[i];

  rep(i,N){
    go_decrease[i] = i;
    if(i && A[i-1] <= A[i]) go_decrease[i] = go_decrease[i-1];
  }

  for(i=N-1;i>=0;i--){
    upup[i] = i;
    if(i+1 < N && A[i] <= A[i+1]) upup[i] = upup[i+1];
  }
  
  reader(&M);
  while(M--){
    reader(&x,&y); x--; y--;
    res = sum[y+1] - sum[y-x];

    i = y - x;
    k = go_decrease[y];
    if(k > i){
      res = min(res, sum[y+1] - sum[k] + (k-i) * A[k]);

      cur = i;
      for(;;){
        if(cur >= k) break;
        mm = doublingRMQQuery(A, N, RMQ, cur, k);
        if(mm==k) break;
        res = min(res, sum[y+1] - sum[mm] + (mm-i) * A[mm]);
        cur = upup[mm] + 1;
      }
    }

    writer(res, '\n');
  }

  myed;
  return 0;
}