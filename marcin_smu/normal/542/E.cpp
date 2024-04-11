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
#define MAX 1001
int n,m;
vector<int> d[MAX];
int kol[MAX];
void nie(){
  puts("-1");
  exit(0);
}
int res;
bitset<1001> s[MAX];
vector<int> b1;
int bfs(int i){
  bitset<1001> ak;
  b1.clear();
  ak[i] = 1;
  b1.PB(i);
  int wyn = -1;
  while(b1.size()){
    bitset<1001> nowe;
    R(i,b1.size()){
      int pom = b1[i];
      nowe |= (s[pom]|ak)^ak;
      ak |= s[pom];    
    }
    wyn ++;
    b1.clear();
    R(i,n)if(nowe[i])b1.PB(i);
  }
  return wyn;
}
void dfs(int a){
  MA(res,bfs(a));
  R(i,d[a].size()){
    int ak = d[a][i];
    if(kol[ak] == 0){
      kol[ak] = 3 - kol[a];
      dfs(ak);
    }
    if(kol[ak] + kol[a] != 3)nie();
  }
}
main(){
  make2(n,m);
  R(i,m){
    int a,b;
    make2(a,b);a--;b--;
    d[a].PB(b);
    d[b].PB(a);
    s[a][b] = 1;
    s[b][a] = 1;
  }
  int wyn = 0;
  R(i,n){
    if(kol[i] == 0){
      kol[i] = 1;
      res = 0;
      dfs(i);
      wyn += res;
    }
  }
  printf("%d\n",wyn);
}