#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef long double D;
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
#define MAX 100001
int n;
int x[MAX],y[MAX];
D p2[MAX];
int licz_brzeg(int a,int b){
  if(a == 0)return b;
  if(b == 0)return a;
  return __gcd(a,b);
}
main(){
  make(n);
  p2[0] = 1;
  F(i,1,120)p2[i] = p2[i-1] / 2;
  D pusty = 1;
  D jedna = n* (n-1) /2;
  R(i,n){
    pusty /= 2;
    jedna /= 2;
    make2(x[i],y[i]);
  }
  D pole = 0;
  D brzeg = 0;
  D dob = 1 - pusty*(n+1) - jedna;
  R(i,n){
    int k = (i+1)%n;
    F(bok,2,min(100,n)){
      D szan = p2[bok] - pusty;
      pole += szan * (x[i] + x[k]) * (y[i] - y[k]) / 2;
      brzeg += szan * licz_brzeg(abs(x[i] - x[k]),abs(y[i] - y[k]));
      k++;
      if(k == n)k = 0;
    }
  }
  pole /= dob;
  brzeg /= dob;
  if(pole < 0)pole = -pole;
  
  printf("%.13lf\n",double(1 + pole - brzeg/2));
}