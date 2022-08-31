#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define makel(A) scanf("%I64d",&A)
#define pl(A) printf("%I64d ",A)
#define MAX 100001
#define INF 1000000001
int n;
PI t[MAX];
int licz(LL pom){
 int wyn=0;
 while(pom>1){
  wyn++;
  pom+=3;
  pom/=4;
 }
 return max(wyn,1);
}
main(){
 make(n);
 R(i,n){
  make(t[i].FI);
  make(t[i].SE);
 }
 int wyn=0;
 R(i,n){
  int pom=licz(t[i].SE)+t[i].FI;
  if(pom>wyn)wyn=pom;
 }
 printf("%d\n",wyn);
}