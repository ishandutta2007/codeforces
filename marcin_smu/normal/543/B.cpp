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
#define MAX 3001
int odl2[MAX];
int n,m;
queue<int> k;
vector<int> d[MAX];
void add(int a,int od){
  if(odl2[a] == 1e6){
    k.push(a);
    odl2[a] = od;
  }
}
void bfs(int a){
  R(i,n)odl2[i] = 1e6;
  add(a,0);
  while(!k.empty()){
    int ak = k.front();k.pop();
    R(i,d[ak].size()){
      add(d[ak][i],odl2[ak]+1);
    }
  }
}
int odl[MAX][MAX];
void nie(){
  puts("-1");
  exit(0);
}
main(){
  make2(n,m);
  R(i,m){
    int a,b;
    make2(a,b);
    a--;b--;
    d[a].PB(b);
    d[b].PB(a);
  }
  R(i,n){
    bfs(i);
    R(j,n)odl[i][j] = odl2[j];
  }
  int s1,t1,l1;
  int s2,t2,l2;
  make2(s1,t1);s1--;t1--;
  make(l1);
  make2(s2,t2);s2--;t2--;
  make(l2);
  if(odl[s1][t1] > l1)nie();
  if(odl[s2][t2] > l2)nie();
  int wyn = odl[s1][t1] + odl[s2][t2];
  R(i,n)R(j,n){
    int pom1 = min(
      odl[s1][i] + odl[j][t1],
      odl[t1][i] + odl[j][s1]
    );
    int pom2 = min(
      odl[s2][i] + odl[j][t2],
      odl[t2][i] + odl[j][s2]
    );
    int sr = odl[i][j];
    if(pom1 + sr <= l1 && pom2 + sr <= l2){
      MI(wyn,pom1+pom2+sr);
    }
  }
  printf("%d\n",m-wyn);
}