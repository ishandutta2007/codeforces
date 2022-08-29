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
#define MAX 100010
int n,t[MAX],j[MAX],np;
int spr(){
  R(i,n/2){
    j[t[i]]-=2;
    if(j[t[i]] < 0)return i;
  }
  if(n&1) if(j[t[n/2]]%2 == 0)return n/2;
  for(int i = n/2-1; i >= 0; i--){
    if(t[i] != t[n-i-1])return n - i-1;
  }
}
main(){
  make(n);R(i,n){
    make(t[i]);t[i]--;
    j[t[i]]++;
  }
  R(i,n)if(j[i]&1)np++;
  if(np > 1){
    puts("0");
    return 0;
  }
  int il = 0;
  while(il<n && t[il] == t[n-il-1])il++;
  if(il == n){
    printf("%lld\n",n*1ll*(n+1)/2);
    return 0;
  }
  int s1 = spr();
  R(i,n/2)swap(t[i],t[n-i-1]);
  R(i,n)j[i] = 0;
  R(i,n)j[t[i]]++;
  np = 0;
  R(i,n)if(j[i]&1)np++;
  int s2 = spr();
  il++;s1++;s2++;
  printf("%lld\n",il*1ll*(s1+s2) - il*1ll*il);
}