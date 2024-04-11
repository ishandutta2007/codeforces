#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define F(I,N) for(int I=0;I<N;I++)
#define R(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A);
#define M 1000000007
#define MAX 2001
int n,k;
LL wyn[MAX],a[MAX],pom[MAX];
main(){
 make(n);
 make(k);
 F(i,n){make(wyn[i]);a[i]=1;};
 while(k){
  if(k&1){
   F(i,n)F(j,i+1){
    pom[i]+=wyn[j]*a[i-j];
    pom[i]%=M;
   }
   F(i,n){
    wyn[i]=pom[i];
    pom[i]=0;
   }
  }
  k/=2;
  F(i,n)F(j,i+1){
   pom[i]+=a[j]*a[i-j];
   pom[i]%=M;
  }
  F(i,n){
   a[i]=pom[i];
   pom[i]=0;
  }
 }
 F(i,n)
 printf("%d ",wyn[i]);
 printf("\n");
}