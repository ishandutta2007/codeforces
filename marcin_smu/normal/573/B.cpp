#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 100010
int n;
int t[MAX];
int w1[MAX],w2[MAX];
main(){
  make(n);
  R(i,n)make(t[i]);
  R(i,n)w1[i+1] = min(w1[i]+1,t[i]);
  FD(i,n)w2[i] = min(w2[i+1]+1,t[i]);
  int wyn = 0;
  R(i,n)MA(wyn,min(w1[i+1],w2[i]));
  printf("%d\n",wyn);
}