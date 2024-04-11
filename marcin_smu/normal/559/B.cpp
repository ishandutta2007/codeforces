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
#define MAX 201010
char z[MAX],z2[MAX];
int n;
LL licz(char* p,char* k){
  int il = k - p;
  if(il&1){
    LL hash = 0;
    while(p!=k){
      hash += *p;
      hash *= 123;
      hash %= int(1e9 + 7);
      p++;
    }
    return hash;
  }else{
    LL a = licz(p,p+il/2);
    LL b = licz(p+il/2,k);
    if(a > b)swap(a,b);
    return a^b + a * 1234112 - b*b*b;
  }
}
main(){
  scanf("%s%s",z,z2);
  while(z[n])n++;
  puts(licz(z,z+n) == licz(z2,z2+n)?"YES":"NO");
}