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
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}
int a,b,c,d;
pair<D,D> prze(D a,D b,D d){
  vector<D> x{(a + d) * (b + d),
              (a + d) * (b - d),
              (a - d) * (b - d),
              (a - d) * (b + d)};
  sort(ALL(x));
  return MP(x[0],x[3]);
}
bool spr(D m){
  pair<D,D> p1 = prze(a,d,m);
  pair<D,D> p2 = prze(b,c,m);
  if(p1.FI > p2.SE || p2.FI > p1.SE)
    return 0;
  return 1;
}
main(){
  make2(a,b);
  make2(c,d);
  D po = 0., ko = 1e11;
  R(i,100){
    D m = (po + ko) / 2;
    if(spr(m))
      ko = m;
    else
      po = m;
  }
  printf("%.10f\n",ko);
}