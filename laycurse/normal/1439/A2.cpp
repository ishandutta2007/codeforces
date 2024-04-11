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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
int X;
int Y;
char S[100][102];
int ress;
int res[10000][6];
int zs;
int z1[4];
int z2[4];
int os;
int o1[4];
int o2[4];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, j;
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(X);cTE1_r3A++){
        rd(S[cTE1_r3A]);
      }
    }
    for(i=(0);i<(X);i++){
      int j;
      for(j=(0);j<(Y);j++){
        S[i][j] -= '0';
      }
    }
    ress = 0;
    for(i=(0);i<(X-2);i++){
      int j;
      for(j=(0);j<(Y);j++){
        if(S[i][j]==1){
          int k;
          {
            auto V9aVTaxx = (i);
            auto APIVbQlN = ( j);
            res[ress][0] = V9aVTaxx;
            res[ress][1] = APIVbQlN;
          }
          {
            auto YREPHmFM = (i+1);
            auto jZyWAPpY = ( j);
            res[ress][2] = YREPHmFM;
            res[ress][3] = jZyWAPpY;
          }
          if(j==Y-1){
            {
              auto jbtyPBGc = (i+1);
              auto ZIeRIny5 = (j-1);
              res[ress][4] = jbtyPBGc;
              res[ress][5] = ZIeRIny5;
            }
          }
          else{
            {
              auto iMWUTgY_ = (i+1);
              auto AlM5nNnR = (j+1);
              res[ress][4] = iMWUTgY_;
              res[ress][5] = AlM5nNnR;
            }
          }
          for(k=(0);k<(3);k++){
            S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
          }
          ress++;
        }
      }
    }
    for(j=(0);j<(Y-2);j++){
      for(i=(X-2);i<(X);i++){
        if(S[i][j]==1){
          int k;
          {
            auto qSsg05KM = (i);
            auto Hjfu7Vx7 = ( j);
            res[ress][0] = qSsg05KM;
            res[ress][1] = Hjfu7Vx7;
          }
          {
            auto zT28qSmp = (i);
            auto aTqQ6rt8 = ( j+1);
            res[ress][2] = zT28qSmp;
            res[ress][3] = aTqQ6rt8;
          }
          if(i==X-1){
            {
              auto X9Iss0pP = (i-1);
              auto szDqbNYU = ( j+1);
              res[ress][4] = X9Iss0pP;
              res[ress][5] = szDqbNYU;
            }
          }
          else{
            {
              auto ytthggxT = (i+1);
              auto O3U4gd88 = ( j+1);
              res[ress][4] = ytthggxT;
              res[ress][5] = O3U4gd88;
            }
          }
          for(k=(0);k<(3);k++){
            S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
          }
          ress++;
        }
      }
    }
    zs = os = 0;
    for(i=(X-2);i<(X);i++){
      for(j=(Y-2);j<(Y);j++){
        if(S[i][j]==0){
          arrInsert(zs, zs, z1, i, z2, j);
        }
        if(S[i][j]==1){
          arrInsert(os, os, o1, i, o2, j);
        }
      }
    }
    if(os == 1){
      for(i=(0);i<(3);i++){
        int k;
        for(k=(0);k<(2);k++){
          {
            auto mlGkBPoR = (z1[(i+k)%3]);
            auto YlLMHsfa = ( z2[(i+k)%3]);
            res[ress][2*k] = mlGkBPoR;
            res[ress][2*k+1] = YlLMHsfa;
          }
        }
        {
          auto sMcf5Tpe = (o1[0]);
          auto aWpYLTGo = ( o2[0]);
          res[ress][4] = sMcf5Tpe;
          res[ress][5] = aWpYLTGo;
        }
        for(k=(0);k<(3);k++){
          S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
        }
        ress++;
      }
    }
    if(os == 2){
      for(i=(0);i<(2);i++){
        int k;
        for(k=(0);k<(2);k++){
          {
            auto jO2HaRTX = (z1[k]);
            auto IlgsnSAd = ( z2[k]);
            res[ress][2*k] = jO2HaRTX;
            res[ress][2*k+1] = IlgsnSAd;
          }
        }
        {
          auto jG1yfsum = (o1[i]);
          auto NLJcSLph = ( o2[i]);
          res[ress][4] = jG1yfsum;
          res[ress][5] = NLJcSLph;
        }
        for(k=(0);k<(3);k++){
          S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
        }
        ress++;
      }
    }
    if(os == 3){
      int k;
      for(k=(0);k<(3);k++){
        {
          auto WZu7joIG = (o1[k]);
          auto Wv3_QJ0O = ( o2[k]);
          res[ress][2*k] = WZu7joIG;
          res[ress][2*k+1] = Wv3_QJ0O;
        }
      }
      for(k=(0);k<(3);k++){
        S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
      }
      ress++;
    }
    if(os == 4){
      for(i=(0);i<(4);i++){
        int k;
        for(k=(0);k<(3);k++){
          {
            auto bXO5jt5I = (o1[(i+k)%4]);
            auto W9o_dQUM = ( o2[(i+k)%4]);
            res[ress][2*k] = bXO5jt5I;
            res[ress][2*k+1] = W9o_dQUM;
          }
        }
        for(k=(0);k<(3);k++){
          S[res[ress][2*k]][res[ress][2*k+1]] ^= 1;
        }
        ress++;
      }
    }
    wt_L(ress);
    wt_L('\n');
    for(i=(0);i<(ress);i++){
      {
        int HK5nwQQr;
        if(6==0){
          wt_L('\n');
        }
        else{
          for(HK5nwQQr=(0);HK5nwQQr<(6-1);HK5nwQQr++){
            wt_L(res[i][HK5nwQQr]+1);
            wt_L(' ');
          }
          wt_L(res[i][HK5nwQQr]+1);
          wt_L('\n');
        }
      }
    }
  }
  return 0;
}
// cLay version 20201121-1

// --- original code ---
// //no-unlocked
// int X, Y;
// char S[100][102];
// int ress, res[10000][6];
// 
// int zs, z1[4], z2[4];
// int os, o1[4], o2[4];
// {
//   REP(rd_int()){
//     rd(X,Y,S(X));
//     rep(i,X) rep(j,Y) S[i][j] -= '0';
//     ress = 0;
// 
//     rep(i,X-2) rep(j,Y) if(S[i][j]==1){
//       (res[ress][0], res[ress][1]) = (i, j);
//       (res[ress][2], res[ress][3]) = (i+1, j);
//       (res[ress][4], res[ress][5]) = (i+1, if[j==Y-1, j-1, j+1]);
//       rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//       ress++;
//     }
//     rep(j,Y-2) rep(i,X-2,X) if(S[i][j]==1){
//       (res[ress][0], res[ress][1]) = (i, j);
//       (res[ress][2], res[ress][3]) = (i, j+1);
//       (res[ress][4], res[ress][5]) = (if[i==X-1, i-1, i+1], j+1);
//       rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//       ress++;
//     }
// 
//     zs = os = 0;
//     rep(i,X-2,X) rep(j,Y-2,Y){
//       if(S[i][j]==0) arrInsert(zs, zs, z1, i, z2, j);
//       if(S[i][j]==1) arrInsert(os, os, o1, i, o2, j);
//     }
// 
//     if(os == 1){
//       rep(i,3){
//         rep(k,2) (res[ress][2k], res[ress][2k+1]) = (z1[(i+k)%3], z2[(i+k)%3]);
//         (res[ress][4], res[ress][5]) = (o1[0], o2[0]);
//         rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//         ress++;
//       }
//     }
//     if(os == 2){
//       rep(i,2){
//         rep(k,2) (res[ress][2k], res[ress][2k+1]) = (z1[k], z2[k]);
//         (res[ress][4], res[ress][5]) = (o1[i], o2[i]);
//         rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//         ress++;
//       }
//     }
//     if(os == 3){
//       rep(k,3) (res[ress][2k], res[ress][2k+1]) = (o1[k], o2[k]);
//       rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//       ress++;
//     }
//     if(os == 4){
//       rep(i,4){
//         rep(k,3) (res[ress][2k], res[ress][2k+1]) = (o1[(i+k)%4], o2[(i+k)%4]);
//         rep(k,3) S[res[ress][2k]][res[ress][2k+1]] ^= 1;
//         ress++;
//       }
//     }
// 
//     wt(ress);
//     rep(i,ress) wt(res[i](6)+1);
//   }
// }