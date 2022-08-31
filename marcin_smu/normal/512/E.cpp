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
#define MAX 1010
int n;
bool cz[MAX][MAX];
struct tri{
  int a,b,c;
};
vector<tri> wyn;
vector<int> d;
void add(int a,int b){
  if(a == 0){
    d.PB(b);
  }
  if(b == 0){
    d.PB(a);
  }
  cz[a][b] = 1;
  cz[b][a] = 1;
}
void licz(int a,int b);
bool spr(int a,int b,int c){
  if(cz[a][b] && cz[a][c] && cz[b][c]){
    wyn.PB({a,b,c});
    licz(a,c);
    licz(c,b);
    return 1;
  }
  return 0;
}
void licz(int a,int b){
  if(a+1 == b)return;
  int i = 1;
  while(1){
    if(spr(a,b,a+i))return;
    if(spr(a,b,b-i))return;
    i++;
  }
}
void licz(){
  wyn.clear();
  d.clear();
  R(i,n)R(j,n)cz[i][j] = 0;
  R(i,n){
    add(i,(i+1)%n);
  }
  R(i,n-3){
    int a,b;
    make2(a,b);a--;b--;
    add(a,b);
  }
  sort(d.begin(),d.end());
  R(i,(int)d.size()-1){
    licz(d[i],d[i+1]);
  }
}
vector<PI> res;
main(){
  make(n);
  licz();
  R(i,wyn.size())
    res.PB(MP(wyn[i].a,wyn[i].b));
  licz();
  FD(i,((int)wyn.size()))
    res.PB(MP(0,wyn[i].c));
  printf("%d\n",(int)res.size());
  R(i,res.size()){
    printf("%d %d\n",res[i].FI+1,res[i].SE+1);
  }
}