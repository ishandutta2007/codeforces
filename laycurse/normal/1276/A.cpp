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
inline int rd_int(void){
  int x;
  rd(x);
  return x;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int N;
char S[200000];
int dp[5][200000];
int ress;
int res[200000];
int go[5][256];
int main(){
  int Lj4PdHRW;
  int i;
  int j;
  int k;
  go[0]['o'] = 1;
  go[0]['t'] = 3;
  go[1]['o'] = 1;
  go[1]['n'] = 2;
  go[1]['t'] = 3;
  go[2]['o'] = 1;
  go[2]['e'] = -1;
  go[2]['t'] = 3;
  go[3]['o'] = 1;
  go[3]['t'] = 3;
  go[3]['w'] = 4;
  go[4]['o'] = -1;
  go[4]['t'] = 3;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    N = rd(S);
    ress = 0;
    dp[0][0] = 0;
    for(i=(1);i<(5);i++){
      dp[i][0] = 1073709056;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(5);j++){
        dp[j][i+1] = dp[j][i] + 1;
      }
      for(j=(0);j<(5);j++){
        if(go[j][S[i]] != -1){
          chmin(dp[go[j][S[i]]][i+1], dp[j][i]);
        }
      }
    }
    k = 1073709056;
    for(i=(0);i<(5);i++){
      if(dp[i][N] < k){
        j = i;
        k = dp[i][N];
      }
    }
    i = N;
    while(dp[j][i]){
      if(dp[j][i] == dp[j][i-1] + 1){
        res[ress++] = i;
        i--;
        continue;
      }
      for(k=(0);k<(5);k++){
        if(go[k][S[i-1]] == j && dp[j][i] == dp[k][i-1]){
          break;
        }
      }
      j = k;
      i--;
    }
    wt_L(ress);
    wt_L('\n');
    {
      int jZyWAPpY;
      if(ress==0){
        putchar('\n');
      }
      else{
        for(jZyWAPpY=(0);jZyWAPpY<(ress-1);jZyWAPpY++){
          wt_L(res[jZyWAPpY]);
          wt_L(' ');
        }
        wt_L(res[jZyWAPpY]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20191208-1 [beta]

// --- original code ---
// //no-unlocked
// int N;
// char S[2d5];
// int dp[5][2d5];
// int ress, res[2d5];
// 
// int go[5][256];
// 
// {
//   int i, j, k;
// 
//   go[0]['o'] = 1;
//   go[0]['t'] = 3;
// 
//   go[1]['o'] = 1;
//   go[1]['n'] = 2;
//   go[1]['t'] = 3;
// 
//   go[2]['o'] = 1;
//   go[2]['e'] = -1;
//   go[2]['t'] = 3;
// 
//   go[3]['o'] = 1;
//   go[3]['t'] = 3;
//   go[3]['w'] = 4;
// 
//   go[4]['o'] = -1;
//   go[4]['t'] = 3;
// 
//   REP(rd_int()){
//     rd(S@N);
//     ress = 0;
// 
//     dp[0][0] = 0;
//     rep(i,1,5) dp[i][0] = int_inf;
// 
//     rep(i,N){
//       rep(j,5) dp[j][i+1] = dp[j][i] + 1;
//       rep(j,5) if(go[j][S[i]] != -1) dp[go[j][S[i]]][i+1] <?= dp[j][i];
//     }
// 
//     k = int_inf;
//     rep(i,5) if(dp[i][N] < k) j = i, k = dp[i][N];
//     i = N;
//     while(dp[j][i]){
//       if(dp[j][i] == dp[j][i-1] + 1){
//         res[ress++] = i;
//         i--;
//         continue;
//       }
// 
//       rep(k,5) if(go[k][S[i-1]] == j && dp[j][i] == dp[k][i-1]) break;
//       j = k;
//       i--;
//     }
//     wt(ress);
//     wt(res(ress));
//   }
// }