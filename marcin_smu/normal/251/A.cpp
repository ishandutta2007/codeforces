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
LL wyn;
int n,d,t[MAX];
main(){
 make(n);
 make(d);
 R(i,n){
  make(t[i]);
 }
 int k=1;
 for(int i=0;i<n;i++){
  while(k<n&&t[i]+d>=t[k])k++;
   wyn+=(k-i-1)*(LL)(k-i-2)/2;
 }
 pl(wyn);
 printf("\n");
}