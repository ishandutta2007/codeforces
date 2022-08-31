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
#include<ctime>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=_getchar_nolock()
#define mypc(c) _putchar_nolock(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int main(){
  int N, K, A[210];
  int i,j,l,m;
  int res, tmp;
  int in[210], ins, add, out[210], outs;

  reader(&N);
  reader(&K);
  rep(i,N) reader(A+i);

  res = -1000000;
  rep(i,N) REP(j,i,N){
    ins = outs = add = 0;
    rep(m,i) out[outs++] = A[m];
    REP(m,i,j+1) in[ins++] = A[m];
    REP(m,j+1,N) out[outs++] = A[m];
    sort(out, out+outs);
    rep(m,K) if(m < outs) in[ins+add++] = out[outs-1-m];
    sort(in, in+ins+add);
    tmp = 0;
    rep(m,ins) tmp += in[add+m];
    res = max(res, tmp);
  }

  writer(res, '\n');

  return 0;
}