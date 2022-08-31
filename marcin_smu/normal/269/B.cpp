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
#define MAX 5001
int n,m;
pair<D,int> p[MAX];
int t[MAX];
main(){
 make(n);
 make(m);
 R(i,n)
  scanf("%d%lf",&p[i].SE,&p[i].FI);
 sort(p,p+n);
 int wyn=0;
 R(i,n){
  int po=-1,ko=wyn;
  while(po+1!=ko){
   int mi=(po+ko)/2;
   if(t[mi]<=p[i].SE)
    po=mi;
   else
    ko=mi;
  }
  if(ko==wyn)wyn++;
  t[ko]=p[i].SE;
 }
 printf("%d\n",n-wyn);
}