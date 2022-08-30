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
#define MAX 1001
bool cz[MAX];
int n;
main(){
 make(n);
 int ak=0;cz[0]=1;
 for(int i=0;i<n*n;i++){
  ak+=i;
  ak%=n;
  cz[ak]=1;
 }
 for(int i=0;i<n;i++){
  if(cz[i]==0){
   printf("NO\n");
   return 0;
  }
 }
 printf("YES\n");
}