#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar();
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
    i = getchar();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar(c[i]);
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
char S[500002];
int main(){
  int i;
  int mn = 'z';
  N = rd(S);
  for(i=(0);i<(N);i++){
    if(mn < S[i]){
      wt_L("Ann");
      wt_L('\n');
    }
    else{
      wt_L("Mike");
      wt_L('\n');
    }
    chmin(mn, S[i]);
  }
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// //no-unlocked
// int N; char S[500002];
// {
//   int mn = 'z';
//   rd(S@N);
//   rep(i,N){
//     wt( if[mn < S[i], "Ann", "Mike"] );
//     mn <?= S[i];
//   }
// }