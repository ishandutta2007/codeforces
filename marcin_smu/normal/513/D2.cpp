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
int n,c;
#define MAX 1000001
void nie(){
  puts("IMPOSSIBLE");
  exit(0);
}
vector<int> l[MAX],r[MAX];
vector<int> wyn;
int dfs(int i,int cn){
  if(i == cn)return cn-1;
  if(l[i].size() == 0){
    wyn.PB(i);
    R(j,r[i].size())
      MA(cn,r[i][j]+1);
    return dfs(i+1,cn);
  }else{
    int ma = l[i][0];
    R(j,l[i].size())
      MA(ma,l[i][j]);
    int pom = dfs(i+1,ma+1);
    wyn.PB(i);
    R(j,r[i].size())if(r[i][j] <= pom)nie();
    ma = max(cn,pom+1);
    R(j,r[i].size())
      MA(ma,r[i][j]+1);
    return dfs(pom+1,ma);
  }
}
main(){
  make2(n,c);
  R(i,c){
    int a,b;
    make2(a,b);a--;b--;
    if(b <= a)nie();
    char z[6];
    scanf("%s",z);
    if(z[0] == 'L'){
      l[a].PB(b);
    }else{
      r[a].PB(b);
    }
  }
  dfs(0,n);
  R(i,n)printf("%d ",wyn[i]+1);puts("");
}