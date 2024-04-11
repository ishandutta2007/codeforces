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
#define pll(A) printf("%I64d ",A);
int n,m,k,x,y;
main(){
 make(n);
 make(m);
 make(k);
 while(k--){
  make(x);
  make(y);
  if(x<=5||x>=n-4||
     y<=5||y>=m-4){
   printf("YES\n");
   return 0;
  }
 }
 printf("NO\n");
}