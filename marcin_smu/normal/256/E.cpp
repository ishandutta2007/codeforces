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
#define MOD 777777777
#define MAXX (1<<17)
int n,m,t[3][3],MAX;
LL dp[MAXX*2][3][3];
bool cz[MAXX*2];
int licz(int nr){
 if(cz[nr*2+1]==0){
  R(i,3)R(j,3)dp[nr][i][j]=dp[nr*2][i][j];
 }else{
  R(i,3)R(j,3)dp[nr][i][j]=0;
  R(i,3)R(j,3)R(k,3)R(l,3){
   if(t[j][k]==1)
    dp[nr][i][l]+=dp[nr*2][i][j]*dp[nr*2+1][k][l];
  }
  R(i,3)R(j,3)dp[nr][i][j]%=MOD;
 }
}
main(){
 make(n);make(m);
 R(i,3)R(j,3)make(t[i][j]);
 MAX=1;while(MAX<=n)MAX*=2;
 R(i,n){
  cz[MAX+i]=1;
  R(j,3)dp[MAX+i][j][j]=1;
 }
 FD(i,MAX){
  cz[i]=(cz[i*2]||cz[i*2+1]);
  if(cz[i*2])licz(i);
 }
 while(m--){
  int a,b;
  make(a);make(b);
  a+=MAX-1;
  if(b!=0){
   R(j,3)dp[a][j][j]=0;
   dp[a][b-1][b-1]=1;
  }else
   R(j,3)dp[a][j][j]=1;
  do{
   a/=2;
   licz(a);
  }while(a!=1);
  int wyn=0;
  R(i,3)R(j,3){
   wyn+=dp[1][i][j];
   if(wyn>=MOD)wyn-=MOD;
  }
  printf("%d\n",wyn);
 }
}