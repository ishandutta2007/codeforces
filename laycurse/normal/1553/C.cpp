#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
template<class T, class S, class U> inline void DigitF_L(T n, int sz, S res[], U b){
  int i;
  for(i=(0);i<(sz);i++){
    res[i] = n % b;
    n /= b;
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
char S[12];
int arr[10];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int mask;
    int res = 10;
    int c[2];
    int r[2];
    rd(S);
    for(mask=(0);mask<(1<<10);mask++){
      int i;
      DigitF_L(mask,10,arr,2);
      for(i=(0);i<(10);i++){
        if(S[i] != '?' && S[i] != arr[i]+'0'){
          goto cTE1_r3A;
        }
      }
      for(i=(0);i<(2);i++){
        c[i] = 0;
        r[i] = 5;
      }
      for(i=(0);i<(10);i++){
        if(c[0] > c[1] + r[1]){
          break;
        }
        if(c[1] > c[0] + r[0]){
          break;
        }
        c[i%2] += arr[i];
        r[i%2]--;
      }
      chmin(res, i);
      cTE1_r3A:;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210717-1 [beta]

// --- original code ---
// //no-unlocked
// char S[12];
// int arr[10];
// {
//   REP(rd_int()){
//     int res = 10, c[2], r[2];
//     rd(S);
//     rep(mask,1<<10){
//       DigitF(mask,10,arr,2);
//       rep(i,10) if(S[i] != '?' && S[i] != arr[i]+'0') break_continue;
//       rep(i,2) c[i] = 0, r[i] = 5;
//       rep(i,10){
//         if(c[0] > c[1] + r[1]) break;
//         if(c[1] > c[0] + r[0]) break;
//         c[i%2] += arr[i];
//         r[i%2]--;
//       }
//       res <?= i;
//     }
//     wt(res);
//   }
// }