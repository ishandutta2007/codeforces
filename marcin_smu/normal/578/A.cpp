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
int a,b;
main(){
  make2(a,b);
  if(a < b)
    puts("-1");
  else if(a == b)
    printf("%d\n",a);
  else {
    int pom = (a+b);
    int x = pom / (2*b);
    D w1 = D(pom)/x/2;
    
    int k = (a-b) / (2*b);
    D w2 = D(a-b)/k/2;
    printf("%.12lf\n",min(w1,w2));
  }
}