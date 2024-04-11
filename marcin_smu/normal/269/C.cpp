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
#define MAX 200001
int n,m,a[MAX],b[MAX],c[MAX],w[MAX],wyn[MAX];
vector<int> d[MAX];
void dfs(int nr){
 R(i,d[nr].size()){
  int ak=d[nr][i];
  if(wyn[ak]==0){
   if(a[ak]==nr)
    wyn[ak]=1;
   else
    wyn[ak]=2;
   int o=a[ak]+b[ak]-nr;
   w[o]-=c[ak];
   if(w[o]==0)dfs(o);
  }
 }
}
main(){
 make(n);make(m);
 R(i,m){
  make(a[i]);make(b[i]);make(c[i]);
  a[i]--;
  b[i]--;
  w[a[i]]+=c[i];
  w[b[i]]+=c[i];
  d[a[i]].PB(i);
  d[b[i]].PB(i);
 }
 R(i,n-1)
  w[i]/=2;
 dfs(0);
 R(i,m)
  printf("%d\n",wyn[i]-1);
}