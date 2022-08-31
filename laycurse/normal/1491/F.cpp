#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar(){
  return getchar();
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
inline void my_putchar(const int k){
  putchar(k);
  if(k=='\n'){
    fflush(stdout);
  }
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
int N;
int arr[2000];
int f;
int ress;
int res[2000];
int main(){
  int Q5VJL1cS;
  int i;
  int j;
  int x;
  int y;
  for(i=(0);i<(2000);i++){
    arr[i] = i+1;
  }
  int e98WHCEY = rd_int();
  for(Q5VJL1cS=(0);Q5VJL1cS<(e98WHCEY);Q5VJL1cS++){
    rd(N);
    for(y=(1);y<(N-1);y++){
      wt_L("?");
      wt_L(' ');
      wt_L(y);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
      {
        int WYIGIcGE;
        if(y==0){
          wt_L('\n');
        }
        else{
          for(WYIGIcGE=(0);WYIGIcGE<(y-1);WYIGIcGE++){
            wt_L(arr[WYIGIcGE]);
            wt_L(' ');
          }
          wt_L(arr[WYIGIcGE]);
          wt_L('\n');
        }
      }
      wt_L(y+1);
      wt_L('\n');
      rd(f);
      if(f){
        break;
      }
    }
    int ao_dF3pO;
    int tU__gIr_;
    int a2conNHc;
    ao_dF3pO = 0;
    tU__gIr_ = y-1;
    while(ao_dF3pO < tU__gIr_){
      if((ao_dF3pO + tU__gIr_)%2==0){
        a2conNHc = (ao_dF3pO + tU__gIr_) / 2;
      }
      else{
        a2conNHc = (ao_dF3pO + tU__gIr_ - 1) / 2;
      }
      wt_L("?");
      wt_L(' ');
      wt_L(a2conNHc+1);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
      {
        int APIVbQlN;
        if(a2conNHc+1==0){
          wt_L('\n');
        }
        else{
          for(APIVbQlN=(0);APIVbQlN<(a2conNHc+1-1);APIVbQlN++){
            wt_L(arr[APIVbQlN]);
            wt_L(' ');
          }
          wt_L(arr[APIVbQlN]);
          wt_L('\n');
        }
      }
      wt_L(y+1);
      wt_L('\n');
      rd(f);
      if(f){
        tU__gIr_ = a2conNHc;
      }
      else{
        ao_dF3pO = a2conNHc + 1;
      }
    }
    x =tU__gIr_;
    ress = 0;
    for(i=(0);i<(y);i++){
      if(i != x){
        res[ress++] = i;
      }
    }
    for(i=(y+1);i<(N);i++){
      wt_L("?");
      wt_L(' ');
      wt_L(1);
      wt_L(' ');
      wt_L(1);
      wt_L('\n');
      wt_L(y+1);
      wt_L('\n');
      wt_L(i+1);
      wt_L('\n');
      rd(f);
      if(f==0){
        res[ress++] = i;
      }
    }
    wt_L("!");
    wt_L(' ');
    wt_L(ress);
    wt_L(' ');
    {
      int XJIcIBrW;
      if(ress==0){
        wt_L('\n');
      }
      else{
        for(XJIcIBrW=(0);XJIcIBrW<(ress-1);XJIcIBrW++){
          wt_L(res[XJIcIBrW]+1);
          wt_L(' ');
        }
        wt_L(res[XJIcIBrW]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20210227-1

// --- original code ---
// //interactive
// int N, arr[2000], f;
// int ress, res[2000];
// {
//   int i, j, x, y;
//   rep(i,2000) arr[i] = i+1;
//   REP(rd_int()){
//     rd(N);
//     rep(y,1,N-1){
//       wt("?", y, 1);
//       wt(arr(y));
//       wt(y+1);
//       rd(f);
//       if(f) break;
//     }
//     x = bsearch_min[int,x,0,y-1][
//       wt("?", x+1, 1);
//       wt(arr(x+1));
//       wt(y+1);
//       rd(f);
//     ](f);
//     ress = 0;
//     rep(i,y) if(i != x) res[ress++] = i;
//     rep(i,y+1,N){
//       wt("?", 1, 1);
//       wt(y+1);
//       wt(i+1);
//       rd(f);
//       if(f==0) res[ress++] = i;
//     }
//     wt("!", ress, res(ress)+1);
//   }
// }