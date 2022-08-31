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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int cnt[100000+1];
int d8;
int d6;
int d4;
int d2;
int main(){
  int FmcKpFmN, Lj4PdHRW, i;
  char c;
  int x;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    cnt[rd_int()]++;
  }
  for(i=(0);i<(100000+1);i++){
    if(cnt[i] >= 8){
      d8++;
      continue;
    }
    if(cnt[i] >= 6){
      d6++;
      continue;
    }
    if(cnt[i] >= 4){
      d4++;
      continue;
    }
    if(cnt[i] >= 2){
      d2++;
      continue;
    }
  }
  int xr20shxY = rd_int();
  for(FmcKpFmN=(0);FmcKpFmN<(xr20shxY);FmcKpFmN++){
    rd(c);
    rd(x);
    if(c=='-'){
      if(cnt[x]==8){
        d8--;
        d6++;
      }
      if(cnt[x]==6){
        d6--;
        d4++;
      }
      if(cnt[x]==4){
        d4--;
        d2++;
      }
      if(cnt[x]==2){
        d2--;
      }
      cnt[x]--;
    }
    else{
      cnt[x]++;
      if(cnt[x]==8){
        d8++;
        d6--;
      }
      if(cnt[x]==6){
        d6++;
        d4--;
      }
      if(cnt[x]==4){
        d4++;
        d2--;
      }
      if(cnt[x]==2){
        d2++;
      }
    }
    if(d8 * 8 + d6 * 6 + d4 * 4 + d2 * 2 >= 8 && d8 + d6 + d4 >= 1){
      wt_L("YES");
      wt_L('\n');
    }
    else{
      wt_L("NO");
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int cnt[1d5+1];
// int d8, d6, d4, d2;
// {
//   char c;
//   int x;
//   REP(rd_int()) cnt[rd_int()]++;
//   rep(i,1d5+1){
//     if(cnt[i] >= 8) d8++, continue;
//     if(cnt[i] >= 6) d6++, continue;
//     if(cnt[i] >= 4) d4++, continue;
//     if(cnt[i] >= 2) d2++, continue;
//   }
//   REP(rd_int()){
//     rd(c,x);
//     if(c=='-'){
//       if(cnt[x]==8) d8--, d6++;
//       if(cnt[x]==6) d6--, d4++;
//       if(cnt[x]==4) d4--, d2++;
//       if(cnt[x]==2) d2--;
//       cnt[x]--;
//     } else {
//       cnt[x]++;
//       if(cnt[x]==8) d8++, d6--;
//       if(cnt[x]==6) d6++, d4--;
//       if(cnt[x]==4) d4++, d2--;
//       if(cnt[x]==2) d2++;
//     }
//     wt(if[d8 * 8 + d6 * 6 + d4 * 4 + d2 * 2 >= 8 && d8 + d6 + d4 >= 1, "YES", "NO"]);
//   }
// }