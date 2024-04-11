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
long long ds[10000000+1];
long long res[10000000+1];
int main(){
  int WYIGIcGE, i;
  for(i=(1);i<(10000000+1);i++){
    int j;
    for(j=(i);j<(10000000+1);j+=(i)){
      ds[j] += i;
    }
  }
  for(i=(0);i<(10000000+1);i++){
    res[i] = -1;
  }
  for(i=(0);i<(10000000+1);i++){
    if(ds[i] <= 10000000 && res[ds[i]] == -1){
      res[ds[i]] = i;
    }
  }
  int t_ynMSdg = rd_int();
  for(WYIGIcGE=(0);WYIGIcGE<(t_ynMSdg);WYIGIcGE++){
    wt_L(res[rd_int()]);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210405-1

// --- original code ---
// //no-unlocked
// ll ds[1d7+1], res[1d7+1];
// {
//   rep(i,1,1d7+1) rep(j,i,1d7+1,i) ds[j] += i;
//   rep(i,1d7+1) res[i] = -1;
//   rep(i,1d7+1) if(ds[i] <= 1d7 && res[ds[i]] == -1) res[ds[i]] = i;
//   REP(rd_int()) wt(res[rd_int()]);
// }