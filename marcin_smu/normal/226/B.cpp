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
#define MAX 100001
int n,t[MAX],q,k;
LL sp[MAX],wyny[MAX];
bool qq(int a,int b){
 return a>b;
}
main(){
 make(n);
 R(i,n)make(t[i]);
 sort(t,t+n,qq);
 R(i,n)sp[i+1]=sp[i]+t[i];
 make(q);
 while(q--){
  make(k);
  if(wyny[k]!=0){\
   pll(wyny[k]);
   continue;
  }
  LL wyn=0;
  LL ak=1,il=k,pocz=1;
  while(pocz<n){
   if(il+pocz<=n)
   wyn+=ak*(sp[il+pocz]-sp[pocz]);
   else
   wyn+=ak*(sp[n]-sp[pocz]);
   ak++;
   pocz+=il;
   il*=k;
  }
  wyny[k]=wyn;
  pll(wyn);
 }
 printf("\n");
}