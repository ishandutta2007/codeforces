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
int n,x,y,c;
LL iler(LL nr){
 if(nr<0)return 0;
 return (nr+1)*(nr+2)/2;
}
LL ileb(LL nr){
 if(nr<0)return 0;
 return (nr+1)*(nr+1);
}
LL ile(LL nr){
 LL wyn=2*nr*(nr+1)+1;
 wyn-=ileb(nr-(n-x+1));
 wyn-=ileb(nr-(n-y+1));
 wyn-=ileb(nr-x);
 wyn-=ileb(nr-y);
 wyn+=iler(nr-(n-x+1+n-y+1));
 wyn+=iler(nr-(n-x+1+y));
 wyn+=iler(nr-(x+n-y+1));
 wyn+=iler(nr-(x+y));
 return wyn;
}
main(){
 scanf("%d%d%d%d",&n,&x,&y,&c);
 int p=-1,k=2*n;
 while(p+1!=k){
  int m=(p+k)/2;
  if(ile(m)>=LL(c))
  k=m;
  else
  p=m;
 }
 printf("%d\n",k);
}