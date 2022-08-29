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
#define MAX 200001
int n,t[MAX],dp[MAX],s[MAX];
void add(int i){
  i++;
  for(;i<=n;i+=(i&-i))dp[i]++;
}
int sum(int i){
  i++;
  int res = 0;
  for(;i;i-=(i&-i))res += dp[i];
  return res;
}
void licz(){
  R(i,n)make(t[i]);
  R(i,n+1)dp[i] = 0;
  FD(i,n){
    s[i] += sum(t[i]);
    int m = n-i;
    while(s[i] >= m){
      s[i] -= m;
      if(i)s[i-1] ++;
    }
    add(t[i]);
  }
}
main(){
  make(n);
  licz();
  licz();
  R(i,n+1)dp[i] = 0;
  R(i,n){
    int po = -1,ko = n;
    while(po+1 != ko){
      int m = (po+ko)/2;
      if(sum(m) <= m-s[i])
        ko = m;
      else
        po = m;
    }
    add(ko);
    printf("%d ",ko);
  }
  puts("");
}