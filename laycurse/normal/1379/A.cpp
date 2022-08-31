#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
inline void rd(string &x){
  char *buf = (char *)wmem;
  rd(buf);
  x = buf;
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
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
int N;
string S;
string res;
string a = "abacaba";
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int cnt;
    rd(N);
    rd(S);
    res = S;
    for(k=(6);k<(N);k++){
      for(j=(0);j<(7);j++){
        if(S[k-6+j] != '?' && S[k-6+j] != a[j]){
          goto cTE1_r3A;
        }
      }
      res = S;
      for(j=(0);j<(7);j++){
        res[k-6+j] = a[j];
      }
      for(j=(0);j<(N);j++){
        if(res[j]=='?'){
          res[j] = 'z';
        }
      }
      cnt = 0;
      for(i=(6);i<(N);i++){
        if(res.substr(i-6,7) == a){
          cnt++;
        }
      }
      if(cnt==1){
        wt_L("Yes");
        wt_L('\n');
        wt_L(res);
        wt_L('\n');
        goto Q5VJL1cS;
      }
      cTE1_r3A:;
    }
    wt_L("No");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// string S, res;
// string a = "abacaba";
// {
//   REP(rd_int()){
//     int i, j, k, cnt;
//     rd(N,S);
//     res = S;
//     rep(k,6,N){
//       rep(j,7) if(S[k-6+j] != '?' && S[k-6+j] != a[j]) break_continue;
//       res = S;
//       rep(j,7) res[k-6+j] = a[j];
//       rep(j,N) if(res[j]=='?') res[j] = 'z';
// 
//       cnt = 0;
//       rep(i,6,N) if(res.substr(i-6,7) == a) cnt++;
//       if(cnt==1) wtLn("Yes", res), break_continue;
//     }
//     wt("No");
//   }
// }