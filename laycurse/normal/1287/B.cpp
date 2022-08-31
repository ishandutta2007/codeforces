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
inline void rd(char &c){
  int i;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = my_getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = my_getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
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
int K;
char S[1500][32];
int main(){
  int i;
  int res = 0;
  map<long long,int> mp;
  rd(N);
  rd(K);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(K);j++){
      if(S[i][j]=='S'){
        S[i][j] =0;
      }
      else if(S[i][j]=='E'){
        S[i][j] =1;
      }
      else{
        S[i][j] =2;
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    long long ind = 0;
    for(j=(0);j<(K);j++){
      ind = ind * 3 + S[i][j];
    }
    mp[ind] = i;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(i+1);j<(N);j++){
      int k;
      long long ind = 0;
      for(k=(0);k<(K);k++){
        ind *= 3;
        if(S[i][k]==S[j][k]){
          ind += S[i][k];
          continue;
        }
        ind += 3 - S[i][k] - S[j][k];
      }
      if(mp.count(ind) && mp[ind] > j){
        res++;
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, K;
// char S[1500][32];
// {
//   int res = 0;
//   map<ll,int> mp;
//   rd(N,K,S(N));
//   rep(i,N) rep(j,K) S[i][j] = if[S[i][j]=='S', 0, S[i][j]=='E', 1, 2];
//   rep(i,N){
//     ll ind = 0;
//     rep(j,K) ind = ind * 3 + S[i][j];
//     mp[ind] = i;
//   }
//   rep(i,N) rep(j,i+1,N){
//     ll ind = 0;
//     rep(k,K){
//       ind *= 3;
//       if(S[i][k]==S[j][k]) ind += S[i][k], continue;
//       ind += 3 - S[i][k] - S[j][k];
//     }
//     if(mp.count(ind) && mp[ind] > j) res++;
//   }
//   wt(res);
// }