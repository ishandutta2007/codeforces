#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

int N, H[100000];
int mn[100000], mx[100000];

int main(){
  int i, res = 1;

  reader(&N);
  rep(i,N) reader(H+i);

  mx[0] = H[0];
  REP(i,1,N) mx[i] = max(mx[i-1], H[i]);
  mn[N-1] = H[N-1];
  for(i=N-2;i>=0;i--) mn[i] = min(mn[i+1], H[i]);

  REP(i,1,N) if(mx[i-1] <= mn[i]) res++;

  writerLn(res);

  return 0;
}