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
int N;
int M;
int A;
int B;
char res[50][51];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x;
    int y;
    int rem;
    rd(N);
    rd(M);
    rd(A);
    rd(B);
    if(N*A != M*B){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(M);j++){
        res[i][j] = '0';
      }
    }
    for(i=(0);i<(N);i++){
      res[i][M] = '\0';
    }
    rem = N * A;
    for(i=(0);i<(N);i++){
      if(rem > 0){
        {
          auto tU__gIr_ = (i);
          auto a2conNHc = ( 0);
          x = tU__gIr_;
          y = a2conNHc;
        }
        for(;;){
          res[x][y]++;
          rem--;
          x = (x+1) % N;
          y = (y+1) % M;
          if(x==i && y==0){
            break;
          }
        }
      }
    }
    {
      int APIVbQlN;
      for(APIVbQlN=(0);APIVbQlN<(N);APIVbQlN++){
        wt_L(res[APIVbQlN]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, M, A, B;
// char res[50][51];
// {
//   REP(rd_int()){
//     int i, x, y, rem;
//     rd(N,M,A,B);
//     if(N*A != M*B) wt("NO"), continue;
//     wt("YES");
// 
//     rep(i,N) rep(j,M) res[i][j] = '0';
//     rep(i,N) res[i][M] = '\0';
//     
//     rem = N * A;
//     rep(i,N) if(rem > 0){
//       (x, y) = (i, 0);
//       for(;;){
//         res[x][y]++;
//         rem--;
//         x = (x+1) % N;
//         y = (y+1) % M;
//         if(x==i && y==0) break;
//       }
//     }
// 
//     wtLn(res(N));
//   }
// }