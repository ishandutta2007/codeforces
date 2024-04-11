#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}

#define INF 1000000000

int main(){
  int i, j, k;
  int d[3][3];

  rep(i,3) rep(j,3) d[i][j] = INF;
  rep(i,3) d[i][i] = 0;

  reader(&i,&j,&k);
  d[0][1] = d[1][0] = i;
  d[0][2] = d[2][0] = j;
  d[1][2] = d[2][1] = k;

  rep(k,3) rep(i,3) rep(j,3) chmin(d[i][j], d[i][k]+d[k][j]);

  writerLn(d[0][1] + d[1][2] + d[2][0]);

  return 0;
}