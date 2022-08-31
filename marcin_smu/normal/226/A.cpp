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
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A);
#define makel(A) scanf("%I64d",&A);
#define pl(A) printf("%I64d ",A);
int n,m;
LL wyn=2,a=3,b=1,pa,pb;
main(){
 make(n);
 make(m);
 n--;
 while(n){
  if(n&1){
   wyn=wyn*a+b*2;
   wyn%=m;
  }
  n/=2;
  pa=a*a;
  pb=a*b+b;
  a=pa%m;
  b=pb%m;
 }
 printf("%d",int(wyn)%m);
}