#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16]={0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
inline void rd(int &x){
  int k, m=0;
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
  char f[10];
  int m=0, s=0;
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
int Prime_L(int N, int res[], void *mem=wmem){
  bool *isprime;
  const int r=23000;
  int a, b, i, *sf, ss=1, sz=1;
  walloc1d(&isprime, r, &mem);
  walloc1d(&sf, r, &mem);
  isprime = (bool*)mem;
  sf = (int*)(isprime + r);
  N /= 2;
  res[0] = 2;
  b =min_L(r, N);
  for(i=(1);i<(b);i++){
    isprime[i] = 1;
  }
  for(i=(1);i<(b);i++){
    if(isprime[i]){
      res[sz++] = 2*i+1;
      sf[ss] = 2*i*(i+1);
      if(sf[ss] < N){
        while(sf[ss] < r){
          isprime[sf[ss]] = 0;
          sf[ss] += res[ss];
        }
        ss++;
      }
    }
  }
  for(a=r; a<N; a+=r){
    b =min_L(a + r, N);
    isprime -= r;
    for(i=(a);i<(b);i++){
      isprime[i] = 1;
    }
    for(i=(1);i<(ss);i++){
      while(sf[i] < b){
        isprime[sf[i]] = 0;
        sf[i] += res[i];
      }
    }
    for(i=(a);i<(b);i++){
      if(isprime[i]){
        res[sz++] = 2*i+1;
      }
    }
  }
  return sz;
}
template<class T> inline T popLast(multiset<T> &a){
  T res;
  typename multiset<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
template<class T> inline T popLast(set<T> &a){
  T res;
  typename set<T>::iterator it;
  it = a.end();
  it--;
  res = *it;
  a.erase(it);
  return res;
}
char memarr[96000000];
int N;
multiset<int> B;
int As;
int A[200000];
int ps;
int p[200010];
int cnv[2800000];
int main(){
  int Lj4PdHRW, i, j, k;
  multiset<int>::iterator it;
  wmem = memarr;
  ps =Prime_L(2750132, p);
  for(i=0;i<(ps);i++){
    cnv[p[i]] = i+1;
  }
  for(i=(2);i<(200001);i++){
    if(cnv[i]){
      continue;
    }
    for(j=2;j*j<=i;j++){
      if(i%j==0){
        break;
      }
    }
    cnv[i] = i/j;
  }
  rd(N);
  for(Lj4PdHRW=0;Lj4PdHRW<(2*N);Lj4PdHRW++){
    rd(i);
    B.insert(i);
  }
  while(B.size()){
    k = popLast(B);
    i = cnv[k];
    if(p[i-1]==k){
      A[As++] =i;
    }
    else{
      A[As++] =k;
    }
    it = B.lower_bound(i);
    B.erase(it);
  }
  {
    int KL2GvlyY;
    if(N==0){
      putchar('\n');
    }
    else{
      for(KL2GvlyY=0;KL2GvlyY<(N-1);KL2GvlyY++){
        wt_L(A[KL2GvlyY]);
        wt_L(' ');
      }
      wt_L(A[KL2GvlyY]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190820-1

// --- original code ---
// //no-unlocked
// int N; multiset<int> B;
// int As, A[2d5];
// 
// int ps, p[200010];
// int cnv[2800000];
// 
// {
//   int i, j, k;
//   multiset<int>::iterator it;
// 
//   ps = Prime(2750132, p);
//   rep(i,ps) cnv[p[i]] = i+1;
//   rep(i,2,200001){
//     if(cnv[i]) continue;
//     for(j=2;j*j<=i;j++) if(i%j==0) break;
//     cnv[i] = i/j;
//   }
// 
//   rd(N);
//   rep(2N){
//     rd(i);
//     B.insert(i);
//   }
// 
//   while(B.size()){
//     k = popLast(B);
//     i = cnv[k];
//     A[As++] = if[p[i-1]==k, i, k];
//     it = B.lower_bound(i);
//     B.erase(it);
//   }
// 
//   wt(A(N));
// }
//