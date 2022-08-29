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
#define MAX 100010
int n;
int f[MAX],t[MAX];
int find(int a){
  return f[a] == a?a:f[a] = find(f[a]);
}
void uni(int a,int b){
  a=find(a);
  b=find(b);
  f[a] = b;
  t[b] = t[a];
}
vector<int> k,k2;
main(){
  make(n);
  R(i,n){
    make(t[i]);
    k.PB(i);
    f[i] = i;
  }
  int wyn = 0;
  while(1){
    R(_,k.size()){
      int i = k[_];
      if(i!=0 && find(i-1) == find(i))continue;
      int pom = find(i)+1;
      if(pom < n){
        pom = find(pom);
        if(t[i] > t[pom]){
          //printf("%d %d\n",t[i],t[pom]);
          k2.PB(i);
        }
      }
    }
    if(k2.size()==0){
      printf("%d\n",wyn);
      break;
    }
    wyn++;
    R(_,k2.size()){
      int i = k2[_];
      uni(i,find(i)+1);
    }
    swap(k,k2);
    k2.clear();
  }
}