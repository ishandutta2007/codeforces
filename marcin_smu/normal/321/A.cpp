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
int a,b,dx,dy;
char k[] = "UDLR";
int x[] = {0,0,-1,1};
int y[] = {1,-1,0,0};
int n;
char z[1000];
main(){
  scanf("%d%d%s",&a,&b,z);
  int n=0;while(z[n])n++;
  R(i,n){
    R(j,4){
      if(z[i] == k[j]){
        dx+=x[j];
        dy+=y[j];
      }
    }
  }
  R(i,n){
    if(dx == 0 && dy == 0){
      if(a == 0 && b == 0){
        puts("Yes");
        return 0;
      }
    }else if(dx == 0 && dy != 0){
      if(a == 0 && b%dy == 0 && b/dy >= 0){
        puts("Yes");
        return 0;
      }
    }else if(dx != 0 && dy == 0){
      if(b == 0 && a%dx == 0 && a/dx >= 0){
        puts("Yes");
        return 0;
      }
    }else{
      if(a%dx == 0 && b%dy == 0 && a/dx == b/dy && a/dx >= 0){
        puts("Yes");
        return 0;
      }
    }
    R(j,4){
      if(z[i] == k[j]){
        a-=x[j];
        b-=y[j];
      }
    }
  }
  puts("No");
}