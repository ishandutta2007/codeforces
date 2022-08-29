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
int N;
int A[2][200000];
int cnt[200000];
int pr[200000][2];
int pc[200000][2];
int ress;
int res[200000];
int vis[200000];
int as;
int a[200000];
int bs;
int b[200000];
void getnext(int &x, int &y){
  int i = A[x][y];
  if(pr[i][0]==x && pc[i][0]==y){
    x = pr[i][1];
    y = pc[i][1];
  }
  else{
    x = pr[i][0];
    y = pc[i][0];
  }
}
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int x;
    int y;
    rd(N);
    {
      int cTE1_r3A;
      int RZTsC2BF;
      for(cTE1_r3A=(0);cTE1_r3A<(2);cTE1_r3A++){
        for(RZTsC2BF=(0);RZTsC2BF<(N);RZTsC2BF++){
          rd(A[cTE1_r3A][RZTsC2BF]);A[cTE1_r3A][RZTsC2BF] += (-1);
        }
      }
    }
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(j=(0);j<(2);j++){
      for(i=(0);i<(N);i++){
        k = cnt[A[j][i]]++;
        if(k==2){
          wt_L(-1);
          wt_L('\n');
          goto Q5VJL1cS;
        }
        pr[A[j][i]][k] = j;
        pc[A[j][i]][k] = i;
      }
    }
    ress = 0;
    for(i=(0);i<(N);i++){
      vis[i] = 0;
    }
    for(i=(0);i<(N);i++){
      if(vis[i]==0){
        as = bs = 0;
        vis[i] = 1;
        x = pr[i][0];
        y = pc[i][0];
        if(x==1){
          a[as++] = y;
        }
        else{
          b[bs++] = y;
        }
        for(;;){
          getnext(x, y);
          x = 1-x;
          k = A[x][y];
          if(vis[k]){
            break;
          }
          vis[k] = 1;
          if(x==1){
            a[as++] = y;
          }
          else{
            b[bs++] = y;
          }
        }
        if(as < bs){
          for(j=(0);j<(as);j++){
            res[ress++] = a[j];
          }
        }
        else{
          for(j=(0);j<(bs);j++){
            res[ress++] = b[j];
          }
        }
      }
    }
    wt_L(ress);
    wt_L('\n');
    {
      int Q5rsz4fz;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(Q5rsz4fz=(0);Q5rsz4fz<(ress-1);Q5rsz4fz++){
          wt_L(res[Q5rsz4fz]+1);
          wt_L(' ');
        }
        wt_L(res[Q5rsz4fz]+1);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// int A[2][2d5];
// int cnt[2d5], pr[2d5][2], pc[2d5][2];
// 
// int ress, res[2d5];
// int vis[2d5];
// int as, a[2d5], bs, b[2d5];
// 
// void getnext(int &x, int &y){
//   int i = A[x][y];
//   if(pr[i][0]==x && pc[i][0]==y){
//     x = pr[i][1];
//     y = pc[i][1];
//   } else {
//     x = pr[i][0];
//     y = pc[i][0];
//   }
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k, x, y;
//     rd(N,(A--)(2,N));
// 
//     rep(i,N) cnt[i] = 0;
//     rep(j,2) rep(i,N){
//       k = cnt[A[j][i]]++;
//       if(k==2) wt(-1), break_break_continue;
//       pr[A[j][i]][k] = j;
//       pc[A[j][i]][k] = i;
//     }
// 
//     ress = 0;
//     rep(i,N) vis[i] = 0;
//     rep(i,N) if(vis[i]==0){
//       as = bs = 0;
//       vis[i] = 1;
//       x = pr[i][0];
//       y = pc[i][0];
//       if(x==1) a[as++] = y;
//       else     b[bs++] = y;
//       for(;;){
//         getnext(x, y);
//         x = 1-x;
//         k = A[x][y];
//         if(vis[k]) break;
//         vis[k] = 1;
//         if(x==1) a[as++] = y;
//         else     b[bs++] = y;
//       }
//       if(as < bs) rep(j,as) res[ress++] = a[j];
//       else        rep(j,bs) res[ress++] = b[j];
//     }
// 
//     wt(ress);
//     wt(res(ress)+1);
//   }
// }