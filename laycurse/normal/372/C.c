#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define ll long long
#define READER_BUF_SIZE 65536
#define myIsDigit(x) ('0'<=(x) && (x)<='9')
#define myIsSpace(x) ((x)==' ' || (x)=='\t' || (x)=='\n' || (x)=='\r')

int reader_pt = READER_BUF_SIZE;
char reader_buf[READER_BUF_SIZE];

int reader_nonneg_int(){
  int r;

  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(myIsDigit(reader_buf[reader_pt])) break;
    reader_pt++;
  }
  r = reader_buf[reader_pt++] - '0';
  for(;;){
    if(reader_pt==READER_BUF_SIZE) reader_pt = 0, fread(reader_buf, READER_BUF_SIZE, sizeof(char), stdin);
    if(!myIsDigit(reader_buf[reader_pt])) break;
    r = r*10 + (reader_buf[reader_pt++]-'0');
  }
  reader_pt++;

  return r;
}


void doublingRMQBuild(ll arr[], int n, int res[]){
  int i, k, hf;

  rep(i,n) res[i] = i;
  for(k=1;;k++){
    hf = (1<<(k-1)); if(hf >= n) break;
    rep(i,n){
      res[n*k+i] = res[n*(k-1)+i];
      if(i+hf < n && arr[res[n*k+i]] < arr[res[n*(k-1)+i+hf]]) res[n*k+i] = res[n*(k-1)+i+hf];
    }
  }
}

int doublingRMQQuery(ll arr[], int n, int rmq[], int a, int b){
  int dep, wid = b-a+1, A, B;
  for(dep=0;(1<<(dep+1))<=wid;dep++);
  A = rmq[n*dep+a];
  B = rmq[n*dep+b-(1<<dep)+1];
  if(arr[A] < arr[B]) A = B;
  return A;
}

ll ab(ll x){ if(x<0) return -x; return x; }

int main(){
  ll n, m, d;
  ll a[333], b[333], t[333];

  int i,j,k,l;
  ll left, right;
  ll res;
  static ll mx[200000], nx[200000];
  static int rmq[5000000];


  n = reader_nonneg_int();
  m = reader_nonneg_int();
  d = reader_nonneg_int();
  rep(i,m){
    a[i] = reader_nonneg_int() - 1;
    b[i] = reader_nonneg_int();
    t[i] = reader_nonneg_int();
  }

  rep(i,n) mx[i] = b[0] - ab(a[0] - i);
  REP(k,1,m){
    doublingRMQBuild(mx, n, rmq);
    rep(i,n){
      left  = i - d * (t[k] - t[k-1]);
      right = i + d * (t[k] - t[k-1]);
      if(left < 0) left = 0;
      if(right >= n) right = n-1;

      j = doublingRMQQuery(mx, n, rmq, left, right);
      nx[i] = mx[j] + b[k] - ab(a[k] - i);
    }
    rep(i,n) mx[i] = nx[i];
  }

  res = mx[0];
  REP(i,1,n) res = MAX(res, mx[i]);

  printf("%I64d\n",res);

  return 0;
}