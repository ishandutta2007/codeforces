#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class T> inline int isPrime_L(T n){
  T i;
  if(n<=1){
    return 0;
  }
  if(n<=3){
    return 1;
  }
  if(n%2==0){
    return 0;
  }
  for(i=3;i*i<=n;i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}
int N;
int M;
int K;
int L[100000+1];
int R[100000+1];
unsigned long long p;
map<unsigned long long,int> memo[100000+1];
int solve(int dep, vector<int> s){
  int i;
  int res = 0;
  int t1 = 0;
  int t2 = 0;
  int cur;
  unsigned long long hs = 0;
  sort(s.begin(), s.end());
  for(i=(0);i<(s.size());i++){
    hs = hs * p + s[i];
  }
  if(memo[dep].count(hs)){
    return memo[dep][hs];
  }
  if(s.size()){
    cur = L[dep-1];
    while(s.size() && s[0] <= L[dep]){
      if(s.size() % 2){
        res += s[0] - cur;
      }
      cur = s[0];
      s.erase(s.begin());
    }
    if(s.size() % 2){
      res += L[dep] - cur;
    }
  }
  if(dep != N){
    t1 = solve(dep+1, s);
    s.push_back(R[dep]);
    t2 = solve(dep+1, s);
  }
  return memo[dep][hs] = res +max_L(t1, t2);
}
int main(){
  wmem = memarr;
  int res;
  rd(N);
  rd(M);
  rd(K);
  {
    int RZTsC2BF;
    for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
      rd(L[RZTsC2BF]);L[RZTsC2BF] += (-1);
      rd(R[RZTsC2BF]);
    }
  }
  sortA_L(N, L, R);
  p = rand() % 89478471 + 1000000000;
  while(!isPrime_L(p)){
    p++;
  }
  L[N] = 1073709056;
  res = solve(0, vector<int>());
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200217-1

// --- original code ---
// //no-unlocked
// int N, M, K;
// int L[1d5+1], R[1d5+1];
// 
// ull p;
// map<ull,int> memo[1d5+1];
// 
// int solve(int dep, vector<int> s){
//   int res = 0, t1 = 0, t2 = 0, cur;
//   ull hs = 0;
//   sort(s.begin(), s.end());
//   rep(i,s.size()) hs = hs * p + s[i];
//   if(memo[dep].count(hs)) return memo[dep][hs];
// 
//   if(s.size()){
//     cur = L[dep-1];
//     while(s.size() && s[0] <= L[dep]){
//       if(s.size() % 2) res += s[0] - cur;
//       cur = s[0];
//       s.erase(s.begin());
//     }
//     if(s.size() % 2) res += L[dep] - cur;
//   }
// 
//   if(dep != N){
//     t1 = solve(dep+1, s);
//     s.push_back(R[dep]);
//     t2 = solve(dep+1, s);
//   }
// 
//   return memo[dep][hs] = res + max(t1, t2);
// }
// 
// {
//   int res;
//   rd(N,M,K,(L--,R)(N));
//   sortA(N, L, R);
//   p = rand() % 89478471 + 1000000000;
//   while(!isPrime(p)) p++;
// 
//   L[N] = int_inf;
//   res = solve(0, vector<int>());
//   wt(res);
// }