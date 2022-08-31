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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
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
  int res = 0;
  rd(N);
  rd(S);
  for(i=(0);i<(N);i+=(2)){
    if(S[i]==S[i+1]){
      res++;
      if(S[i]=='a'){
        S[i] ='b';
      }
      else{
        S[i] ='a';
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  wt_L(S);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190925-1

// --- original code ---
// //no-unlocked
// int N;
// char S[200002];
// {
//   int res = 0;
//   rd(N,S);
//   rep(i,0,N,2) if(S[i]==S[i+1]){
//     res++;
//     S[i] = if[S[i]=='a', 'b', 'a'];
//   }
//   wtLn(res,S);
// }