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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int N;
int K;
int cost[2000][10];
bitset<2001> dp[2001];
char buf[9];
const char *digit[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int main(){
  int i;
  rd(N);
  rd(K);
  for(i=(0);i<(N);i++){
    int k;
    rd(buf);
    for(k=(0);k<(10);k++){
      int j;
      cost[i][k] = 0;
      for(j=(0);j<(7);j++){
        if(buf[j]==digit[k][j]){
          continue;
        }
        if(buf[j]=='0'){
          cost[i][k]++;
          continue;
        }
        cost[i][k] = 1073709056;
        break;
      }
    }
  }
  dp[N].set(0);
  for(i=(N)-1;i>=(0);i--){
    int k;
    for(k=(0);k<(10);k++){
      if(cost[i][k] < 1073709056){
        dp[i] |= (dp[i+1] << cost[i][k]);
      }
    }
  }
  if(!dp[0][K]){
    wt_L(-1);
    wt_L('\n');
    return 0;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(10)-1;j>=(0);j--){
      if(K-cost[i][j] >= 0 && dp[i+1][K-cost[i][j]]){
        wt_L(j);
        K -= cost[i][j];
        break;
      }
    }
  }
  wt_L("");
  wt_L('\n');
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// //no-unlocked
// int N, K;
// int cost[2000][10];
// bitset<2001> dp[2001];
// char buf[9];
// const char *digit[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
// {
//   rd(N,K);
//   rep(i,N){
//     rd(buf);
//     rep(k,10){
//       cost[i][k] = 0;
//       rep(j,7){
//         if(buf[j]==digit[k][j]) continue;
//         if(buf[j]=='0') cost[i][k]++, continue;
//         cost[i][k] = int_inf, break;
//       }
//     }
//   }
// 
//   dp[N].set(0);
//   rrep(i,N) rep(k,10) if(cost[i][k] < int_inf){
//     dp[i] |= (dp[i+1] << cost[i][k]);
//   }
// 
//   if(!dp[0][K]) wt(-1), return 0;
//   rep(i,N) rrep(j,10){
//     if(K-cost[i][j] >= 0 && dp[i+1][K-cost[i][j]]){
//       wtN(j);
//       K -= cost[i][j];
//       break;
//     }
//   }
//   wt("");
// }