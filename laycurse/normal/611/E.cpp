#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

template<class T> inline T max(T a, T b, T c){return max(max(a,b),c);}
template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}

int N, X[3];
int T[300000];
int A, B, ABoC, C, AB, AC, BC, ABC;

int solve(void){
  int i, j, k, res, tmp;
  int a, b, c;

  rep(i,N){
    if(T[i] > X[0]+X[1]+X[2]){ return -1; }

    if(T[i] <= X[0]){ A++; continue; }
    if(T[i] <= X[1]){ B++; continue; }
    if(T[i] <= X[2] && T[i] <= X[0]+X[1]){ ABoC++; continue; }
    if(T[i] <= X[2]){ C++; continue; }
    if(T[i] <= X[0]+X[1]){ AB++; continue; }
    if(T[i] <= X[0]+X[2]){ AC++; continue; }
    if(T[i] <= X[1]+X[2]){ BC++; continue; }
    ABC++;
  }


  res = N;
  rep(k,ABoC+1){
    C += k;
    AB += ABoC - k;

    tmp = ABC;
    a = A; b = B; c = C;

    tmp += BC;
    a -= min(BC, a);
    
    tmp += AC;
    i = AC;
    j = min(i, b);
    b -= j; i -= j;
    j = min(i, a);
    a -= j;

    tmp += AB;
    i = AB;
    j = min(i, c);
    c -= j; i -= j;
    j = min(i, b);
    b -= j; i -= j;
    j = min(i, a);
    a -= j;

    tmp += max(c, (c+b+1)/2, (c+b+a+2)/3);
    
    chmin(res, tmp);
    
    C -= k;
    AB -= ABoC - k;
  }

  return res;
}


int main(){
  int i, res;

  reader(&N);
  rep(i,3) reader(X+i);
  rep(i,N) reader(T+i);
  sort(X, X+3);

  res = solve();

  writerLn(res);

  return 0;
}