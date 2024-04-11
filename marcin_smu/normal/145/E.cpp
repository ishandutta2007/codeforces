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
#define MAX 1000010
struct node{
  int i4,i7;
  int d44,d47,d74,d77;
  int cz;
  void ust(int a){
    if(a == 4){
      i4=1;
      d44=1;
    }else{
      i7=1;
      d77=1;
    }
    d47 = 1;
    d74 = 1;
  }
  void swa(){
    cz=!cz;
    swap(i4,i7);
    swap(d44,d77);
    swap(d47,d74);
  }
  void licz(node& a, node &b){
    i4 = a.i4+b.i4;
    i7 = a.i7+b.i7;
    d44 = a.d44 + b.d44;
    d77 = a.d77 + b.d77;
    d47 = max(a.d47+b.d77,a.d44+b.d47);
    d74 = max(a.d74+b.d44,a.d77+b.d74);
    
  }
}t[MAX*3];
int n,m,nn;
int pp,kp;
void add(int nr,int pk,int kk){
  if(pp > kk || pk > kp)return;
  if(pp <= pk && kk <= kp){
    t[nr].swa();
    return;
  }
  if(t[nr].cz){
    t[nr*2].swa();
    t[nr*2+1].swa();
    t[nr].cz = 0;
  }
  add(nr*2,pk,(pk+kk)/2);
  add(nr*2+1,(pk+kk)/2+1,kk);
  t[nr].licz(t[nr*2],t[nr*2+1]);
  
}
main(){
  make2(n,m);
  nn=1;while(nn <= n)nn*=2;
  scanf(" ");
  R(i,n){
    char z = getchar();
    if(z == '4'){
      t[i+nn].ust(4);
    }else
      t[i+nn].ust(7);
  }
  FD(i,nn)t[i].licz(t[i*2],t[i*2+1]);
  R(i,m){
    char z[7];
    scanf("%s",z);
    if(z[0] == 'c'){
      printf("%d\n",t[1].d47);
    }else{
      make2(pp,kp);
      pp--;kp--;
      add(1,0,nn-1);
    }
  }
}