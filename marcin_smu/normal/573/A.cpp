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
int n;
int wyn;
main(){
  make(n);
  R(i,n){
    int pom;make(pom);
    while(pom%2 == 0)pom/=2;
    while(pom%3 == 0)pom/=3;
    if(i == 0)wyn = pom;
    else{
      if(wyn!=pom){
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
}