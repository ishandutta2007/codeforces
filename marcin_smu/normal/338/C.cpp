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
#define MAX 10001001
int n,wyn[10];
LL t[10],t2[10];
bool cz[MAX];
int w=1e8;
void licz(int nr,int ak,bool cz){
  if(nr == n){
    if(ak < w)
      w = ak;
    return;
  }
  if(cz==0)
    licz(nr+1,ak+wyn[nr]+1+(wyn[nr]!=1),1);
  else
    licz(nr+1,ak+wyn[nr]+(wyn[nr]!=1),1);
  R(i,nr){
    if(t[i] % t[nr] == 0){
      t[i]/=t[nr];
      licz(nr+1,ak+(wyn[nr]!=1),cz);
      t[i]*=t[nr];
    }
  }
}
main(){
  make(n);
  R(i,n)scanf("%lld",&t[i]);
  sort(t,t+n,greater<LL>());
  R(i,n)t2[i] = t[i];
  F(i,2,MAX){
    if(!cz[i]){
      R(j,n){
        while(t2[j]%i == 0){
          t2[j]/=i;
          wyn[j]++;
        }
      }
      for(int j = 1;i*j<MAX;j++)cz[i*j] = 1;
    }
  }
  R(i,n)if(t2[i]>1)wyn[i]++;
  //R(i,n)printf("%d\n",wyn[i]);
  licz(1,wyn[0]+(wyn[0]!=1),0);
  printf("%d\n",w);
}