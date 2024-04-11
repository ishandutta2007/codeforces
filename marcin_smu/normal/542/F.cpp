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
int n,t;
vector<int> d[MAX];
main(){
  make2(n,t);
  R(i,n){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    d[a].PB(b);
  }
  R(i,t-1){
    sort(ALL(d[i]),greater<int>());
    int j;
    for(j=1;j<d[i].size();j+=2){
      d[i+1].PB(d[i][j] + d[i][j-1]);
    }
    if(j==d[i].size())
      d[i+1].PB(d[i][j-1]);
  }
  sort(ALL(d[t-1]),greater<int>());
  printf("%d\n",d[t-1][0]);
}