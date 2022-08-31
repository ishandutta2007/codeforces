#include<bits/stdc++.h>
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
#define make2(A,B) scanf("%d%d",&A,&B)
#define ALL(x) (x).begin(), (x).end()
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX (1<<17)
int n,d[MAX],x[MAX];
void dfs(int i){
  d[i]--;
  d[x[i]]--;
  printf("%d %d\n",x[i],i);
  x[x[i]]^=i;
  if(d[x[i]]==1)dfs(x[i]);
}
main(){
  make(n);
  int sum = 0;
  R(i,n){
    make2(d[i],x[i]);
    sum += d[i];
  }
  printf("%d\n",sum/2);
  R(i,n)if(d[i]==1)dfs(i);
  
}