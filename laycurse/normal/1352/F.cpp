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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N[3];
int ress;
char res[1000];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int k;
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(3);cTE1_r3A++){
        rd(N[cTE1_r3A]);
      }
    }
    ress = 0;
    if(N[1]==0){
      if(N[0]){
        int xr20shxY;
        for(xr20shxY=(0);xr20shxY<(N[0]+1);xr20shxY++){
          res[ress++] = '0';
        }
      }
      else{
        int KrdatlYV;
        for(KrdatlYV=(0);KrdatlYV<(N[2]+1);KrdatlYV++){
          res[ress++] = '1';
        }
      }
    }
    else{
      int APIVbQlN, a2conNHc, jbtyPBGc;
      for(a2conNHc=(0);a2conNHc<(N[0]+1);a2conNHc++){
        res[ress++] = '0';
      }
      for(APIVbQlN=(0);APIVbQlN<(N[2]+1);APIVbQlN++){
        res[ress++] = '1';
      }
      k = 1;
      for(jbtyPBGc=(0);jbtyPBGc<(N[1]-1);jbtyPBGc++){
        k ^= 1;
        res[ress++] = k + '0';
      }
    }
    res[ress] = '\0';
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N[3];
// int ress;
// char res[1000];
// {
//   REP(rd_int()){
//     int k;
//     rd(N(3));
//     ress = 0;
//     if(N[1]==0){
//       if(N[0]){
//         rep(N[0]+1) res[ress++] = '0';
//       } else {
//         rep(N[2]+1) res[ress++] = '1';
//       }
//     } else {
//       rep(N[0]+1) res[ress++] = '0';
//       rep(N[2]+1) res[ress++] = '1';
//       k = 1;
//       rep(N[1]-1) k ^= 1, res[ress++] = k + '0';
//     }
//     res[ress] = '\0';
//     wt(res);
//   }
// }