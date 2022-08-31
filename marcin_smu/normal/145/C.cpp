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
#define MAX 102001
const int P = 1e9 + 7;
int n,k;
bool isl(int a){
  if(a == 0)return 1;
  return (a%10 == 4 || a%10 == 7) && isl(a/10);
}
int w[MAX];
int iw = -1;
map<int,int> m;
LL pot(LL a,LL w){
  LL r = 1;
  while(w){
    if(w&1){
      r *= a;
      r %= P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return r;
}
LL sil[MAX],odw[MAX];
LL po(int a,int b){
  if(a < b || b < 0)return 0;
  return sil[a] * odw[b] % P * odw[a-b] % P; 
}
main(){
  make2(n,k);
  sil[0] = 1;
  R(i,n+1){
    sil[i+1] = sil[i] * (i+1) % P;
  }
  R(i,n+1){
    odw[i] = pot(sil[i],P-2);
  }
  R(i,n){
    int pom;
    make(pom);
    if(isl(pom)){
      auto x = m.find(pom);
      if(x!=m.end()){
        w[x->SE]++;
      }else{
        iw++;
        m[pom] = iw;
        w[iw] = 1;
      }
    }else{
      iw++;
      w[iw] = 1;  
    }
  }
  iw++;
  vector<int> a;
  a.PB(1);
  int il1=0;
  R(i,iw){
    if(w[i] == 1){
      il1 ++;
    }else{
      a.PB(0);
      vector<int> b;
      b.PB(1);
      F(ii,1,a.size()){
        b.PB((a[ii] + a[ii-1] *1ll* w[i])%P);
      }
      swap(a,b);
    }
  }
  LL wyn = 0;
  while(a.size()<k+1)a.PB(0);
  R(i,k+1){
    wyn += po(il1, i) * a[k-i] % P;
  }
  cout << wyn%P << "\n";
}