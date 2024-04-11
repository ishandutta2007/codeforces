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
int N;
int M;
char S[1000][1002];
int res[100000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int x = 0;
    int y = 1;
    int z = 0;
    rd(N);
    rd(M);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        if(S[i][j] == S[j][i]){
          {
            auto ao_dF3pO = (i);
            auto tU__gIr_ = ( j);
            auto a2conNHc = ( 1);
            x = ao_dF3pO;
            y = tU__gIr_;
            z = a2conNHc;
          }
          goto WYIGIcGE;
        }
      }
    }
    WYIGIcGE:;
    if(z == 1 || M%2 == 1){
      for(i=(0);i<(M+1);i++){
        if(i%2==0){
          res[i] =x;
        }
        else{
          res[i] =y;
        }
      }
      wt_L("YES");
      wt_L('\n');
      {
        int APIVbQlN;
        if(M+1==0){
          wt_L('\n');
        }
        else{
          for(APIVbQlN=(0);APIVbQlN<(M+1-1);APIVbQlN++){
            wt_L(res[APIVbQlN]+1);
            wt_L(' ');
          }
          wt_L(res[APIVbQlN]+1);
          wt_L('\n');
        }
      }
      continue;
    }
    for(x=(0);x<(N);x++){
      int k;
      for(k=(0);k<(2);k++){
        y = z = -1;
        for(i=(0);i<(N);i++){
          if(S[i][x]=='a'+k){
            y = i;
            break;
          }
        }
        for(i=(0);i<(N);i++){
          if(S[x][i]=='a'+k){
            z = i;
            break;
          }
        }
        if(y != -1 && z != -1){
          wt_L("YES");
          wt_L('\n');
          for(i=(0);i<(M/2);i++){
            if((M/2-i)%2){
              res[i] =z;
            }
            else{
              res[i] =x;
            }
          }
          res[M/2] = x;
          for(i=(0);i<(M/2);i++){
            if((i+1)%2){
              res[M/2+1+i] =y;
            }
            else{
              res[M/2+1+i] =x;
            }
          }
          {
            int zT28qSmp;
            if(M+1==0){
              wt_L('\n');
            }
            else{
              for(zT28qSmp=(0);zT28qSmp<(M+1-1);zT28qSmp++){
                wt_L(res[zT28qSmp]+1);
                wt_L(' ');
              }
              wt_L(res[zT28qSmp]+1);
              wt_L('\n');
            }
          }
          goto Q5VJL1cS;
        }
      }
    }
    wt_L("NO");
    wt_L('\n');
    Q5VJL1cS:;
  }
  return 0;
}
// cLay version 20210103-1 [bug fixed 2]

// --- original code ---
// //no-unlocked
// int N, M;
// char S[1000][1002];
// int res[1d5+2];
// {
//   REP(rd_int()){
//     int x = 0, y = 1, z = 0;
//     rd(N,M,S(N));
//     rep(i,N) rep(j,i+1,N) if(S[i][j] == S[j][i]) (x, y, z) = (i, j, 1), break_break;
//     if(z == 1 || M%2 == 1){
//       rep(i,M+1) res[i] = if[i%2==0, x, y];
//       wt("YES");
//       wt(res(M+1)+1);
//       continue;
//     }
// 
//     rep(x,N) rep(k,2){
//       y = z = -1;
//       rep(i,N) if(S[i][x]=='a'+k) y = i, break;
//       rep(i,N) if(S[x][i]=='a'+k) z = i, break;
//       if(y != -1 && z != -1){
//         wt("YES");
//         rep(i,M/2) res[i] = if[(M/2-i)%2, z, x];
//         res[M/2] = x;
//         rep(i,M/2) res[M/2+1+i] = if[(i+1)%2, y, x];
//         wt(res(M+1)+1);
//         break_break_continue;
//       }
//     }
// 
//     wt("NO");
//   }
// }