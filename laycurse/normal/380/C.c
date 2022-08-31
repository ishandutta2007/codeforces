#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define READER_BUF_SIZE 1048576
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE, reader_last;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}

int reader_string(char res[]){
  int len = 0;
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(!myIsSpace(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, reader_last = fread(reader_buf, sizeof(char), READER_BUF_SIZE, stdin);
    if(myIsSpace(reader_buf[reader_pt])){
      reader_pt++;
      break;
    }
    res[len++] = reader_buf[reader_pt++];
  }
  res[len] = '\0';
  return len;
}

#define WRITER_BUF_SIZE 1048576
int writer_pt = 0;
char writer_buf[WRITER_BUF_SIZE];

void writer_nonneg_int_char(int n, char c){
  int i, sz;
  static char buf[10];

  sz = 0;
  while(n) buf[sz++] = n%10, n/=10;
  if(sz==0) buf[sz++] = 0;

  while(sz--){
    if(writer_pt==WRITER_BUF_SIZE) writer_pt=0, fwrite(writer_buf, sizeof(char), WRITER_BUF_SIZE, stdout);
    writer_buf[writer_pt++] = buf[sz] + '0';
  }
  
  if(writer_pt==WRITER_BUF_SIZE) writer_pt=0, fwrite(writer_buf, sizeof(char), WRITER_BUF_SIZE, stdout);
  writer_buf[writer_pt++] = c;
}

void writer_flush(void){
  fwrite(writer_buf, sizeof(char), writer_pt, stdout);
  writer_pt = 0;
}


void doublingRMQBuild(int arr[], int n, int res[]){
  int i, k, hf;

  rep(i,n) res[i] = i;
  for(k=1;;k++){
    hf = (1<<(k-1)); if(hf >= n) break;
    rep(i,n){
      res[n*k+i] = res[n*(k-1)+i];
      if(i+hf < n && arr[res[n*k+i]] > arr[res[n*(k-1)+i+hf]]) res[n*k+i] = res[n*(k-1)+i+hf];
    }
  }
}

int doublingRMQQuery(int arr[], int n, int rmq[], int a, int b){
  int dep, wid = b-a+1, A, B;
  for(dep=0;(1<<(dep+1))<=wid;dep++);
  A = rmq[n*dep+a];
  B = rmq[n*dep+b-(1<<dep)+1];
  if(arr[A] > arr[B]) A = B;
  return A;
}

int ab(int x){ if(x < 0) return -x; return x; }

int main(){
  int i,j,k,l,m,n,q;
  int a, b, res;
  static char s[1000100];
  static int sum[1000100], rmq[44000000];

  n = reader_string(s);
  q = reader_nonneg_int();

  sum[0] = 0;
  rep(i,n){
    if(s[i]=='(') sum[i+1] = sum[i] + 1;
    else          sum[i+1] = sum[i] - 1;
  }

  doublingRMQBuild(sum, n+1, rmq);
  
  while(q--){
    a = reader_nonneg_int() - 1;
    b = reader_nonneg_int();
    m = doublingRMQQuery(sum, n+1, rmq, a, b);

    res = b-a;
    if(sum[b] < sum[a]) k = sum[b]; else k = sum[a];
    res -= ab(sum[b]-sum[a]);
    res -= (k - sum[m]) * 2;

    writer_nonneg_int_char(res, '\n');
  }

  writer_flush();
  return 0;
}