#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
int A[200000];
int x[200000];
int s[200000];
int t[200000];
int z[4];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, loop;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      s[i] = t[i] = -1;
    }
    for(loop=(0);loop<(3);loop++){
      for(i=(0);i<(N);i++){
        x[i] = A[i];
      }
      if(loop==1){
        swap(x[0], x[1]);
      }
      if(loop==2){
        swap(x[N-2], x[N-1]);
      }
      for(i=(1);i<(N);i++){
        {
          auto APIVbQlN = (min_L(x[i-1], x[i]));
          x[i-1] -= APIVbQlN;
          x[i] -= APIVbQlN;
        }
      }
      int YREPHmFM;
      int jZyWAPpY;
      if(N==0){
        jZyWAPpY = 0;
      }
      else{
        jZyWAPpY = x[0];
        for(YREPHmFM=(1);YREPHmFM<(N);YREPHmFM++){
          jZyWAPpY = max_L(jZyWAPpY, x[YREPHmFM]);
        }
      }
      if(jZyWAPpY== 0){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    for(i=(0);i<(N);i++){
      x[i] = A[i];
    }
    s[0] = x[0];
    for(i=(1);i<(N);i++){
      {
        auto Q5rsz4fz = (min_L(x[i-1], x[i]));
        x[i-1] -= Q5rsz4fz;
        x[i] -= Q5rsz4fz;
      }
      if(x[i-1]){
        break;
      }
      s[i] = x[i];
    }
    for(i=(0);i<(N);i++){
      x[i] = A[N-1-i];
    }
    t[0] = x[0];
    for(i=(1);i<(N);i++){
      {
        auto aTqQ6rt8 = (min_L(x[i-1], x[i]));
        x[i-1] -= aTqQ6rt8;
        x[i] -= aTqQ6rt8;
      }
      if(x[i-1]){
        break;
      }
      t[i] = x[i];
    }
    for(i=(0);i<(N-3);i++){
      int k;
      if(s[i] < 0 || t[N-4-i] < 0){
        continue;
      }
      {
        auto ytthggxT = (s[i]);
        auto O3U4gd88 = ( A[i+2]);
        auto H31bcJ8S = ( A[i+1]);
        auto dtiCQK_a = ( t[N-4-i]);
        z[0] = ytthggxT;
        z[1] = O3U4gd88;
        z[2] = H31bcJ8S;
        z[3] = dtiCQK_a;
      }
      for(k=(1);k<(4);k++){
        {
          auto qE8LMwYZ = (min_L(z[k-1], z[k]));
          z[k-1] -= qE8LMwYZ;
          z[k] -= qE8LMwYZ;
        }
      }
      int dKuENJNI;
      int HOAyP4rA;
      if(4==0){
        HOAyP4rA = 0;
      }
      else{
        HOAyP4rA = z[0];
        for(dKuENJNI=(1);dKuENJNI<(4);dKuENJNI++){
          HOAyP4rA = max_L(HOAyP4rA, z[dKuENJNI]);
        }
      }
      if(HOAyP4rA== 0){
        wt_L("YES");
        wt_L('\n');
        goto Q5VJL1cS;
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 1]

// --- original code ---
// //no-unlocked
// int N, A[2d5];
// int x[2d5], s[2d5], t[2d5], z[4];
// {
//   REP(rd_int()){
//     rd(N,A(N));
//     rep(i,N) s[i] = t[i] = -1;
// 
//     rep(loop,3){
//       rep(i,N) x[i] = A[i];
//       if(loop==1) swap(x[0], x[1]);
//       if(loop==2) swap(x[N-2], x[N-1]);
//       rep(i,1,N) (x[i-1], x[i]) -= min(x[i-1], x[i]);
//       if(max(x(N)) == 0) wt("YES"), break_continue;
//     }
// 
//     rep(i,N) x[i] = A[i];
//     s[0] = x[0];
//     rep(i,1,N){
//       (x[i-1], x[i]) -= min(x[i-1], x[i]);
//       if(x[i-1]) break;
//       s[i] = x[i];
//     }
// 
//     rep(i,N) x[i] = A[N-1-i];
//     t[0] = x[0];
//     rep(i,1,N){
//       (x[i-1], x[i]) -= min(x[i-1], x[i]);
//       if(x[i-1]) break;
//       t[i] = x[i];
//     }
// 
//     rep(i,N-3){
//       if(s[i] < 0 || t[N-4-i] < 0) continue;
//       (z[0], z[1], z[2], z[3]) = (s[i], A[i+2], A[i+1], t[N-4-i]);
//       rep(k,1,4) (z[k-1], z[k]) -= min(z[k-1], z[k]);
//       if(max(z(4)) == 0) wt("YES"), break_continue;
//     }
// 
//     wt("NO");
//   }
// }