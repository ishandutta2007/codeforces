#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[200000];

void loop(){
 scanf("%d",&N); rep(i,N) scanf("%d",&A[i]);
 bool ok = true;
 rep(i,N-1) if(A[i]!=A[i+1]) ok=false;
 if(ok) printf("%d\n",N);
 else printf("1\n");
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}