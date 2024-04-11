#pragma GCC optimize ("Ofast")
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
int N;
char S[102];
char nx[102];
int main(){
  int i, k;
  int sz;
  int res = 0;
  rd(N);
  rd(S);
  for(i=(0);i<(N);i++){
    S[i] -= 'a';
  }
  for(k=(26)-1;k>=(0);k--){
    sz = 0;
    for(i=(0);i<(N);i++){
      if(S[i] == k && sz && nx[sz-1] == k-1){
        res++;
        continue;
      }
      while(S[i] == k-1 && sz && nx[sz-1] == k){
        res++;
        sz--;
      }
      nx[sz++] = S[i];
    }
    N = sz;
    for(i=(0);i<(N);i++){
      S[i] = nx[i];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N;
// char S[102], nx[102];
// {
//   int sz, res = 0;
//   rd(N,S);
//   rep(i,N) S[i] -= 'a';
//   rrep(k,26){
//     sz = 0;
//     rep(i,N){
//       if(S[i] == k && sz && nx[sz-1] == k-1) res++, continue;
//       while(S[i] == k-1 && sz && nx[sz-1] == k) res++, sz--;
//       nx[sz++] = S[i];
//     }
//     N = sz;
//     rep(i,N) S[i] = nx[i];
//   }
//   wt(res);
// }