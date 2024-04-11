#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
int main(){
  int cTE1_r3A, i;
  int X;
  rd(X);
  int Y;
  rd(Y);
  int Q;
  rd(Q);
  int A[1000][1000] = {};
  long long dp1[1000][1000] = {};
  long long dp2[1000][1000] = {};
  long long res = 0;
  long long tmp;
  for(i=(0);i<(X);i++){
    int j;
    for(j=(0);j<(Y);j++){
      if(i+1 < X){
        dp1[i+1][j] += dp2[i][j] + 1;
      }
      if(j+1 < Y){
        dp2[i][j+1] += dp1[i][j] + 1;
      }
      res += 1 + dp1[i][j] + dp2[i][j];
    }
  }
  for(cTE1_r3A=(0);cTE1_r3A<(Q);cTE1_r3A++){
    int R;
    rd(R);R += (-1);
    int C;
    rd(C);C += (-1);
    int r;
    int c;
    long long up1 = 1;
    long long up2 = 1;
    long long dw1 = 1;
    long long dw2 = 1;
    auto xr20shxY = ((R));
    auto WYIGIcGE = (( C));
    r=xr20shxY;
    c=WYIGIcGE;
    for(;;){
      if(up1%2==1){
        r--;
      }
      else{
        c--;
      }
      if(!(0 <= r  &&  r < X && 0 <= c  &&  c < Y) || A[r][c]){
        break;
      }
      up1++;
    }
    auto ao_dF3pO = ((R));
    auto tU__gIr_ = (( C));
    r=ao_dF3pO;
    c=tU__gIr_;
    for(;;){
      if(up2%2==0){
        r--;
      }
      else{
        c--;
      }
      if(!(0 <= r  &&  r < X && 0 <= c  &&  c < Y) || A[r][c]){
        break;
      }
      up2++;
    }
    auto V9aVTaxx = ((R));
    auto APIVbQlN = (( C));
    r=V9aVTaxx;
    c=APIVbQlN;
    for(;;){
      if(dw1%2==1){
        c++;
      }
      else{
        r++;
      }
      if(!(0 <= r  &&  r < X && 0 <= c  &&  c < Y) || A[r][c]){
        break;
      }
      dw1++;
    }
    auto jbtyPBGc = ((R));
    auto ZIeRIny5 = (( C));
    r=jbtyPBGc;
    c=ZIeRIny5;
    for(;;){
      if(dw2%2==0){
        c++;
      }
      else{
        r++;
      }
      if(!(0 <= r  &&  r < X && 0 <= c  &&  c < Y) || A[r][c]){
        break;
      }
      dw2++;
    }
    A[R][C] ^= 1;
    if(A[R][C]==0){
      res +=up1 * dw1 + up2 * dw2 - 1;
    }
    else{
      res -=up1 * dw1 + up2 * dw2 - 1;
    }
    wt_L(res);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210926-1

// --- original code ---
// //no-unlocked
// int @X, @Y, @Q, A[1000][1000] = {}; ll dp1[1000][1000] = {}, dp2[1000][1000] = {};
// ll res = 0, tmp;
// 
// rep(i,X) rep(j,Y){
//   if(i+1 < X) dp1[i+1][j] += dp2[i][j] + 1;
//   if(j+1 < Y) dp2[i][j+1] += dp1[i][j] + 1;
//   res += 1 + dp1[i][j] + dp2[i][j];
// }
// 
// rep(Q){
//   int @R--, @C--, r, c;
//   ll up1 = 1, up2 = 1, dw1 = 1, dw2 = 1;
// 
//   (r, c) = (R, C);
//   for(;;){
//     if[up1%2==1, r--, c--];
//     if(!(0 <= r < X && 0 <= c < Y) || A[r][c]) break;
//     up1++;
//   }
// 
//   (r, c) = (R, C);
//   for(;;){
//     if[up2%2==0, r--, c--];
//     if(!(0 <= r < X && 0 <= c < Y) || A[r][c]) break;
//     up2++;
//   }
// 
//   (r, c) = (R, C);
//   for(;;){
//     if[dw1%2==1, c++, r++];
//     if(!(0 <= r < X && 0 <= c < Y) || A[r][c]) break;
//     dw1++;
//   }
// 
//   (r, c) = (R, C);
//   for(;;){
//     if[dw2%2==0, c++, r++];
//     if(!(0 <= r < X && 0 <= c < Y) || A[r][c]) break;
//     dw2++;
//   }
// 
//   A[R][C] ^= 1;
//   res if[A[R][C]==0, +=, -=] up1 * dw1 + up2 * dw2 - 1;
//   wt(res);
// }