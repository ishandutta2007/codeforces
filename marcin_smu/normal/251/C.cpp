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
#define MAX 500000
LL a,b;
int k,t[MAX],t2[MAX];
int nwd(int a,int b){
 while(b){
  int pom=b;
  b=a%b;
  a=pom;
 }
 return a;
}
main(){
 makel(a);
 makel(b);
 make(k);
 int n=1;
 F(i,1,k+1){
  int pom=nwd(n,i);
  n*=i/pom;
 }
 t[0]=1;
 F(i,1,n){
  t[i]=t[i-1]+1;
  for(int j=2;j<=k;j++){
   if(t[i-i%j]+1<t[i])
    t[i]=t[i-i%j]+1;
  }
 }
 int pom=b%n;
 R(i,pom)t2[i]=n+1;
 t2[pom]=0;
 F(i,pom+1,n){
  t2[i]=t2[i-1]+1;
  for(int j=2;j<=k;j++){
   if(t2[i-i%j]+1<t2[i])
    t2[i]=t2[i-i%j]+1;
  }
 }
 if(a/n==b/n)
  printf("%d\n",t2[a%n]);
 else
  pl(t[a%n]+t2[n-1]+t[n-1]*LL((a/n)-(b/n)-1));
}