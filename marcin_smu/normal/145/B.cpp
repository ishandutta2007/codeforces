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
int a,b,c,d;
char z[] = "47";
void nie(){
  puts("-1");
  exit(0);
}
main(){
  make2(a,b);
  make2(c,d);
  if(c == d){
    if(a < c || b < c)nie();
    if(a == c && b == c)nie();
    if(a == c){
      R(i,c){
        putchar('7');
        putchar('4');
      }
      R(i,b-c){
        putchar('7');
      }
      return 0;
    }
    R(i,a-c){
      putchar('4');
    }
    R(i,c){
      putchar('7');
      if(i == c-1){
        R(i,b-c){
          putchar('7');
        }
      }
      putchar('4');
    }
  }else{
    if(c > d){
      if(d+1 != c || a<c || b <c)nie();
      R(i,a-c){
        putchar('4');
      }
      R(i,c){
        putchar('4');
        putchar('7');
      }
      R(i,b-c){
        putchar('7');
      }
      return 0;
    }
    if(c+1 != d|| a<d || b <d)nie();
    putchar('7'); 
    R(i,a-c)
      putchar('4');
    R(i,c){
      putchar('7');
      if(i == c-1){
        R(i,b-d){
          putchar('7');
        }
      }
      putchar('4');
    }
  }
}