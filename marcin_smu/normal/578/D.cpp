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
#define MAX 100010
LL wyn;
int n,m;
char z[MAX];
LL licz(LL a){
  return (a*a+a)/2;
}
main(){
  make2(n,m);
  if(n==1){
    printf("%d\n",m-1);
    return 0;
  }
  scanf("%s",z);
  char ost = 0;
  int il = 0;
  vector<int> blo;
  vector<char> lit;
  R(i,n){
    if(ost != z[i]){
      if(i){
        blo.PB(il);
        lit.PB(ost);
      }
      il = 0;
      ost = z[i];
    }
    il++;
  }
  blo.PB(il);
  lit.PB(ost);
  //wyn = -SZ(blo)+1;
  int wne = n - SZ(blo);
  R(i,blo.size()){
    if(blo[i] == 1){
      if(i!=0 && i!= SZ(blo)-1 && lit[i-1] == lit[i+1]){
        wyn += (2*m-2);
        wyn += (m-2) * 1ll * (SZ(blo)-3);
        wyn += SZ(blo)-2;
        wyn += (wne+1) * 1ll * (m-1);
        wyn --;
      }else{
        wyn += (2*m-2);
        wyn += (m-2) * 1ll * (SZ(blo)-2);
        wyn += SZ(blo)-1;
        wyn += wne *1ll * (m-1);
        wyn --;
      }
    }else{
      wyn += (2*m-2);
      wyn += (m-2) * 1ll * (SZ(blo)-1);
      wyn += SZ(blo)-1;
      wyn += (wne - 1) * 1ll * (m-1);
    }
  }
  assert(wyn == n *1ll*SZ(blo)* (m-1));
  int i = 0;
  while(1){
    while(z[i] == z[i+1])i++;
    if(i == n-1)break;
    int j = i+1;
    while(z[j+1] == z[j-1])j++;
    wyn -= licz(j-i);
    i = j;
  }
  printf("%lld\n",wyn);
}