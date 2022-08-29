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

#define mygc(c) (c)=_getchar_nolock()
#define mypc(c) _putchar_nolock(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int res[100010];

int solve(int N, int K){
  int i, j, r;
  
  if(N==1){
    res[0] = 1;
    if(K==0) return 1;
    return 0;
  }

  r = K - N/2 + 1;
  if(r <= 0) return 0;

  res[0] = r;
  res[1] = 2*r;
  j = 1000000000;
  REP(i,2,N) res[i] = j--;
  return 1;
}

int main(){
  int N, K;
  int i;

  reader(&N);
  reader(&K);

  if(solve(N,K)){
    rep(i,N) writer(res[i], i==N-1?'\n':' ');
  } else {
    writer(-1, '\n');
  }

  return 0;
}