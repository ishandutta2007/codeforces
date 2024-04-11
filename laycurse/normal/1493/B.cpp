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
template<class T, class S> int arrCountVal(int N, T A[], S val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int H;
int M;
int hh;
int mm;
int arr[4];
int r[4];
int rev[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    rd(H);
    rd(M);
    rd(hh);
    rd(mm);mm += (-1);
    for(;;){
      int i;
      mm++;
      if(mm == M){
        mm = 0;
        hh++;
      }
      if(hh == H){
        hh = 0;
      }
      auto FmcKpFmN = ((hh/10));
      auto xr20shxY = (( hh%10));
      auto WYIGIcGE = (( mm/10));
      auto t_ynMSdg = (( mm%10));
      arr[0]=FmcKpFmN;
      arr[1]=xr20shxY;
      arr[2]=WYIGIcGE;
      arr[3]=t_ynMSdg;
      for(i=(0);i<(4);i++){
        r[3-i] = rev[arr[i]];
      }
      if(arrCountVal(4,r,-1)){
        continue;
      }
      if(r[0]*10+r[1] >= H || r[2]*10+r[3] >= M){
        continue;
      }
      wt_L(arr[0]);
      wt_L(arr[1]);
      wt_L(":");
      wt_L(arr[2]);
      wt_L(arr[3]);
      wt_L("\n");
      break;
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //no-unlocked
// int H, M, hh, mm;
// int arr[4], r[4];
// int rev[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
// {
//   REP(rd_int()){
//     rd(H,M,hh,mm--);
//     for(;;){
//       mm++;
//       if(mm == M) mm = 0, hh++;
//       if(hh == H) hh = 0;
//       (arr[0], arr[1], arr[2], arr[3]) = (hh/10, hh%10, mm/10, mm%10);
//       rep(i,4) r[3-i] = rev[arr[i]];
//       if(arrCountVal(4,r,-1)) continue;
//       if(r[0]*10+r[1] >= H || r[2]*10+r[3] >= M) continue;
//       wtN(arr[0],arr[1],":",arr[2],arr[3],"\n");
//       break;
//     }
//   }
// }