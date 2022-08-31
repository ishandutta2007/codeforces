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
#define MAX 200100
LL a[MAX];
LL wyn;
LL pre[MAX],suf[MAX];
int n,k,x;
main(){
  make2(n,k);
  make(x);
  R(i,n)scanf("%lld\n",&a[i]);
  LL pom = 1;
  R(i,k)pom *= x;
  pre[0] = 0;
  R(i,n)pre[i+1] = pre[i] | a[i];
  FD(i,n)suf[i] = suf[i+1] | a[i];
  LL wyn = pre[n];
  R(i,n){
    MA(wyn, pre[i] | (a[i]*pom) | suf[i+1]);
  }
  printf("%lld\n",wyn);
}