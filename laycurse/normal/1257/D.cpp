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
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S> void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[200000];
int M;
int P[200000];
int S[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int k;
  int res;
  int mx;
  int cnt;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    rd(M);
    {
      int xr20shxY;
      for(xr20shxY=(0);xr20shxY<(M);xr20shxY++){
        rd(P[xr20shxY]);
        rd(S[xr20shxY]);
      }
    }
    rsortA_L(M,P,S);
    k = 0;
    for(i=(0);i<(M);i++){
      if(k==0 || S[i] > S[k-1]){
        arrInsert(k,k,P,P[i],S,S[i]);
      }
    }
    M = k;
    for(i=(0);i<(N);i++){
      if(A[i] > P[0]){
        wt_L(-1);
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    res = k = 0;
    while(k < N){
      res++;
      mx = A[k++];
      cnt = 1;
      i = 0;
      while(k < N){
        if(max_L(A[k], mx)<= P[i] && cnt < S[i]){
          chmax(mx, A[k]);
          k++;
          cnt++;
          continue;
        }
        if(i+1==M ||max_L(A[k], mx)> P[i+1]){
          break;
        }
        i++;
      }
    }
    wt_L(res);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20191123-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], M, P[2d5], S[2d5];
// {
//   int i, k, res;
//   int mx, cnt;
//   REP(rd_int()){
//     rd(N,A(N),M,(P,S)(M));
//     rsortA(M,P,S);
// 
//     k = 0;
//     rep(i,M) if(k==0 || S[i] > S[k-1]) arrInsert(k,k,P,P[i],S,S[i]);
//     M = k;
// 
//     rep(i,N) if(A[i] > P[0]) wt(-1), break_continue;
// 
//     res = k = 0;
//     while(k < N){
//       res++;
//       mx = A[k++];
//       cnt = 1;
//       i = 0;
//       while(k < N){
//         if(max(A[k],mx) <= P[i] && cnt < S[i]){
//           mx >?= A[k];
//           k++;
//           cnt++;
//           continue;
//         }
//         if(i+1==M || max(A[k],mx) > P[i+1]) break;
//         i++;
//       }
//     }
//     wt(res);
//   }
// }