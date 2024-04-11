#pragma GCC optimize ("Ofast")
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
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
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
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
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
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int M;
int R[200000];
int C[200000];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(R[cTE1_r3A]);R[cTE1_r3A] += (-1);
        rd(C[cTE1_r3A]);C[cTE1_r3A] += (-1);
      }
    }
    if(M%2){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    sortA_L(M,C,R);
    while(M){
      if(C[M-1] == C[M-2]){
        M-=2;
        continue;
      }
      if(M >= 3 && C[M-2]==C[M-3]){
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
      if(C[M-1] == C[M-2]+1){
        if(R[M-1] == R[M-2]){
          M-=2;
          continue;
        }
        wt_L("NO");
        wt_L('\n');
        goto Q5VJL1cS;
      }
      R[M-1] ^= (C[M-1] - C[M-2] - 1) % 2;
      C[M-1] = C[M-2] + 1;
    }
    wt_L("YES");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1

// --- original code ---
// //no-unlocked
// int N, M, R[2d5], C[2d5];
// {
//   REP(rd_int()){
//     rd(N,M,(R--,C--)(M));
//     if(M%2) wt("NO"), continue;
//     sortA(M,C,R);
//     while(M){
//       if(C[M-1] == C[M-2]) M-=2, continue;
//       if(M >= 3 && C[M-2]==C[M-3]) wt("NO"), break_continue;
//       if(C[M-1] == C[M-2]+1){
//         if(R[M-1] == R[M-2]) M-=2, continue;
//         wt("NO"), break_continue;
//       }
//       R[M-1] ^= (C[M-1] - C[M-2] - 1) % 2;
//       C[M-1] = C[M-2] + 1;
//     }
//     wt("YES");
//   }
// }