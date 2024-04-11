#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

int N, M, F[100000], B[100000];

int F_inv[100001];
int A[100000];

int main(){
  int i, k;

  reader(&N,&M);
  rep(i,N) reader(F+i);
  rep(i,M) reader(B+i);

  rep(i,N+1) F_inv[i] = -1;
  rep(i,N){
    if(F_inv[F[i]]==-1){ F_inv[F[i]] = i; continue; }
    F_inv[F[i]] = -2;
  }

  rep(i,M){
    k = F_inv[B[i]];
    if(k==-1){ writerLn("Impossible"); return 0; }
    A[i] = k+1;
  }

  rep(i,M) if(A[i]==-1){ writerLn("Ambiguity"); return 0; }

  writerLn("Possible");
  writerArr(A, M);

  return 0;
}