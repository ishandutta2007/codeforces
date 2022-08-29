#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
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
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int N[3];
int A[3][200];
long long dp[201][201][201];
int main(){
  int i;
  wmem = memarr;
  int k[3];
  int r[3];
  long long res = 0;
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(3);Lj4PdHRW++){
      rd(N[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(3);i++){
    {
      int RZTsC2BF;
      for(RZTsC2BF=(0);RZTsC2BF<(N[i]);RZTsC2BF++){
        rd(A[i][RZTsC2BF]);
      }
    }
  }
  for(i=(0);i<(3);i++){
    sortA_L(N[i], A[i]);
  }
  for(k[0]=(N[0]+1)-1;k[0]>=(0);k[0]--){
    for(k[1]=(N[1]+1)-1;k[1]>=(0);k[1]--){
      for(k[2]=(N[2]+1)-1;k[2]>=(0);k[2]--){
        for(i=(0);i<(3);i++){
          int j;
          for(j=(i+1);j<(3);j++){
            {
              int ZIeRIny5;
              for(ZIeRIny5=(0);ZIeRIny5<((2) + 1);ZIeRIny5++){
                r[ZIeRIny5] = k[ZIeRIny5];
              }
            }
            r[i]++;
            r[j]++;
            if(r[0] <= N[0] && r[1] <= N[1] && r[2] <= N[2]){
              chmax(dp[k[0]][k[1]][k[2]], dp[r[0]][r[1]][r[2]] + A[i][k[i]] * A[j][k[j]]);
            }
          }
        }
        chmax(res, dp[k[0]][k[1]][k[2]]);
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N[3], A[3][200];
// ll dp[201][201][201];
// {
//   int k[3], r[3];
//   ll res = 0;
//   rd(N(3));
//   rep(i,3) rd(A[i](N[i]));
//   rep(i,3) sortA(N[i], A[i]);
//   rrep(k[0],N[0]+1) rrep(k[1],N[1]+1) rrep(k[2],N[2]+1){
//     rep(i,3) rep(j,i+1,3){
//       r[0..2] = k[0..2];
//       r[i]++;
//       r[j]++;
//       if(r[0] <= N[0] && r[1] <= N[1] && r[2] <= N[2]){
//         dp[k[0]][k[1]][k[2]] >?= dp[r[0]][r[1]][r[2]] + A[i][k[i]] * A[j][k[j]];
//       }
//     }
//     res >?= dp[k[0]][k[1]][k[2]];
//   }
//   wt(res);
// }