#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
// taken from here: https://github.com/igrsk/spoj/blob/master/SWAPS.cpp
#define FORO(i,n) for(int i = 0;i < n;i++)
#define FORI(i,n) for(int i = 1;i <= n;i++) 
const int MAXN = 200000;
const int MAXA = 200000;
const int MAXSQRTN = 500;

int A[MAXN];
int N, M;
int bit[MAXSQRTN+1][MAXA+1];
int sqrtN;

void bitinc(int i,int v,int *d) {
  for(;i <= MAXA;i += i&-i) d[i]+=v;
}

void bitins(int x,int y,int v) {
  while(x <= sqrtN) {
    bitinc(y,v,bit[x]);
    x += x&-x;
  }
}

int bitsum(int x,int y) {
  int ret = 0;
  for(;x > 0;x-=x&-x)
    for(int yy = y;yy > 0;yy-=yy&-yy)
      ret += bit[x][yy];
  return ret;
}

void init() {
  for(sqrtN = 1;sqrtN*sqrtN < N;sqrtN++) ;
  for(int i = 0;i < N;i++) {
    bitins(i/sqrtN+1,A[i],1);
  }
}

int query(int i,int x) {
  int ret = bitsum(i/sqrtN,x);
  // 0 ~ sqrtN-1, sqrtN ~ 2*sqrtN-1, ... 
  for(int j = sqrtN*(i/sqrtN);j <= i;j++)
    if(A[j] <= x) ret++;
  return ret;
}

int main() {
  scanf("%d %d",&N, &M);
  FORO(i,N) A[i] = i+1;
  
  init();
  
  long long orans = 0;
  FORO(i,N) {
    orans += i-query(i,A[i])+1;
  }

  int X, Y, q1, q2;
  FORO(mm,M) {
    scanf("%d %d",&X,&Y);
    // update and query
    X--; Y--;
    if (X != Y) {
      q1 = A[X];
      q2 = A[Y];


      orans -= (X-query(X-1,A[X])-1)+(query(N-1,A[X]-1)-query(X,A[X]-1));
      bitins(X/sqrtN+1,A[X],-1);
      
      A[X] = q2;
      bitins(X/sqrtN+1,q2,1);
      orans += (X-query(X-1,q2)-1)+(query(N-1,q2-1)-query(X,q2-1));

      orans -= (Y-query(Y-1,A[Y])-1)+(query(N-1,A[Y]-1)-query(Y,A[Y]-1));
      bitins(Y/sqrtN+1,A[Y],-1);
      
      A[Y] = q1;
      bitins(Y/sqrtN+1,q1,1);
      orans += (Y-query(Y-1,q1)-1)+(query(N-1,q1-1)-query(Y,q1-1));
    }

    printf("%lld\n",orans);
  }
  return 0;
}