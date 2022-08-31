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
int A[200000];
int mx;
int cnt[200];
int pcnt[200];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, k;
    int a;
    int b;
    int tmp;
    int res;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(A[cTE1_r3A]);A[cTE1_r3A] += (-1);
      }
    }
    {
      int xr20shxY;
      int WYIGIcGE;
      if(N==0){
        WYIGIcGE = 0;
      }
      else{
        WYIGIcGE = A[0];
        for(xr20shxY=(1);xr20shxY<(N);xr20shxY++){
          WYIGIcGE = max_L(WYIGIcGE, A[xr20shxY]);
        }
      }
      mx =WYIGIcGE+ 1;
    }
    for(k=(0);k<(mx);k++){
      cnt[k] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[A[i]]++;
    }
    {
      int V9aVTaxx;
      int APIVbQlN;
      if(mx==0){
        APIVbQlN = 0;
      }
      else{
        APIVbQlN = cnt[0];
        for(V9aVTaxx=(1);V9aVTaxx<(mx);V9aVTaxx++){
          APIVbQlN = max_L(APIVbQlN, cnt[V9aVTaxx]);
        }
      }
      res =APIVbQlN;
    }
    for(k=(0);k<(mx);k++){
      if(cnt[k] >= 2){
        {
          auto iMWUTgY_ = (0);
          auto AlM5nNnR = ( N-1);
          auto XJIcIBrW = ( 0);
          a = iMWUTgY_;
          b = AlM5nNnR;
          tmp = XJIcIBrW;
        }
        for(i=(0);i<(mx);i++){
          pcnt[i] = cnt[i];
        }
        for(;;){
          while(a <  N && A[a] != k){
            pcnt[A[a++]]--;
          }
          while(b >= 0 && A[b] != k){
            pcnt[A[b--]]--;
          }
          pcnt[A[a++]]--;
          pcnt[A[b--]]--;
          tmp += 2;
          if(a > b){
            break;
          }
          {
            int aTqQ6rt8;
            int X9Iss0pP;
            if(mx==0){
              X9Iss0pP = 0;
            }
            else{
              X9Iss0pP = pcnt[0];
              for(aTqQ6rt8=(1);aTqQ6rt8<(mx);aTqQ6rt8++){
                X9Iss0pP = max_L(X9Iss0pP, pcnt[aTqQ6rt8]);
              }
            }
            chmax(res, tmp +X9Iss0pP);
          }
        }
      }
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, A[2d5], mx;
// int cnt[200], pcnt[200];
// {
//   REP(rd_int()){
//     int a, b, tmp, res;
//     rd(N,(A--)(N));
//     mx = max(A(N)) + 1;
// 
//     rep(k,mx) cnt[k] = 0;
//     rep(i,N) cnt[A[i]]++;
//     res = max(cnt(mx));
// 
//     rep(k,mx) if(cnt[k] >= 2){
//       (a, b, tmp) = (0, N-1, 0);
//       rep(i,mx) pcnt[i] = cnt[i];
//       for(;;){
//         while(a <  N && A[a] != k) pcnt[A[a++]]--;
//         while(b >= 0 && A[b] != k) pcnt[A[b--]]--;
//         pcnt[A[a++]]--;
//         pcnt[A[b--]]--;
//         tmp += 2;
//         if(a > b) break;
//         res >?= tmp + max(pcnt(mx));
//       }
//     }
// 
//     wt(res);
//   }
// }