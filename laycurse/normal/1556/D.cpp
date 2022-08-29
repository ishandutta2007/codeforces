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
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
int N;
int K;
int A[100000];
int aa[3];
int bb[3];
int query(int t, int i, int j){
  if(t==0){
    wt_L("and");
    wt_L(' ');
    wt_L(i+1);
    wt_L(' ');
    wt_L(j+1);
    wt_L('\n');
  }
  if(t==1){
    wt_L("or");
    wt_L(' ');
    wt_L(i+1);
    wt_L(' ');
    wt_L(j+1);
    wt_L('\n');
  }
  return rd_int();
}
int main(){
  int bt;
  wmem = memarr;
  int i;
  int j;
  int x;
  int y;
  int z;
  rd(N);
  rd(K);K += (-1);
  aa[0] = query(0,0,1);
  aa[1] = query(0,0,2);
  aa[2] = query(0,1,2);
  bb[0] = query(1,0,1);
  bb[1] = query(1,0,2);
  bb[2] = query(1,1,2);
  for(bt=(0);bt<(30);bt++){
    for(x=(0);x<(2);x++){
      for(y=(0);y<(2);y++){
        for(z=(0);z<(2);z++){
          if( (x&y) != ((aa[0]>>bt)&1) ){
            continue;
          }
          if( (x&z) != ((aa[1]>>bt)&1) ){
            continue;
          }
          if( (y&z) != ((aa[2]>>bt)&1) ){
            continue;
          }
          if( (x|y) != ((bb[0]>>bt)&1) ){
            continue;
          }
          if( (x|z) != ((bb[1]>>bt)&1) ){
            continue;
          }
          if( (y|z) != ((bb[2]>>bt)&1) ){
            continue;
          }
          A[0] |= (x<<bt);
          A[1] |= (y<<bt);
          A[2] |= (z<<bt);
        }
      }
    }
  }
  for(i=(3);i<(N);i++){
    aa[0] = query(0,0,i);
    bb[0] = query(1,0,i);
    for(bt=(0);bt<(30);bt++){
      z = ((A[0] >> bt) & 1);
      for(x=(0);x<(2);x++){
        if( (z&x) != ((aa[0]>>bt)&1) ){
          continue;
        }
        if( (z|x) != ((bb[0]>>bt)&1) ){
          continue;
        }
        A[i] |= (x<<bt);
      }
    }
  }
  sortA_L(N,A);
  wt_L("finish");
  wt_L(' ');
  wt_L(A[K]);
  wt_L('\n');
  return 0;
}
// cLay version 20210819-1 [beta]

// --- original code ---
// //interactive
// int N, K, A[1d5];
// int aa[3], bb[3];
// 
// int query(int t, int i, int j){
//   if(t==0) wt("and", i+1, j+1);
//   if(t==1) wt("or", i+1, j+1);
//   return rd_int();
// }
// 
// {
//   int i, j, x, y, z;
//   rd(N,K--);
//   aa[0] = query(0,0,1);
//   aa[1] = query(0,0,2);
//   aa[2] = query(0,1,2);
//   bb[0] = query(1,0,1);
//   bb[1] = query(1,0,2);
//   bb[2] = query(1,1,2);
//   rep(bt,30){
//     rep(x,2) rep(y,2) rep(z,2){
//       if( (x&y) != ((aa[0]>>bt)&1) ) continue;
//       if( (x&z) != ((aa[1]>>bt)&1) ) continue;
//       if( (y&z) != ((aa[2]>>bt)&1) ) continue;
//       if( (x|y) != ((bb[0]>>bt)&1) ) continue;
//       if( (x|z) != ((bb[1]>>bt)&1) ) continue;
//       if( (y|z) != ((bb[2]>>bt)&1) ) continue;
//       A[0] |= (x<<bt);
//       A[1] |= (y<<bt);
//       A[2] |= (z<<bt);
//     }
//   }
//   rep(i,3,N){
//     aa[0] = query(0,0,i);
//     bb[0] = query(1,0,i);
//     rep(bt,30){
//       z = ((A[0] >> bt) & 1);
//       rep(x,2){
//         if( (z&x) != ((aa[0]>>bt)&1) ) continue;
//         if( (z|x) != ((bb[0]>>bt)&1) ) continue;
//         A[i] |= (x<<bt);
//       }
//     }
//   }
//   sortA(N,A);
//   wt("finish", A[K]);
// }