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
#define MAX 200
int n,k,q[MAX],r[MAX],s[MAX],z[MAX][MAX];
main(){
 make(n);make(k);
 R(i,n){
  make(q[i]);
  q[i]--;
 }
 R(i,n)
  r[q[i]]=i;
 R(i,n){
  make(s[i]);
  s[i]--;
 }
 bool x=0;
 for(int i=0;i<n;i++)
  if(s[i]!=i)x=1;
 if(x==0){
  printf("NO\n");
  return 0;
 }
 for(int i=0;i<n;i++)
  if(q[i]!=r[i])x=0;
 if(x&&k!=1){
  printf("NO\n");
  return 0;
 }
 R(i,n)z[0][i]=i;
 F(i,1,k+1){
  bool x=1;
  R(j,n){
   z[i][j]=z[i-1][q[j]];
   if(z[i][j]!=s[j])x=0;
  }
  if(x){
   if(((k+i)&1)==0){
    printf("YES\n");
    return 0;
   }
   break; 
  }
 }
 F(i,1,k+1){
  bool x=1;
  R(j,n){
   z[i][j]=z[i-1][r[j]];
   if(z[i][j]!=s[j])x=0;
  }
  if(x){
   if(((k+i)&1)==0){
    printf("YES\n");
    return 0;
   }
   break; 
  }
 }
 printf("NO\n");
}