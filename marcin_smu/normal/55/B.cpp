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
LL t[4];
char t2[3];
LL wyn=-1;
void licz(LL pom[4],int il){
 if(il==1){
  if(wyn==-1||pom[0]<wyn)
  wyn=pom[0];
  return;
 }
 for(int i=0;i<il;i++)
 for(int j=i+1;j<il;j++){
  LL pom2[4];
  int kt=1;
  pom2[0]=(t2[4-il]=='+'?pom[i]+pom[j]:pom[i]*pom[j]);
  for(int k=0;k<il;k++){
   if(k!=i&&k!=j)
   pom2[kt++]=pom[k];
  }
  licz(pom2,il-1);
 }
}
main(){
 R(i,4)makel(t[i]);
 R(i,3)scanf(" %c",&t2[i]);
 licz(t,4);
 pll(wyn);
}