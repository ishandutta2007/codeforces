#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>

#define MOD 1000000007
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;int N, R;
int fact[500000], invfact[500000];
//---------------------------------------
//NCR PASCAL
//--------------------------------------- 
int powmod(int base, int expo) {
  if(expo==0)
    return 1;
  else if(expo&1)
    return (long long)base*powmod(base, expo-1)%MOD;
  else{
    int root=powmod(base, expo>>1);
    return (long long)root*root%MOD;
  }
}

int Min(int a, int b) {
  return (a < b ? a : b);
}

int inverse(int x) {
  return powmod(x, MOD-2);
}
 
void init() {
  fact[0]=1;
  for(int i=1; i<=N; i++) {
    fact[i]=(long long)i*fact[i-1]%MOD;
  }
  invfact[N]=inverse(fact[N]);
  for(int i=N; i>0; i--) {
    invfact[i-1]=(long long)i*invfact[i]%MOD;
  }
}
 
int nCr_mod(int n, int r){
  if(r>n || r<0)
    return 0;
  return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}
//---------------------------------------
//NCR PASCAL
//--------------------------------------- 
void print1d(LL *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) cout << " ";
    cout << vec[i];
  }
  cout << "\n";
}
void print1d_int(int *vec, int M, const char *str=NULL) {
  if(str != NULL) printf("%s ", str);
  for(int i=0; i<M; i++) {
    if(i>0) cout << " ";
    cout << vec[i];
  }
  cout << "\n";
}
LL **alloc2d(int M, int N) {
  LL **a = new LL * [M];
  for(int i=0; i<M; i++) a[i] = new LL [N];
  return a;
}
int exp(int k){
  if(k == 0){
    return 1;
  }
  return 2*exp(k-1);
}
int islucky(int n, int numdigits){
  if(n == 0){
    return numdigits;
  }
  if(n % 10 == 4 || n % 10 == 7){
    return islucky((n - n % 10)/10, numdigits + 1);
  } else {
    return 0;
  }
}
int base2(int numdigits, int n){
  int a = 1;
  int k = n;
  for(int i = 0; i < numdigits; i++){
    a *= 2;
    if(k % 10 == 7){
      a++;
    }
    k = (k - k % 10)/ 10;
  }
  return a;
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int num, take;
  scanf("%d%d", &num, &take);
  int seq[num];
  int nUnlucky = 0;
  int freq0[4096];
  memset(freq0, 0, sizeof(freq0));

  for(int i = 0; i < num; i++){
    scanf("%d", &seq[i]);
    int a = islucky(seq[i], 0);
    if(a == 0){
      nUnlucky++;
    } else {
      int b2 = base2(a, seq[i]);
      if(DEBUG) {
	printf("islucky(%d)= %d, b2= %d\n", seq[i], a, b2);
      }
      freq0[b2]++;
    }
  }
  N = nUnlucky + 1;
  init();
  LL luckyFreq[4096];
  int nLucky = 0;
  for(int i = 0; i < 4096; i++){
    if(freq0[i] > 0){
      luckyFreq[nLucky++] = freq0[i];
    }
  }
  //NEW DP :)
  if(DEBUG) cout << "nLucky " << nLucky << endl << "nUnlucky " << nUnlucky << endl;
  if(DEBUG) print1d(luckyFreq, nLucky, "luckyFreq: ");
  LL dp[2][nLucky+2];
  for(int i = 0; i<2; i ++) for(int j=0; j<nLucky+2; j++) dp[i][j] = 0;

  dp[0][0] = 1;
  for(int i = 1; i <= nLucky; i++){
    dp[i%2][0] = 1;
    for(int j = 1; j < i + 1; j++){
      dp[i%2][j] = (luckyFreq[i-1]*dp[(i-1)%2][j-1] + dp[(i-1)%2][j]) % MOD;
    }
    if(DEBUG) {
      printf("dp[%d]: ", i);
      print1d(dp[i%2], i + 1);
    }
  }
  LL sum = 0;
  if( take <= (nLucky+nUnlucky) ) {
    // i is unlucky
    for(int i = 0; i<=Min(nUnlucky, take); i++){
      if( (i+nLucky) >= take ) {
	LL choose = nCr_mod(nUnlucky, i);
	sum += (nCr_mod(nUnlucky, i) * dp[nLucky % 2][take-i]) % MOD;
	sum = sum % MOD;      
	if(DEBUG) cout << "i= " << i << " choose= " << choose << " sum= " << sum << endl;
      }
    }
  }
  cout << sum << endl;
  exit(0);
}