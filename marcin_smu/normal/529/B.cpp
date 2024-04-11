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
#define MAX 1001
int n;
int h[MAX],w[MAX];
int licz(int a){
  int il = 0;
  vector<int> zar;
  int sum = 0;
  R(i,n){
    if(h[i] > a){
      if(w[i] > a)return 1e9;
      il++;
      sum += h[i];
    }else{
      sum += w[i];
      if(w[i] <= a){
        int pom = w[i] - h[i];
        if(pom > 0)
          zar.PB(pom);
      }
    }
  }
 // printf("%d %d %d %d %d\n",a,sum,il,n/2,(int)zar.size());
  
  if(il > n/2)return 1e9;
  sort(ALL(zar));
  R(i,n/2-il){
    if(zar.size() > i){
      sum -= zar[zar.size() - i - 1];
    }
  }
//  printf("%d %d\n",a,sum);
  return sum * a;
}
main(){
  make(n);
  R(i,n)make2(w[i],h[i]);
  int wyn = 1e9;
  F(i,1,1001){
  
    MI(wyn,licz(i));
  }
  printf("%d\n",wyn);
}