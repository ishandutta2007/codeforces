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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 100001
#define LM 20
int n,il[MAX],x[MAX],wyn,k2[MAX];
bool kw[MAX][LM];
void dfs(int nr){
  while(kw[nr][k2[nr]]==1)k2[nr]++;
  if(k2[nr]>wyn)wyn=k2[nr];
  if(il[nr]==0)return;
  for(int i=0;i<k2[nr];++i)
  kw[nr][i]=0;
  kw[nr][k2[nr]]=1;
  for(int i=0;i<LM;i++){
    if(kw[x[nr]][i]&&kw[nr][i]&&i>k2[x[nr]])k2[x[nr]]=i;
    kw[x[nr]][i]|=kw[nr][i];
  }
  --il[x[nr]];
  --il[nr];
  x[x[nr]]^=nr;
  if(il[x[nr]]<2)dfs(x[nr]);
}
int read_int(){
  int wyn = 0,pom;
  pom = getchar();
  while(pom<='9' && pom>='0'){
    wyn*=10;
    wyn+=pom-'0';
    pom = getchar();
  }
  return wyn;
}
main(){
  n = read_int();
  for(int i=1;i<n;++i){
    int a = read_int(),b = read_int();
    ++il[a];
    ++il[b];
    x[a]^=b;
    x[b]^=a;
  }
  for(int i=1;i<=n;++i)
    if(il[i]==1)dfs(i);
  F(i,1,n+1){
    putchar('A' + wyn - k2[i]);
    putchar(' ');
  }
  puts("");
}