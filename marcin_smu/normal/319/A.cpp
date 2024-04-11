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
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
#define MAX 101
char z[MAX];
int n;
const int P = 1e9 + 7;
main(){
  scanf("%s",z);
  n=0;while(z[n])n++;
  LL wyn = 0,p2 = 1;
  R(i,n){
    wyn *= 2;
    if(z[n-i-1] == '1'){
      wyn+=p2*p2%P;
    }
    p2 *= 2;
    wyn %= P;
    if(p2 >= P)p2 -= P;
  }
  printf("%lld\n",wyn);
}