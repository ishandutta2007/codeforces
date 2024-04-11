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
int N;
int K;
char A[100000+2];
int hist[26];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int r = 0;
    int a;
    rd(N);
    rd(K);
    rd(A);
    if(N%K){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(26);i++){
      hist[i] = 0;
    }
    for(i=(0);i<(N);i++){
      hist[A[i]-'a']++;
    }
    for(i=(0);i<(26);i++){
      hist[i] =(moddw_L((-hist[i]),K));
    }
    int KrdatlYV;
    int ao_dF3pO;
    if(26==0){
      ao_dF3pO = 0;
    }
    else{
      ao_dF3pO = hist[0];
      for(KrdatlYV=(1);KrdatlYV<(26);KrdatlYV++){
        ao_dF3pO += hist[KrdatlYV];
      }
    }
    if(ao_dF3pO==0){
      wt_L(A);
      wt_L('\n');
      continue;
    }
    for(i=(N)-1;i>=(0);i--){
      j = A[i] - 'a';
      hist[j] = (hist[j] + 1) % K;
      r++;
      int APIVbQlN;
      int YREPHmFM;
      if(26==0){
        YREPHmFM = 0;
      }
      else{
        YREPHmFM = hist[0];
        for(APIVbQlN=(1);APIVbQlN<(26);APIVbQlN++){
          YREPHmFM += hist[APIVbQlN];
        }
      }
      if(YREPHmFM> r){
        continue;
      }
      int ZIeRIny5;
      int iMWUTgY_;
      if(26==0){
        iMWUTgY_ = 0;
      }
      else{
        iMWUTgY_ = hist[0];
        for(ZIeRIny5=(1);ZIeRIny5<(26);ZIeRIny5++){
          iMWUTgY_ += hist[ZIeRIny5];
        }
      }
      a = r -iMWUTgY_;
      if(a && j+1 < 26 && hist[j+1] == 0){
        hist[j+1] += K;
        a -= K;
      }
      if(a && j+1 < 26){
        hist[0] += a;
      }
      for(k=(j+1);k<(26);k++){
        if(hist[k]){
          int Q5rsz4fz;
          int GgkpftXM;
          if(26==0){
            GgkpftXM = 0;
          }
          else{
            GgkpftXM = hist[0];
            for(Q5rsz4fz=(1);Q5rsz4fz<(26);Q5rsz4fz++){
              GgkpftXM += hist[Q5rsz4fz];
            }
          }
          hist[0] += r -GgkpftXM;
          hist[k]--;
          A[i++] = 'a' + k;
          for(k=(0);k<(26);k++){
            int aTqQ6rt8;
            for(aTqQ6rt8=(0);aTqQ6rt8<(hist[k]);aTqQ6rt8++){
              A[i++] = 'a' + k;
            }
          }
          wt_L(A);
          wt_L('\n');
          goto Q5VJL1cS;
        }
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int N, K;
// char A[1d5+2];
// int hist[26];
// {
//   REP(rd_int()){
//     int i, j, k, r = 0, a;
//     rd(N,K,A);
//     if(N%K) wt(-1), continue;
//     rep(i,26) hist[i] = 0;
//     rep(i,N) hist[A[i]-'a']++;
//     rep(i,26) hist[i] = (-hist[i])%%K;
//     if(sum(hist(26))==0) wt(A), continue;
//     rrep(i,N){
//       j = A[i] - 'a';
//       hist[j] = (hist[j] + 1) % K;
//       r++;
//       if(sum(hist(26)) > r) continue;
// 
//       a = r - sum(hist(26));
//       if(a && j+1 < 26 && hist[j+1] == 0) hist[j+1] += K, a -= K;
//       if(a && j+1 < 26) hist[0] += a;
//       rep(k,j+1,26) if(hist[k]){
//         hist[0] += r - sum(hist(26));
//         hist[k]--;
//         A[i++] = 'a' + k;
//         rep(k,26) rep(hist[k]) A[i++] = 'a' + k;
//         wt(A);
//         break_break_continue;
//       }
//     }
//   }
// }