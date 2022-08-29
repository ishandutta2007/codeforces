#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc1d(T **arr, int x1, int x2, void **mem = &wmem){
  walloc1d(arr, x2-x1, mem);
  (*arr) -= x1;
}
inline int my_getchar(){
  return getchar();
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
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
    k = my_getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
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
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
template<class T> void arrRot(int k, int N, T A[], T B[] = NULL, void *mem = wmem){
  int i;
  int fg = 0;
  (k = moddw_L(k,N));
  if(B==NULL){
    walloc1d(&B, N, &mem);
    fg = 1;
  }
  for(i=(k);i<(N);i++){
    B[i-k] = A[i];
  }
  for(i=(0);i<(k);i++){
    B[N-k+i] = A[i];
  }
  if(fg){
    for(i=(0);i<(N);i++){
      A[i] = B[i];
    }
  }
}
int N;
int P[10000+2];
int Q[10000+2];
int pp[10000+2];
int qq[10000+2];
int sz;
int arr[10000+2];
int vis[10000+2];
int query(int k){
  wt_L("?");
  wt_L(' ');
  wt_L(k+1);
  wt_L('\n');
  return rd_int() - 1;
}
void ans(){
  wt_L("!");
  wt_L(' ');
  {
    int Lj4PdHRW;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(Lj4PdHRW=(0);Lj4PdHRW<(N-1);Lj4PdHRW++){
        wt_L(P[Lj4PdHRW]+1);
        wt_L(' ');
      }
      wt_L(P[Lj4PdHRW]+1);
      wt_L('\n');
    }
  }
}
int main(){
  int e98WHCEY;
  wmem = memarr;
  int cTE1_r3A = rd_int();
  for(e98WHCEY=(0);e98WHCEY<(cTE1_r3A);e98WHCEY++){
    int i;
    int j;
    int k;
    rd(N);
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(N);i++){
      if(!vis[i]){
        sz = 0;
        for(;;){
          k = query(i);
          if(vis[k]){
            break;
          }
          vis[k] = 1;
          arr[sz++] = k;
        }
        for(j=(0);j<(sz);j++){
          if(arr[j] == i){
            break;
          }
        }
        arrRot(j, sz, arr);
        arr[sz] = i;
        for(j=(0);j<(sz);j++){
          P[arr[j]] = arr[j+1];
        }
      }
    }
    ans();
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20211231-1

// --- original code ---
// //interactive
// int N, P[1d4+2], Q[], pp[], qq[];
// int sz, arr[], vis[];
// 
// int query(int k){
//   wt("?",k+1);
//   return rd_int() - 1;
// }
// 
// void ans(){
//   wt("!",P(N)+1);
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k;
//     rd(N);
//     rep(i,N) vis[i] = 0;
//     rep(i,N) if(!vis[i]){
//       sz = 0;
//       for(;;){
//         k = query(i);
//         if(vis[k]) break;
//         vis[k] = 1;
//         arr[sz++] = k;
//       }
//       rep(j,sz) if(arr[j] == i) break;
//       arrRot(j, sz, arr);
//       arr[sz] = i;
//       rep(j,sz) P[arr[j]] = arr[j+1];
//     }
//     ans();
//   }
// }