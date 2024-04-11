#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
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
inline void rd(long long &x){
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int N;
long long B[200000+2];
long long A[200000];
long long sm;
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int z;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N+2);cTE1_r3A++){
        rd(B[cTE1_r3A]);
      }
    }
    sortA_L(N+2, B);
    int xr20shxY;
    cLtraits_try_make_signed<remove_reference<decltype((*((long long*)NULL)))>::type>::type WYIGIcGE;
    if(N+2==0){
      WYIGIcGE = 0;
    }
    else{
      WYIGIcGE = B[0];
      for(xr20shxY=(1);xr20shxY<(N+2);xr20shxY++){
        WYIGIcGE += B[xr20shxY];
      }
    }
    sm =WYIGIcGE;
    for(i=(0);i<(N+2);i++){
      if(i==N+1){
        j =N;
      }
      else{
        j =N+1;
      }
      if(sm - B[i] - B[j] == B[j]){
        int k;
        z = 0;
        for(k=(0);k<(N+2);k++){
          if(k!=i && k!=j){
            A[z++] = B[k];
          }
        }
        {
          int V9aVTaxx;
          if(N==0){
            wt_L('\n');
          }
          else{
            for(V9aVTaxx=(0);V9aVTaxx<(N-1);V9aVTaxx++){
              wt_L(A[V9aVTaxx]);
              wt_L(' ');
            }
            wt_L(A[V9aVTaxx]);
            wt_L('\n');
          }
        }
        goto Q5VJL1cS;
      }
    }
    wt_L(-1);
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// int N; ll B[2d5+2], A[2d5], sm;
// {
//   REP(rd_int()){
//     int i, j, z;
//     rd(N,B(N+2));
//     sortA(N+2, B);
//     sm = sum(B(N+2));
//     rep(i,N+2){
//       j = if[i==N+1, N, N+1];
//       if(sm - B[i] - B[j] == B[j]){
//         z = 0;
//         rep(k,N+2) if(k!=i && k!=j) A[z++] = B[k];
//         wt(A(N)), break_continue;
//       }
//     }
//     wt(-1);
//   }
// }