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
#define MAX 200010
int n;
int a[MAX];
D licz(D m){
  D mi = 0;
  D ma = 0;
  D ak = 0;
  R(i,n){
    ak += a[i] + m;
    MI(mi,ak);
    MA(ma,ak);
  }
  return (ma - mi);
}
main(){
  make(n);
  R(i,n)make(a[i]);
  D po = -3e9, ko =  3e9;
  R(i,130){
    D m1 = (po*2+ko)/3;
    D m2 = (po+ko*2)/3;
    D w1 = licz(m1);
    D w2 = licz(m2);
    if(w1 < w2){
      ko = m2;
    }else
      po = m1;
  }
  printf("%.9lf\n",double(licz((po+ko)/2)));
}