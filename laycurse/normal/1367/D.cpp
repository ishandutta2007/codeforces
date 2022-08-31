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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int M;
int B[50];
char S[52];
char res[52];
int cnt[26];
int decc[50];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int k;
    int z = 25;
    N = rd(S);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(M);cTE1_r3A++){
        rd(B[cTE1_r3A]);
      }
    }
    for(i=(0);i<(26);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[S[i]-'a']++;
    }
    for(;;){
      k = 0;
      for(i=(0);i<(M);i++){
        if(B[i]==0){
          k++;
        }
      }
      if(k==0){
        break;
      }
      while(cnt[z] < k){
        z--;
      }
      for(i=(0);i<(M);i++){
        if(B[i]==0){
          res[i] = 'a' + z;
        }
      }
      z--;
      for(i=(0);i<(M);i++){
        decc[i] = 0;
      }
      for(i=(0);i<(M);i++){
        if(B[i]==0){
          int j;
          decc[i]++;
          for(j=(0);j<(M);j++){
            decc[j] += abs(i-j);
          }
        }
      }
      for(i=(0);i<(M);i++){
        B[i] -= decc[i];
      }
    }
    res[M] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, B[50];
// char S[52];
// char res[52];
// int cnt[26], decc[50];
// {
//   REP(rd_int()){
//     int i, k, z = 25;
//     rd(S@N,M,B(M));
//     
//     rep(i,26) cnt[i] = 0;
//     rep(i,N) cnt[S[i]-'a']++;
// 
//     for(;;){
//       k = 0;
//       rep(i,M) if(B[i]==0) k++;
//       if(k==0) break;
//       while(cnt[z] < k) z--;
//       rep(i,M) if(B[i]==0) res[i] = 'a' + z;
//       z--;
// 
//       rep(i,M) decc[i] = 0;
//       rep(i,M) if(B[i]==0){
//         decc[i]++;
//         rep(j,M) decc[j] += abs(i-j);
//       }
//       rep(i,M) B[i] -= decc[i];
//     }
// 
//     res[M] = '\0';
//     wt(res);
//   }
// }