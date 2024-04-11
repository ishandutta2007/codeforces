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
#define MAX 200101
int n,q;
set<int> s;
int f[MAX];
int find(int a){
  return f[a] == a ? a: f[a] = find(f[a]);
}
void uni(int a,int b){
  a = find(a);
  b = find(b);
  f[a] = b;
}
main(){
  make2(n,q);
  R(i,n){
    s.insert(i);
    f[i] = i;
  }
  R(i,q){
    int z,a,b;
    make(z);
    make2(a,b);a--;b--;
    if(z == 1){
      uni(a,b);
    }else if(z == 2){
      auto x = s.lower_bound(a);
      while(*x < b){
        int pom = *x;
        uni(pom,pom+1);
        auto y = x;
        x++;
        s.erase(y);
      }
    }else{
      puts(find(a) == find(b) ?  "YES" : "NO");
    }
  }
}