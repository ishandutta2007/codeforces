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
#define MAX 102
int n,m,t[MAX],wyn=0,cz[MAX],f[MAX];
int find(int nr){
  return f[nr]==nr?nr:f[nr]=find(f[nr]);
}
int Union(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b)wyn--;
  f[a]=b;
}
main(){
  make(n);make(m);
  wyn=m-1;
  R(i,m+1)f[i]=i;
  int czy=1;
  for(int i=0;i<n;i++){
    int pom;make(pom);
    if(pom==0){
     wyn++;
    }else
      czy=0;
    R(j,pom){
      make(t[j]);
      cz[t[j]]=1;
    }
    R(j,pom-1)Union(t[j],t[j+1]);
  }
  F(i,1,m+1){if(cz[i]==0)wyn--;}
  printf("%d\n",wyn+czy);
}