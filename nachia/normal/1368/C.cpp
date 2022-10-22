#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

int main() {
 UL K; cin>>K;
 printf("%u\n0 0\n",3*K+4);
 rep(i,K+1){
  printf("%u %u\n%",i,i+1);
  printf("%u %u\n%",i+1,i);
  printf("%u %u\n%",i+1,i+1);
 }
 return 0;
}