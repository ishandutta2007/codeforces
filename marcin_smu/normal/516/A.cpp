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
int n;
vector<int> wyn;
int il = 0;
main(){
  scanf("%d ",&n);
  R(i,n){
    char a = getchar();
    switch(a){
      case '9':
        wyn.PB(7);
        wyn.PB(3);
        wyn.PB(3);
        wyn.PB(2);
      break;
      case '8':
        wyn.PB(7);
        wyn.PB(2);
        wyn.PB(2);
        wyn.PB(2);
      break;
      
      case '6':
        wyn.PB(5);
        wyn.PB(3);
      break;
      case '4':
        wyn.PB(3);
        wyn.PB(2);
        wyn.PB(2);
      break;
      case '7':
      case '5':
      case '3':
      case '2':
        wyn.PB(a - '0');
      break;
    }
  }
  sort(ALL(wyn));
  FD(i,int(wyn.size())){
    putchar(wyn[i] + '0');
  }
  puts("");
}