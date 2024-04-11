#include<bits/stdc++.h>
using namespace std;
using UL=unsigned int;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
LL A[100000];

int main(){
 scanf("%d",&N);
 rep(i,N) scanf("%lld",&A[i]);

 if(N==1){ printf("1 1\n0\n1 1\n0\n1 1\n%d\n",-A[0]); return 0; }

 printf("1 1\n%lld\n",-A[0]);
 A[0]=0;
 printf("2 %d\n",N);
 rep(i,N-1){ if(i)printf(" "); printf("%lld",A[i+1]*(N-1)); }
 printf("\n");
 printf("1 %d\n",N);
 rep(i,N){ if(i)printf(" "); printf("%lld",-A[i]*N); }
 printf("\n");
 return 0;
}