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
#define MAX 100001
int n,v[MAX];
LL w[MAX],m[MAX];
vector<int> d[MAX];
void dfs(int nr,int o){
 R(i,d[nr].size()){
  if(d[nr][i]==o)continue;
  dfs(d[nr][i],nr);
  w[nr]=max(w[nr],w[d[nr][i]]);
  m[nr]=max(m[nr],m[d[nr][i]]);
 }
 LL ile=v[nr]-w[nr]+m[nr];
 if(ile>0)
 w[nr]+=ile;
 else
 m[nr]-=ile;
}
main(){
 make(n);
 R(i,n-1){
  int a,b;
  make(a);make(b);
  d[a].PB(b);
  d[b].PB(a);
 }
 F(i,1,n+1)make(v[i]);
 dfs(1,-1);
 pl(w[1]+m[1]);
}