#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
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
int N;
char S[200002];
int main(){
  int i;
  int s = 0;
  int p = 0;
  rd(N);
  rd(S);
  for(i=0;i<(N/2);i++){
    if(S[i]=='?'){
      s += 9;
    }
    else{
      s += 2*(S[i] - '0');
    }
  }
  for(i=(N/2);i<(N);i++){
    if(S[i]=='?'){
      s -= 9;
    }
    else{
      s -= 2*(S[i] - '0');
    }
  }
  if(s){
    wt_L("Monocarp");
    wt_L('\n');
  }
  else{
    wt_L("Bicarp");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20190914-1

// --- original code ---
// //no-unlocked
// int N;
// char S[200002];
// {
//   int s = 0, p = 0;
//   rd(N,S);
// 
//   rep(i,N/2){
//     if(S[i]=='?') s += 9;
//     else          s += 2(S[i] - '0');
//   }
//   rep(i,N/2,N){
//     if(S[i]=='?') s -= 9;
//     else          s -= 2(S[i] - '0');
//   }
// 
//   wt( if[s, "Monocarp", "Bicarp"] );
// }