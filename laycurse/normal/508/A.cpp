#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

int X, Y, K;
char mp[1010][1010];

int main(){
  int i, j, k;
  int di, dj, dame = 0;
  int res = 0;

  reader(&X,&Y,&K);
  rep(k,K){
    reader(&i,&j);
    mp[i][j] = 1;
    REP(di,-1,2) REP(dj,-1,2) if(di && dj){
      if(mp[i][j] + mp[i+di][j] + mp[i][j+dj] + mp[i+di][j+dj] == 4) dame = 1;
    }
    if(dame){ res = k+1; break; }
  }
  writerLn(res);

  return 0;
}