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
int X1,Y1,X2,Y2;
void spr(){
  int ruchy = X2 - X1;
  if(ruchy <= 0)return;
  int yy = max(0,Y2-ruchy);
  int ruchy2 = Y1 - yy;
  if(ruchy2 <= ruchy){
    puts("Polycarp");
    exit(0);
  }
}
main(){
  make2(X1,Y1);
  make2(X2,Y2);
  spr();
  swap(X1,Y1);
  swap(X2,Y2);
  spr();
  puts("Vasiliy");
  
}