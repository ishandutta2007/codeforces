#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
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
template<class T> int runLength(int N, T *arr, void *val_s = NULL, void *len_s = NULL){
  int i;
  int rN;
  T *val = (T*) val_s;
  int *len = (int*) len_s;
  if(N==0){
    return 0;
  }
  if(val==NULL || len==NULL){
    void *mem = wmem;
    if(val==NULL){
      walloc1d(&val, N, &mem);
    }
    if(len==NULL){
      walloc1d(&len, N, &mem);
    }
  }
  rN = 1;
  val[0] = arr[0];
  len[0] = 1;
  for(i=(1);i<(N);i++){
    if(val[rN-1] == arr[i]){
      len[rN-1]++;
    }
    else{
      val[rN] = arr[i];
      len[rN] = 1;
      rN++;
    }
  }
  return rN;
}
int N;
int A[400000];
int sz;
int num[400000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int i;
  int G;
  int S;
  int B;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    sz = runLength(N, A, NULL, num);
    i = G = S = B = 0;
    G = num[i++];
    while(i < sz && S <= G){
      S += num[i++];
    }
    while(i < sz && G + S + B + num[i] <= N/2){
      B += num[i++];
    }
    if(!(G < S && G < B && G+S+B <= N/2)){
      G = S = B = 0;
    }
    wt_L(G);
    wt_L(' ');
    wt_L(S);
    wt_L(' ');
    wt_L(B);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200227-1

// --- original code ---
// //no-unlocked
// int N, A[4d5];
// int sz, num[4d5];
// {
//   int i, G, S, B;
//   REP(rd_int()){
//     rd(N,A(N));
//     sz = runLength(N, A, NULL, num);
//     i = G = S = B = 0;
//     G = num[i++];
//     while(i < sz && S <= G) S += num[i++];
//     while(i < sz && G + S + B + num[i] <= N/2) B += num[i++];
//     if(!(G < S && G < B && G+S+B <= N/2)) G = S = B = 0;
//     wt(G,S,B);
//   }
// }