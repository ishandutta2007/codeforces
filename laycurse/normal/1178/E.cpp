#include<bits/stdc++.h>
using namespace std;
inline int rd(char c[]){
  int i, sz=0;
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
char S[1000002];
int N;
char res[1000002];
int len;
char tmp[1000002];
int tmps;
int main(){
  int a, b, i, j, k;
  N = rd(S);
  a = 0;
  b = N-1;
  while(a <= b){
    if(a==b){
      res[len++] = S[a];
      break;
    }
    if(S[a]==S[b]){
      res[len++] = S[a];
      tmp[tmps++] = S[b];
      a++;
      b--;
      continue;
    }
    if(S[a+1] == S[b]){
      a++;
      continue;
    }
    if(S[a] == S[b-1]){
      b--;
      continue;
    }
    a++;
    b--;
  }
  while(tmps){
    res[len++] = tmp[--tmps];
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// //no-unlocked
// char S[1000002]; int N;
// 
// char res[1000002]; int len;
// char tmp[1000002]; int tmps;
// {
//   int i, j, k;
//   int a, b;
// 
//   rd(S@N);
//   a = 0;
//   b = N-1;
//   while(a <= b){
//     if(a==b){
//       res[len++] = S[a];
//       break;
//     }
//     
//     if(S[a]==S[b]){
//       res[len++] = S[a];
//       tmp[tmps++] = S[b];
//       a++; b--;
//       continue;
//     }
// 
//     if(S[a+1] == S[b]){
//       a++; continue;
//     }
// 
//     if(S[a] == S[b-1]){
//       b--; continue;
//     }
// 
//     a++; b--;
//   }
// 
//   while(tmps) res[len++] = tmp[--tmps];
//   wt(res);
// }