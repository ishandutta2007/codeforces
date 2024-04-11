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
int A[55];
int tmp[55];
int ress;
int reslen[55];
int res[55][55];
int cnt;
int main(){
  int i;
  int x = 0;
  int y = 0;
  int p;
  int t;
  int aa;
  int bb;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    if(N%2==0){
      t = i / 2;
      if(i%2==0){
        t += N/2;
      }
    }
    else{
      t = i / 2;
      if(i%2==1){
        t += N/2+1;
      }
    }
    for(j=(0);j<(N);j++){
      if(A[j] == t){
        break;
      }
    }
    if(x){
      res[ress][reslen[ress]++] = x;
    }
    if(j-x){
      res[ress][reslen[ress]++] = j-x;
    }
    if(N-j-y){
      res[ress][reslen[ress]++] = N-j-y;
    }
    if(y){
      res[ress][reslen[ress]++] = y;
    }
    aa = 0;
    bb = N;
    for(j=(0);j<(reslen[ress]);j++){
      int k;
      bb -= res[ress][j];
      for(k=(0);k<(res[ress][j]);k++){
        tmp[bb+k] = A[aa+k];
      }
      aa += res[ress][j];
    }
    for(j=(0);j<(N);j++){
      A[j] = tmp[j];
    }
    ress++;
    if(i%2==0){
      x++;
    }
    else{
      y++;
    }
  }
  for(i=(0);i<(N);i++){
    if(reslen[i] > 1){
      cnt++;
    }
  }
  wt_L(cnt);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    if(reslen[i] > 1){
      wt_L(reslen[i]);
      wt_L(' ');
      {
        int YREPHmFM;
        if(reslen[i]==0){
          wt_L('\n');
        }
        else{
          for(YREPHmFM=(0);YREPHmFM<(reslen[i]-1);YREPHmFM++){
            wt_L(res[i][YREPHmFM]);
            wt_L(' ');
          }
          wt_L(res[i][YREPHmFM]);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay varsion 20201003-1

// --- original code ---
// //no-unlocked
// int N, A[55], tmp[55];
// int ress, reslen[55], res[55][55], cnt;
// {
//   int x = 0, y = 0, p, t, aa, bb;
//   rd(N,(A--)(N));
//   // wt(A(N));
// 
//   rep(i,N){
//     if(N%2==0){
//       t = i / 2;
//       if(i%2==0) t += N/2;
//     } else {
//       t = i / 2;
//       if(i%2==1) t += N/2+1;
//     }
// 
//     rep(j,N) if(A[j] == t) break;
//     if(x) res[ress][reslen[ress]++] = x;
//     if(j-x) res[ress][reslen[ress]++] = j-x;
//     if(N-j-y) res[ress][reslen[ress]++] = N-j-y;
//     if(y) res[ress][reslen[ress]++] = y;
// 
//     aa = 0; bb = N;
//     rep(j,reslen[ress]){
//       bb -= res[ress][j];
//       rep(k,res[ress][j]) tmp[bb+k] = A[aa+k];
//       aa += res[ress][j];
//     }
//     rep(j,N) A[j] = tmp[j];
//     ress++;
// 
//     if[i%2==0, x, y]++;
// 
//     // wt(t,":",A(N));
//   }
// 
//   // wt("---");
//   rep(i,N) if(reslen[i] > 1) cnt++;
//   wt(cnt);
//   rep(i,ress) if(reslen[i] > 1) wt(reslen[i], res[i](reslen[i]));
// 
//   // wt("---");
//   //wt(A(N));
// }