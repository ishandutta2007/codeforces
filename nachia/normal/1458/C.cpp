#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,M;
int A[1024][1024];
int I[3];
int D[3];
int ans[1024][1024];

int addmod(int x,int dx){ x+=dx; if(x>=N) x-=N; return x; }

int buf[1024];
void op_I(){ rep(y,N){ rep(x,N) buf[A[x][y]]=x; rep(x,N) A[x][y]=buf[x]; } }
void op_C(){ rep(x,N){ rep(y,N) buf[A[x][y]]=y; rep(y,N) A[x][y]=buf[y]; } }

void loop(){
  scanf("%d%d",&N,&M);
  rep(y,N) rep(x,N){ scanf("%d",&A[x][y]); A[x][y]--; }
  rep(i,3) I[i]=i;
  rep(i,3) D[i]=0;

  scanf(" ");
  rep(i,M){
    char c; scanf("%c",&c);
    if(c=='U'){ D[I[1]]=addmod(D[I[1]],N-1); }
    if(c=='D'){ D[I[1]]=addmod(D[I[1]],1); }
    if(c=='L'){ D[I[0]]=addmod(D[I[0]],N-1); }
    if(c=='R'){ D[I[0]]=addmod(D[I[0]],1); }
    if(c=='C'){ swap(I[1],I[2]); }
    if(c=='I'){ swap(I[0],I[2]); }
  }
  
  rep(x,N) rep(y,N){
    int X[3]={addmod(x,D[0]),addmod(y,D[1]),addmod(A[x][y],D[2])};
    ans[X[I[0]]][X[I[1]]] = X[I[2]];
  }

  rep(y,N){ rep(x,N){ if(x) printf(" "); printf("%d",ans[x][y]+1); } printf("\n"); }
}

int main(){
  int T; scanf("%d",&T);
  rep(i,T) loop();
  return 0;
}