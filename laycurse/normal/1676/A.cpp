#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
void*wmem;
char memarr[96000000];
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
inline void rd(string &x){
  char*buf = (char *)wmem;
  rd(buf);
  x = buf;
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
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
int main(){
  int Nzj9Y0kE;
  wmem = memarr;
  int bkxOPzPX = rd_int();
  for(Nzj9Y0kE=(0);Nzj9Y0kE<(bkxOPzPX);Nzj9Y0kE++){
    string S;
    rd(S);
    int om7Ebh6q;
    remove_reference<decltype(S[om7Ebh6q]-'0')>::type bs24PFPc;
    int R5MtCiij = 0;
    if((0) > ((3)-1)){
      bs24PFPc = 0;
    }
    else{
      for(om7Ebh6q = 0; om7Ebh6q <= (3)-1; om7Ebh6q++){
        if(R5MtCiij == 0){
          bs24PFPc = S[om7Ebh6q]-'0';
          R5MtCiij = 1;
          continue;
        }
        bs24PFPc += S[om7Ebh6q]-'0';
      }
      if(R5MtCiij==0){
        bs24PFPc = 0;
      }
    }
    int x = bs24PFPc;
    int wbH8AaCb;
    remove_reference<decltype(S[3+wbH8AaCb]-'0')>::type QBN4sCMC;
    int lmouyaID = 0;
    if((0) > ((3)-1)){
      QBN4sCMC = 0;
    }
    else{
      for(wbH8AaCb = 0; wbH8AaCb <= (3)-1; wbH8AaCb++){
        if(lmouyaID == 0){
          QBN4sCMC = S[3+wbH8AaCb]-'0';
          lmouyaID = 1;
          continue;
        }
        QBN4sCMC += S[3+wbH8AaCb]-'0';
      }
      if(lmouyaID==0){
        QBN4sCMC = 0;
      }
    }
    int y = QBN4sCMC;
    if(x==y){
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
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}
// cLay version 20220506-1

// --- original code ---
// //no-unlocked
// REP(rd_int()){
//   string @S;
//   int x = sum[i,0,3](S[i]-'0');
//   int y = sum[i,0,3](S[3+i]-'0');
//   wt(if[x==y, "YES", "NO"]);
// }