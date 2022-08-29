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
#define MAX 101
int n,m,t[MAX][MAX],sx[MAX],sy[MAX],sx2[MAX],sy2[MAX];
bool cx[MAX],cy[MAX];
main(){
 make(n);make(m);
 R(i,n)cx[i]=rand()%2;
 R(i,m)cy[i]=rand()%2;
 R(i,n)R(j,m){
  make(t[i][j]);
  if(cx[i]^cy[j]){
   sx[i]+=t[i][j];
   sy[j]+=t[i][j];
  }else{
   sx[i]-=t[i][j];
   sy[j]-=t[i][j];
  }
 }
 bool x=1;
 while(x){
  x=0;
  R(i,n){
   if(sx[i]<0){
    cx[i]=!cx[i];
    sx[i]*=-1;
    x=1;
    R(j,m){
     if(cx[i]^cy[j])
     sy[j]+=2*t[i][j];
     else
     sy[j]-=2*t[i][j];
    }
   }
  }
  
  R(j,m){
   if(sy[j]<0){
    cy[j]=!cy[j];
    sy[j]*=-1;
    x=1;
    R(i,n){
     if(cx[i]^cy[j])
     sx[i]+=2*t[i][j];
     else
     sx[i]-=2*t[i][j];
    }
   }
  }
  
 };
 int il=0;
 R(i,n)if(cx[i]==0)il++;
 printf("%d",il);
 R(i,n)if(cx[i]==0)printf(" %d",i+1);
 printf("\n");
 il=0;
 R(i,m)if(cy[i])il++;
 printf("%d",il);
 R(i,m)if(cy[i])printf(" %d",i+1);
 printf("\n");
}