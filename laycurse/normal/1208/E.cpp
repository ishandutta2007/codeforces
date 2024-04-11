#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
inline void wt_L(long long x){
  char f[20];
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> void slideMax(int n, int k, T in[], T res[], void *mem = wmem){
  T *q;
  int i, q_size=0, q_st=0, s=0;
  walloc1d(&q, n);
  for(i=0;i<(n);i++){
    while(q_size && q[q_st+q_size-1] < in[i]){
      q_size--;
    }
    q[q_st+q_size++] = in[i];
    if(i>=k && in[i-k]==q[q_st]){
      q_st++;
      q_size--;
    }
    if(i>=k-1){
      res[s++] = q[q_st];
    }
  }
}
char memarr[96000000];
int N;
int W;
int L;
int A[1000000];
int tmp[2000000];
int mx[2000000];
long long res[1000000];
long long s[1000001];
int main(){
  int Lj4PdHRW, i, j, k, m;
  long long x;
  wmem = memarr;
  rd(N);
  rd(W);
  for(Lj4PdHRW=0;Lj4PdHRW<(N);Lj4PdHRW++){
    rd(L);
    {
      int KL2GvlyY;
      for(KL2GvlyY=0;KL2GvlyY<(L);KL2GvlyY++){
        rd(A[KL2GvlyY]);
      }
    }
    if(2*L <= W){
      m = 0;
      for(i=0;i<(L);i++){
        chmax(m, A[i]);
        res[i] += m;
      }
      m = 0;
      for(i=0;i<(L);i++){
        chmax(m, A[L-1-i]);
        res[W-1-i] += m;
      }
      s[L] += m;
      s[W-L] -= m;
    }
    else{
      k = W - L;
      for(i=0;i<(k);i++){
        tmp[i] = 0;
      }
      for(i=0;i<(L);i++){
        tmp[k+i] = A[i];
      }
      for(i=0;i<(k);i++){
        tmp[k+L+i] = 0;
      }
      slideMax(L+2*k, k+1, tmp, mx);
      for(i=0;i<(W);i++){
        res[i] += mx[i];
      }
    }
  }
  x = 0;
  for(i=0;i<(W);i++){
    res[i] += (x += s[i]);
  }
  {
    int Q5VJL1cS;
    if(W==0){
      putchar('\n');
    }
    else{
      for(Q5VJL1cS=0;Q5VJL1cS<(W-1);Q5VJL1cS++){
        wt_L(res[Q5VJL1cS]);
        wt_L(' ');
      }
      wt_L(res[Q5VJL1cS]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190830-1

// --- original code ---
// //no-unlocked
// int N, W, L, A[1d6];
// 
// int tmp[2d6], mx[2d6];
// ll res[1d6];
// ll s[1000001];
// {
//   int i, j, k, m;
//   ll x;
//   rd(N,W);
//   rep(N){
//     rd(L,A(L));
//     if(2*L <= W){
//       m = 0;
//       rep(i,L){
//         m >?= A[i];
//         res[i] += m;
//       }
//       m = 0;
//       rep(i,L){
//         m >?= A[L-1-i];
//         res[W-1-i] += m;
//       }
//       s[L] += m;
//       s[W-L] -= m;
//     } else {
//       k = W - L;
//       rep(i,k) tmp[i] = 0;
//       rep(i,L) tmp[k+i] = A[i];
//       rep(i,k) tmp[k+L+i] = 0;
//       slideMax(L+2k, k+1, tmp, mx);
//       rep(i,W) res[i] += mx[i];
//     }
//   }
//   x = 0;
//   rep(i,W) res[i] += (x += s[i]);
//   wt(res(W));
// }