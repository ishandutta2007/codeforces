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
int H;
int G;
int A[3000000];
int ress;
int res[2000000];
long long val;
int chk_del(int n){
  int n1;
  int n2;
  for(;;){
    n1 = 2*n;
    n2 = 2*n + 1;
    if(A[n1] == A[n2]  &&  A[n2] == 0){
      break;
    }
    if(A[n1] > A[n2]){
      n =n1;
    }
    else{
      n =n2;
    }
  }
  return n;
}
void do_del(int n){
  int n1;
  int n2;
  int t;
  for(;;){
    n1 = 2*n;
    n2 = 2*n + 1;
    if(A[n1] == A[n2]  &&  A[n2] == 0){
      A[n] = 0;
      break;
    }
    if(A[n1] > A[n2]){
      t =n1;
    }
    else{
      t =n2;
    }
    A[n] = A[t];
    n = t;
  }
}
void doit(int n){
  int k;
  if(n >= (1<<G)){
    return;
  }
  for(;;){
    k = chk_del(n);
    if(k < (1<<G)){
      break;
    }
    do_del(n);
    res[ress++] = n;
  }
  doit(2*n);
  doit(2*n+1);
}
int main(){
  int FmcKpFmN;
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    int i;
    rd(H);
    rd(G);
    for(i=(0);i<(2<<H);i++){
      A[i] = 0;
    }
    for(i=(1);i<(1<<H);i++){
      rd(A[i]);
    }
    ress = 0;
    doit(1);
    val = 0;
    for(i=(1);i<(1<<G);i++){
      val += A[i];
    }
    wt_L(val);
    wt_L('\n');
    {
      int APIVbQlN;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(APIVbQlN=(0);APIVbQlN<(ress-1);APIVbQlN++){
          wt_L(res[APIVbQlN]);
          wt_L(' ');
        }
        wt_L(res[APIVbQlN]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200325-1

// --- original code ---
// //no-unlocked
// int H, G, A[3d6];
// int ress, res[2d6]; ll val;
// 
// int chk_del(int n){
//   int n1, n2;
//   for(;;){
//     n1 = 2n;
//     n2 = 2n + 1;
//     if(A[n1] == A[n2] == 0) break;
//     n = if[A[n1] > A[n2], n1, n2];
//   }
//   return n;
// }
// 
// void do_del(int n){
//   int n1, n2, t;
//   for(;;){
//     n1 = 2n;
//     n2 = 2n + 1;
//     if(A[n1] == A[n2] == 0) A[n] = 0, break;
//     t = if[A[n1] > A[n2], n1, n2];
//     A[n] = A[t];
//     n = t;
//   }
// }
// 
// void doit(int n){
//   int k;
// 
//   if(n >= (1<<G)) return;
// 
//   for(;;){
//     k = chk_del(n);
//     if(k < (1<<G)) break;
//     do_del(n);
//     res[ress++] = n;
//   }
// 
//   doit(2n);
//   doit(2n+1);
// }
// 
// {
//   REP(rd_int()){
//     rd(H,G);
//     rep(i,2<<H) A[i] = 0;
//     rep(i,1,1<<H) rd(A[i]);
//     ress = 0;
//     doit(1);
// 
//     val = 0;
//     rep(i,1,1<<G) val += A[i];
//     wt(val);
//     wt(res(ress));
//   }
// }