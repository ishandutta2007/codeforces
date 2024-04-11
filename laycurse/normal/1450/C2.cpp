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
template<class S, class T> inline S moddw_L(S a, const T b){
  a %= b;
  if(a < 0){
    a += b;
  }
  return a;
}
int N;
char S[300][302];
int pt[1000];
int cost[1000][3];
int res[1000];
int res_cost;
int tmp;
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, ps;
    res_cost = 1073709056;
    rd(N);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(2*N);i++){
      int j;
      for(j=(0);j<(3);j++){
        cost[i][j] = 0;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        if(S[i][j] == 'O'){
          cost[i+j][0]++;
        }
        if(S[i][j] == 'X'){
          cost[i+j][1]++;
        }
      }
    }
    for(ps=(-1);ps<(2);ps++){
      if(ps){
        int st;
        for(st=(0);st<(3);st++){
          for(i=(0);i<(2*N);i++){
            pt[i] =(moddw_L((st + i * ps),3));
          }
          {
            int iMWUTgY_;
            remove_reference<decltype(cost[iMWUTgY_][pt[iMWUTgY_]])>::type AlM5nNnR;
            int XJIcIBrW = 0;
            if((0) > ((2*N)-1)){
              AlM5nNnR = 0;
            }
            else{
              for(iMWUTgY_ = 0; iMWUTgY_ <= (2*N)-1; iMWUTgY_++){
                if(XJIcIBrW == 0){
                  AlM5nNnR = cost[iMWUTgY_][pt[iMWUTgY_]];
                  XJIcIBrW = 1;
                  continue;
                }
                AlM5nNnR += cost[iMWUTgY_][pt[iMWUTgY_]];
              }
            }
            tmp =AlM5nNnR;
          }
          if(tmp < res_cost){
            res_cost = tmp;
            for(i=(0);i<(2*N);i++){
              res[i] = pt[i];
            }
          }
        }
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        if(res[i+j]==0 && S[i][j] == 'O'){
          S[i][j] = 'X';
          continue;
        }
        if(res[i+j]==1 && S[i][j] == 'X'){
          S[i][j] = 'O';
          continue;
        }
      }
    }
    {
      int szDqbNYU;
      for(szDqbNYU=(0);szDqbNYU<(N);szDqbNYU++){
        wt_L(S[szDqbNYU]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay version 20201206-1

// --- original code ---
// //no-unlocked
// int N;
// char S[300][302];
// int pt[1000];
// int cost[1000][3];
// int res[1000], res_cost, tmp;
// {
//   REP(rd_int()){
//     res_cost = int_inf;
//     rd(N,S(N));
//     rep(i,2*N) rep(j,3) cost[i][j] = 0;
//     rep(i,N) rep(j,N){
//       if(S[i][j] == 'O') cost[i+j][0]++;
//       if(S[i][j] == 'X') cost[i+j][1]++;
//     }
//     rep(ps,-1,2) if(ps) rep(st,3){
//       rep(i,2*N) pt[i] = (st + i * ps) %% 3;
//       tmp = sum[i,0,2*N](cost[i][pt[i]]);
//       if(tmp < res_cost){
//         res_cost = tmp;
//         rep(i,2*N) res[i] = pt[i];
//       }
//     }
// 
//     rep(i,N) rep(j,N){
//       if(res[i+j]==0 && S[i][j] == 'O') S[i][j] = 'X', continue;
//       if(res[i+j]==1 && S[i][j] == 'X') S[i][j] = 'O', continue;
//     }
//     wtLn(S(N));
//   }
// }