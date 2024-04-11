#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
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
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a){
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(C) {for(auto&c:C)cerr<<c<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(C) {}
#define cerr if(0)cout
#endif
D X1,Y1,X2,Y2,r1,r2;
D odl;
const D eps = 1e-8;
const D PI = acos(-1);
D kw(D a){
  return a*a;
}
D pole(D a,D b,D c){
  D p = (a+b+c)/2;
  return sqrt(p * (p-a) * (p-b) * (p-c));
}
D caleczka(D a,D b,D err){
  D w1 = sqrt(1-a*a);
  D w2 = sqrt(1-b*b);
  if(abs(w1-w2)*err < eps){
    return (w1 + w2) * (a-b);
  }else{
    return caleczka(a,(a+b)/2,err/2) + caleczka((a+b)/2,b,err/2);
  }
}
D licz(D r,D h){
  D x = sqrt(r*r - h*h) / r;
  return caleczka(1,x,1/(1-x)) * r * r;
}
D przec(){ // r1 > r2
  if(r1 + r2 < odl + eps) return 0.;
  if(r2 + odl < r1 + eps){
    return kw(min(r1,r2)) * PI;
  }
  D h = pole(r1,r2,odl)*2/ odl;
  if(kw(odl) + kw(h) < kw(r1)+eps){
    return kw(r2) * PI - licz(r2,h) + licz(r1,h);
  }
  return licz(r1,h) + licz(r2,h);
}
int main(){
  cin >> X1 >> Y1 >> r1;
  cin >> X2 >> Y2 >> r2;
  odl = sqrt(kw(X1-X2) + kw(Y1 - Y2));
  debug(odl);
  if(r1 < r2)swap(r1,r2);
  cout << setprecision(12) << przec() << endl;
}