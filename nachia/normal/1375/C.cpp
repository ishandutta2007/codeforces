#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
UL A[300000];

void Case(){
 scanf("%u",&N);
 rep(i,N) scanf("%u",&A[i]);
 printf(A[0]<A[N-1]?"YES\n":"NO\n");
}

int main() {
 UL T; scanf("%u", &T);
 rep(t,T) Case();
 return 0;
}