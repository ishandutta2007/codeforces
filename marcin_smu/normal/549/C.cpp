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
int n,k;
int p,np;
void wp(){
  puts("Daenerys");
  exit(0);
}
void wnp(){
  puts("Stannis");
  exit(0);
}
main(){
  make2(n,k);
  R(i,n){
    int pom;make(pom);
    if(pom&1)
      np++;
    else
      p++;
  }
  if(n==k){
    if(np&1){
      wnp();
    }else
      wp();
    return 0;
  }
  int il = n-k;
  int inp = (il+1)/2;
  int ip = (il)/2;
  if(il % 2 == 0){
    if(k % 2 == 0){
      wp();
    }else{
      if(inp >= p)
        wnp();
      else
        wp();
    }
  }else{
    if(ip >= np)
      wp();
    if(ip >= p && k % 2 == 0){
      wp();
    }
    wnp();
  }
    
  
}