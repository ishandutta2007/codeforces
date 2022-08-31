#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef unsigned long long LL;
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

#define MAX (1<<19)
LL t[MAX*2],t2[MAX*2],t3[MAX*2],t4[MAX*2];
const unsigned P = 2013265921; //15*2^27+1
const unsigned gen = 440564289;//jakis generator w Zp
LL power(LL a,int w){
  LL ret=1;
  while(w){
    if(w&1){
      ret*=a;
      ret%=P;
    }
    w/=2;
    a*=a;
    a%=P;
  }
  return ret;
}
void FFT(LL *a,LL *b,LL x,int n){ // x ma rzad n
  if(n == 1){
    b[0] = a[0];
    return;
  }
  n>>=1;
  LL *ar = new LL[n];
  LL *b1 = new LL[n];
  LL *b2 = new LL[n];
  R(i,n)ar[i] = a[i*2]; 
  FFT(ar,b1,x*x%P,n);
  R(i,n)ar[i] = a[i*2+1]; 
  FFT(ar,b2,x*x%P,n);
  delete[] ar;
  LL xi = 1;
  R(i,n){
    b[i] = (b1[i] + b2[i] * xi) % P;
    xi = xi*x%P;
  }
  R(i,n){
    b[i+n] = (b1[i] + b2[i] * xi) % P;
    xi = xi*x%P;
  }
  delete[] b1;
  delete[] b2;
  if(xi != 1)exit(1);
}
int n,m,k;
char s[MAX],s2[MAX];
int wyn[MAX];
void add(int il,int st,int diff){
  if(il == 0 || st == -1 || st > n || t[st] == 1 )return;
  t[st] = 1;
  add(il-1,st+diff,diff);
}
void licz(char z){
  
  int nn = 1;while(nn <= n)nn *= 2;
  if(nn > 1<<18) nn = 1<<18;
  
  R(i,nn)t2[i] = t[i] = 0;
  R(i,n)if(s[i] == z)t[i]=1;
  R(i,n)if(s[i] == z){
    add(k,i-1,-1);
    add(k,i+1,1);
  }
  int il = 0;
  R(i,m){
    if(s2[i] == z){
      t2[m-i-1] = 1;
      il++;
    }
  }
 // R(i,nn)printf("%llu ",t[i]);puts("");
 // R(i,nn)printf("%llu ",t2[i]);puts("");
  LL pom = power(gen, (1<<27)/ nn);
  FFT(t, t3, pom, nn);
  FFT(t2, t4, pom, nn);
  R(i,nn)t3[i]=t3[i]*t4[i]%P * power(nn,P-2)%P;
  FFT(t3, t, power(pom, nn-1), nn);
 // R(i,nn)printf("%llu ",t[i]);puts("");
  F(i,m-1,n){
    if(t[i] == il){
      wyn[i]++;
    }
  }
  
}
char xxxx[] = "ACGT";
main(){
  make(n);make(m);make(k);
  scanf(" %s %s",s,s2);
  R(i,4)licz(xxxx[i]);
  int res=0;
  F(i,m-1,n){
 //   printf("%d ",wyn[i]);
    if(wyn[i] == 4)res++;
  }
  //puts("");
  printf("%d\n",res);
}