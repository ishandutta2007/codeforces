#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
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
char S[1000000+2];
int las[2][1000000+1];
int res[1000000];
int main(){
  int i;
  int j;
  int k;
  rd(N);
  rd(S);
  for(i=(0);i<(N);i++){
    for(k=(0);k<(2);k++){
      if(i){
        las[k][i] =las[k][i-1];
      }
      else{
        las[k][i] =-1;
      }
    }
    if(S[i]=='0'){
      las[0][i] = i;
    }
    if(S[i]=='1'){
      las[1][i] = i;
    }
  }
  for(k=(1);k<(N+1);k++){
    i = 0;
    for(;;){
      if(i + k - 1 >= N){
        break;
      }
      if(las[0][i + k - 1] < i || las[1][i + k - 1] < i){
        res[k-1]++;
        i += k;
        continue;
      }
      i =min_L(las[0][i + k - 1], las[1][i + k - 1])+ 1;
    }
  }
  {
    int t_ynMSdg;
    if(N==0){
      wt_L('\n');
    }
    else{
      for(t_ynMSdg=(0);t_ynMSdg<(N-1);t_ynMSdg++){
        wt_L(res[t_ynMSdg]);
        wt_L(' ');
      }
      wt_L(res[t_ynMSdg]);
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[1d6+2];
// int las[2][1d6+1];
// int res[1d6];
// {
//   int i, j, k;
//   rd(N,S);
//   rep(i,N){
//     rep(k,2) las[k][i] = if[i, las[k][i-1], -1];
//     if(S[i]=='0') las[0][i] = i;
//     if(S[i]=='1') las[1][i] = i;
//   }
// 
//   rep(k,1,N+1){
//     i = 0;
//     for(;;){
//       if(i + k - 1 >= N) break;
//       if(las[0][i + k - 1] < i || las[1][i + k - 1] < i){
//         res[k-1]++;
//         i += k;
//         continue;
//       }
//       i = min(las[0][i + k - 1], las[1][i + k - 1]) + 1;
//     }
//   }
//   wt(res(N));
// }