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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
char S[200000+2];
int main(){
  int Lj4PdHRW;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i, x;
    int res = -1;
    int tmp;
    N = rd(S);
    for(i=(0);i<(N);i++){
      S[i] -= '0';
    }
    for(x=(0);x<(10);x++){
      tmp = 0;
      for(i=(0);i<(N);i++){
        if(S[i]==x){
          tmp++;
        }
      }
      chmax(res, tmp);
    }
    for(x=(0);x<(10);x++){
      int y;
      for(y=(0);y<(10);y++){
        tmp = 0;
        for(i=(0);i<(N);i++){
          if(tmp%2==0 && S[i]==x){
            tmp++;
            continue;
          }
          if(tmp%2==1 && S[i]==y){
            tmp++;
            continue;
          }
        }
        chmax(res, (tmp/2)*2);
      }
    }
    wt_L(N-res);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N;
// char S[2d5+2];
// {
//   REP(rd_int()){
//     int res = -1, tmp;
//     rd(S@N);
//     rep(i,N) S[i] -= '0';
// 
//     rep(x,10){
//       tmp = 0;
//       rep(i,N) if(S[i]==x) tmp++;
//       res >?= tmp;
//     }
// 
//     rep(x,10) rep(y,10){
//       tmp = 0;
//       rep(i,N){
//         if(tmp%2==0 && S[i]==x) tmp++, continue;
//         if(tmp%2==1 && S[i]==y) tmp++, continue;
//       }
//       res >?= (tmp/2)*2;
//     }
// 
//     wt(N-res);
//   }
// }