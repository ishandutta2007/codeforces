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
template<typename C> void maxi(C& a,C b){if(a<b)a=b;}
template<typename C> void mini(C& a,C b){if(a>b)a=b;}
#define MAX 200100
int t[MAX],n,w1[MAX],w2[MAX];
void licz(int *w){
  R(i,n){
    int ak = i-1;
    while(ak != -1 && t[ak] >= t[i])ak = w[ak];
    w[i] = ak;
  }
  R(i,n)
    w[i] = i - w[i];
}
int wyn[MAX];
main(){
  make(n);
  R(i,n)make(t[i]);
  licz(w1);
  R(i,n/2)swap(t[i],t[n-i-1]);
  licz(w2);
  R(i,n){
    int pom = w2[i] + w1[n-i-1]-2;
    maxi(wyn[pom],t[i]);
  }
  FD(i,n){
    maxi(wyn[i], wyn[i+1]);
  }
  R(i,n)printf("%d ",wyn[i]);
  puts("");
}