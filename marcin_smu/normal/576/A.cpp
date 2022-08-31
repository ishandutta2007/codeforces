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
#define MAX 1001
int n;
bool cz[MAX];
vector<int> wyn;
main(){
  make(n);
  F(i,2,n+1){
    if(cz[i])continue;
    for(int j=1;j*i <= n;j++)
      cz[i*j] = 1;
    int ak = i;
    while(ak <= n){
      wyn.PB(ak);
      ak *= i;
    }
  }
  printf("%d\n",wyn.size());
  R(i,SZ(wyn))
    printf("%d ",wyn[i]);
  puts("");
}