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
#define SZ(x) ((int)(x).size())
#define db if(1)printf
template<typename C> void MA(C& a,C b){if(a<b)a=b;}
template<typename C> void MI(C& a,C b){if(a>b)a=b;}
#define MAX 30010
int n;
struct pom{
  int a,b;
  int nr;
};
vector<pom> t[MAX]; 
vector<int> bil;
main(){
  make(n);
  R(i,4*n){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);a--;b--;c--;
    t[a].PB({b,c,i+1});
  }
  R(i,n)bil.PB(i);
  vector<int> wyn;
  while(!bil.empty()){
    int ak = bil.back();
    bil.pop_back();
    if(t[ak].empty())continue;
    pom x = t[ak].back();
    t[ak].pop_back();
    bil.PB(x.a);
    bil.PB(x.b);
    wyn.PB(x.nr);
  }
  puts("YES");
  FD(i,SZ(wyn)){
    printf("%d ",wyn[i]);
  }
  puts("");
}