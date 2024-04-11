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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int w[20][20];
int mn[20];
int arr[20];
int cur[20];
long long calc(void){
  int i;
  long long res = 0;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(w[i][j]){
        res += w[i][j] * (cur[i] - cur[j]);
      }
    }
  }
  return res;
}
int main(){
  int WYIGIcGE, cTE1_r3A;
  int i;
  int j;
  int k;
  int x;
  int kk;
  long long res = 4611686016279904256LL;
  long long tmp;
  long long g;
  rd(N);
  int RZTsC2BF = rd_int();
  for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    rd(k);
    w[i][j] = k;
  }
  for(WYIGIcGE=(0);WYIGIcGE<(N);WYIGIcGE++){
    for(i=(0);i<(N);i++){
      for(j=(0);j<(N);j++){
        if(w[i][j]){
          chmax(mn[i], mn[j] + 1);
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    cur[i] = mn[i];
  }
  tmp = calc();
  if(res > tmp){
    res = tmp;
    for(i=(0);i<(N);i++){
      arr[i] = cur[i];
    }
  }
  for(;;){
    int szDqbNYU;
    g = 4611686016279904256LL;
    for(k=(0);k<(N);k++){
      int BUotOFBp;
      for(i=(0);i<(N);i++){
        cur[i] = arr[i];
      }
      cur[k]++;
      for(BUotOFBp=(0);BUotOFBp<(N);BUotOFBp++){
        for(i=(0);i<(N);i++){
          for(j=(0);j<(N);j++){
            if(w[i][j]){
              chmax(cur[i], cur[j] + 1);
            }
          }
        }
      }
      tmp = calc();
      if(g > tmp){
        g = tmp;
        kk = k;
      }
    }
    if(g >= res){
      break;
    }
    k = kk;
    for(i=(0);i<(N);i++){
      cur[i] = arr[i];
    }
    cur[k]++;
    for(szDqbNYU=(0);szDqbNYU<(N);szDqbNYU++){
      for(i=(0);i<(N);i++){
        for(j=(0);j<(N);j++){
          if(w[i][j]){
            chmax(cur[i], cur[j] + 1);
          }
        }
      }
    }
    res = calc();
    for(i=(0);i<(N);i++){
      arr[i] = cur[i];
    }
  }
  {
    int dKuENJNI;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(dKuENJNI=(0);dKuENJNI<(N-1);dKuENJNI++){
        wt_L(arr[dKuENJNI]);
        wt_L(' ');
      }
      wt_L(arr[dKuENJNI]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20201102-1

// --- original code ---
// //no-unlocked
// int N, w[20][20];
// int mn[20], arr[20], cur[20];
// ll calc(void){
//   ll res = 0;
//   rep(i,N) rep(j,N) if(w[i][j]) res += w[i][j] * (cur[i] - cur[j]);
//   return res;
// }
// {
//   int i, j, k, x, kk;
//   ll res = ll_inf, tmp, g;
//   rd(N);
//   REP(rd_int()){
//     rd(i--, j--, k);
//     w[i][j] = k;
//   }
// 
//   rep(N) rep(i,N) rep(j,N) if(w[i][j]) mn[i] >?= mn[j] + 1;
//   rep(i,N) cur[i] = mn[i];
//   tmp = calc();
//   if(res > tmp){
//     res = tmp;
//     rep(i,N) arr[i] = cur[i];
//   }
//   for(;;){
//     g = ll_inf;
//     rep(k,N){
//       rep(i,N) cur[i] = arr[i];
//       cur[k]++;
//       rep(N) rep(i,N) rep(j,N) if(w[i][j]) cur[i] >?= cur[j] + 1;
//       tmp = calc();
//       if(g > tmp) g = tmp, kk = k;
//     }
//     if(g >= res) break;
//     k = kk;
//     rep(i,N) cur[i] = arr[i];
//     cur[k]++;
//     rep(N) rep(i,N) rep(j,N) if(w[i][j]) cur[i] >?= cur[j] + 1;
//     res = calc();
//     rep(i,N) arr[i] = cur[i];
//   }
//   wt(arr(N));
// }