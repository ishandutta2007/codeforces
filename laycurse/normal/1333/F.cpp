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
int res[500000];
int del[500000+1];
vector<int> mul[500000+1];
int main(){
  int i;
  int j;
  int k;
  rd(N);
  for(i=(1);i<(N+1);i++){
    for(j=(i);j<(N+1);j+=(i)){
      mul[i].push_back(j);
    }
  }
  k = N-2;
  for(i=(N+1)-1;i>=(1);i--){
    for(;;){
      if(mul[i].size() <= 1){
        break;
      }
      j = mul[i].back();
      mul[i].pop_back();
      if(del[j]){
        continue;
      }
      del[j] = 1;
      res[k--] = i;
    }
  }
  while(k >= 0){
    res[k--] = 1;
  }
  {
    int KrdatlYV;
    if(N-1==0){
      wt_L('\n');
    }
    else{
      for(KrdatlYV=(0);KrdatlYV<(N-1-1);KrdatlYV++){
        wt_L(res[KrdatlYV]);
        wt_L(' ');
      }
      wt_L(res[KrdatlYV]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200408-1

// --- original code ---
// //no-unlocked
// int N;
// int res[5d5], del[5d5+1];
// vector<int> mul[5d5+1];
// {
//   int i, j, k;
// 
//   rd(N);
//   rep(i,1,N+1) rep(j,i,N+1,i) mul[i].push_back(j);
// 
//   k = N-2;
//   rrep(i,1,N+1){
//     for(;;){
//       if(mul[i].size() <= 1) break;
//       j = mul[i].back();
//       mul[i].pop_back();
//       if(del[j]) continue;
//       del[j] = 1;
//       res[k--] = i;
//     }
//   }
//   while(k >= 0) res[k--] = 1;
//   wt(res(N-1));
// }