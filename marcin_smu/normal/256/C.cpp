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
#define MAX 1000001
#define INF 777777777777ll
int n,kt=1;
LL t[MAX];
int nim[MAX],mb=(1<<30)-1;
int ile[MAX];
int a4=2,a2=1;
LL kw(LL a){return a*a;}
int ni(LL x){
 int p=0,k=kt;
 while(p+1!=k){
  int m=(p+k)/2;
  if(t[m]<=x)
  p=m;
  else
  k=m;
 }
 return nim[p];
}
void od(int x){
 ile[x]--;
 if(ile[x]==0)
  mb^=(1<<x);
}
int dod(int x){
 ile[x]++;
 if(ile[x]==1)
  mb^=(1<<x);
}
main(){
 nim[0]=0;
 t[0]=0;
 ile[0]=0;
 while(t[kt-1]<=INF){
  if(kw(kw(a4))+1<kw(a2+1)){
   t[kt]=kw(kw(a4))+1;
   od(ni(a4));
   a4++;
  }else{
   t[kt]=kw(a2+1);
   a2++;
   dod(ni(a2));
  }
  nim[kt]=__builtin_ctz(mb);
  
//  printf("%d\n",nim[kt]);
  kt++;
 }
 int x=0;
 make(n);
 R(i,n){
  LL pom;
  makel(pom);
  x^=ni(pom);
 }
 printf("%s\n",x?"Furlo":"Rublo");
}