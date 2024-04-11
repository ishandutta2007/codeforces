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
#define MAX 1010
int n,m,k;
char z[MAX];
void draw(){
  puts("Draw");
  exit(0);
}
void win1(){
  puts("First");
  exit(0);
}

void win2(){
  puts("Second");
  exit(0);
}
int il[MAX];
main(){
  make2(n,m);
  if(m == 1)win2();
  
  make(k);
  bool czg = 0,czr = 0;
  R(i,n){
    scanf("%s",z);
    int gr = -1;
    int gg = -1;
    bool czp = 0;
    R(j,m){
      if(z[j] == 'R')
        gr = j;
      if(z[j] == 'G')
        gg = j;
      if(z[j] == '-')
        czp = 1;
      
    }
    if(gr == -1 && gg == -1)continue;
    if(gg == -1 && czp){
      czr = 1;
    }
    if(gr == -1 && czp){
      czg = 1;
    }
    if(gr != -1 &&  gg != -1){
      int odl = abs(gr - gg) - 1;
      R(i,8){
        if(odl & 1<<i){
          il[i]++;
        }
      }
    }
  }
  if(czr && czg)draw();
  if(czg)win1();
  if(czr)win2();
  R(i,8)
    if(il[i]%(k+1))win1();
  win2();
}