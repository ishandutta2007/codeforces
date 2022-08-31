#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> void Manachar(int N, T A[], int res[]){
  int i;
  int j;
  int k;
  int c = 0;
  for(i=(0);i<(N);i++){
    k = 2*c - i;
    if(i+res[k] < c+res[c]){
      res[i] = res[k];
    }
    else{
      j = c + res[c] - i;
      while(i-j >= 0 && i+j < N && A[i-j]==A[i+j]){
        j++;
      }
      res[i] = j;
      c = i;
    }
  }
  for(i=(0);i<(N);i++){
    res[i] = 2*res[i] - 1;
  }
}
int N;
char S[1000000+2];
char t[2000000+1];
int len[2000000+1];
int jump[1000000];
int main(){
  int FmcKpFmN;
  int i;
  int k;
  int c;
  int opt;
  int ind;
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    N = rd(S);
    for(i=(0);i<(N);i++){
      t[2*i+1] = S[i];
    }
    for(i=(0);i<(N+1);i++){
      t[2*i] = '@';
    }
    Manachar(2*N+1, t, len);
    for(i=(0);i<(2*N+1);i++){
      len[i] /= 2;
    }
    for(i=(0);i<(N);i++){
      jump[i] = 0;
    }
    for(i=(2);i<(2*N);i+=(2)){
      k = ((i-1)/2) - len[i] / 2 + 1;
      c = N - 2*k;
      if(len[i] <= c){
        chmax(jump[k], len[i]);
      }
      k = (i/2) + len[i] / 2 - 1;
      c = N - 2*(N - 1 - k);
      if(len[i] <= c){
        chmax(jump[k], len[i]);
      }
    }
    for(i=(1);i<(2*N);i+=(2)){
      k = (i/2) - len[i] / 2;
      c = N - 2*k;
      if(len[i] <= c){
        chmax(jump[k], len[i]);
      }
      k = (i/2) + len[i] / 2;
      c = N - 2*(N - 1 - k);
      if(len[i] <= c){
        chmax(jump[k], len[i]);
      }
    }
    opt = 0;
    for(i=(0);i<((N+1)/2);i++){
      if(i && S[i-1] != S[N-i]){
        break;
      }
      k = 2*i;
      if(2*i < N){
        k +=max_L(jump[i], jump[N-1-i]);
      }
      if(opt < k){
        {
          auto BUotOFBp = (k);
          auto Q5rsz4fz = ( i);
          opt = BUotOFBp;
          ind = Q5rsz4fz;
        }
      }
    }
    if(opt==N){
      wt_L(S);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(ind);i++){
      wt_L(S[i]);
    }
    if(jump[ind] > jump[N-1-ind]){
      for(i=(0);i<(jump[ind]);i++){
        wt_L(S[ind+i]);
      }
    }
    else{
      k = jump[N-1-ind];
      for(i=(0);i<(k);i++){
        wt_L(S[N-ind-k+i]);
      }
    }
    for(i=(0);i<(ind);i++){
      wt_L(S[N-ind+i]);
    }
    wt_L("");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200317-1

// --- original code ---
// //no-unlocked
// 
// template<class T>
// void Manachar(int N, T A[], int res[]){
//   int i, j, k, c = 0;
//   rep(i,N){
//     k = 2*c - i;
//     if(i+res[k] < c+res[c]){
//       res[i] = res[k];
//     } else {
//       j = c + res[c] - i;
//       while(i-j >= 0 && i+j < N && A[i-j]==A[i+j]) j++;
//       res[i] = j;
//       c = i;
//     }
//   }
//   rep(i,N) res[i] = 2*res[i] - 1;
// }
// 
// int N;
// char S[1d6+2], t[2d6+1];
// int len[2d6+1];
// int jump[1d6];
// 
// {
//   int i, k, c, opt, ind;
//   REP(rd_int()){
//     rd(S@N);
//     rep(i,N) t[2i+1] = S[i];
//     rep(i,N+1) t[2i] = '@';
//     Manachar(2N+1, t, len);
//     rep(i,2N+1) len[i] /= 2;
//     rep(i,N) jump[i] = 0;
//     rep(i,2,2N,2){
//       k = ((i-1)/2) - len[i] / 2 + 1;
//       c = N - 2k;
//       if(len[i] <= c) jump[k] >?= len[i];
// 
//       k = (i/2) + len[i] / 2 - 1;
//       c = N - 2(N - 1 - k);
//       if(len[i] <= c) jump[k] >?= len[i];
//     }
//     rep(i,1,2N,2){
//       k = (i/2) - len[i] / 2;
//       c = N - 2k;
//       if(len[i] <= c) jump[k] >?= len[i];
// 
//       k = (i/2) + len[i] / 2;
//       c = N - 2(N - 1 - k);
//       if(len[i] <= c) jump[k] >?= len[i];
//     }
// 
//     opt = 0;
//     rep(i,(N+1)/2){
//       if(i && S[i-1] != S[N-i]) break;
//       k = 2i;
//       if(2i < N) k += max(jump[i], jump[N-1-i]);
//       if(opt < k) (opt, ind) = (k, i);
//     }
//     if(opt==N) wt(S), continue;
//     rep(i,ind) wtN(S[i]);
//     if(jump[ind] > jump[N-1-ind]){
//       rep(i,jump[ind]) wtN(S[ind+i]);
//     } else {
//       k = jump[N-1-ind];
//       rep(i,k) wtN(S[N-ind-k+i]);
//     }
//     rep(i,ind) wtN(S[N-ind+i]);
//     wt("");
//   }
// }