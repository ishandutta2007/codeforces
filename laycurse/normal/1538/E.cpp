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
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
int node;
string x;
string op;
string a;
string tmp;
string b;
map<string,int> mp;
long long cnt[200];
string sf[200];
string se[200];
int getid(string s){
  if(mp.count(s)){
    return mp[s];
  }
  return mp[s] = node++;
}
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int cTE1_r3A;
    int i;
    int j;
    int k;
    int ii;
    int jj;
    long long ctmp;
    string tf;
    string te;
    node = 0;
    mp.clear();
    int RZTsC2BF = rd_int();
    for(cTE1_r3A=(0);cTE1_r3A<(RZTsC2BF);cTE1_r3A++){
      rd(x);
      rd(op);
      rd(a);
      if(op=="="){
        rd(tmp);
        rd(b);
      }
      if(op==":="){
        i = getid(x);
        ctmp = 0;
        tf = te = a;
        if(tf.size() >= 4){
          tf = tf.substr(0,3);
        }
        if(te.size() >= 4){
          te = te.substr(te.size()-3);
        }
        for(ii=(3);ii<(a.size());ii++){
          if(a.substr(ii-3,4) == "haha"){
            ctmp++;
          }
        }
      }
      else{
        i = getid(x);
        j = getid(a);
        k = getid(b);
        ctmp = cnt[j] + cnt[k];
        tf = sf[j] + sf[k];
        te = se[j] + se[k];
        if(tf.size() >= 4){
          tf = tf.substr(0,3);
        }
        if(te.size() >= 4){
          te = te.substr(te.size()-3);
        }
        for(ii=(1);ii<(4);ii++){
          jj = 4 - ii;
          if(se[j].size() < ii){
            continue;
          }
          if(sf[k].size() < jj){
            continue;
          }
          if(se[j].substr(se[j].size() - ii) + sf[k].substr(0,jj) == "haha"){
            ctmp++;
          }
        }
      }
      cnt[i] = ctmp;
      sf[i] = tf;
      se[i] = te;
    }
    wt_L(ctmp);
    wt_L('\n');
  }
  return 0;
}
// cLay version 20210607-1

// --- original code ---
// //no-unlocked
// int node;
// string x, op, a, tmp, b;
// map<string,int> mp;
// 
// ll cnt[200]; string sf[200], se[200];
// 
// int getid(string s){
//   if(mp.count(s)) return mp[s];
//   return mp[s] = node++;
// }
// 
// {
//   REP(rd_int()){
//     int i, j, k, ii, jj;
//     ll ctmp; string tf, te;
//     node = 0;
//     mp.clear();
// 
//     // puts("hoge");
//     REP(rd_int()){
//       rd(x,op,a);
//       if(op=="=") rd(tmp,b);
// 
//       // wt("reader",x,op,a,tmp,b);
// 
//       if(op==":="){
//         i = getid(x);
//         // wt("id",i,x);
//         ctmp = 0;
//         tf = te = a;
//         if(tf.size() >= 4) tf = tf.substr(0,3);
//         if(te.size() >= 4) te = te.substr(te.size()-3);
//         rep(ii,3,a.size()) if(a.substr(ii-3,4) == "haha") ctmp++;
//       } else {
//         i = getid(x);
//         j = getid(a);
//         k = getid(b);
//         // wt("ids",i,j,k,x,a,b);
//         ctmp = cnt[j] + cnt[k];
//         tf = sf[j] + sf[k];
//         te = se[j] + se[k];
//         if(tf.size() >= 4) tf = tf.substr(0,3);
//         if(te.size() >= 4) te = te.substr(te.size()-3);
//         rep(ii,1,4){
//           jj = 4 - ii;
//           if(se[j].size() < ii) continue;
//           if(sf[k].size() < jj) continue;
//           if(se[j].substr(se[j].size() - ii) + sf[k].substr(0,jj) == "haha") ctmp++;
//         }
//       }
//       cnt[i] = ctmp;
//       sf[i] = tf;
//       se[i] = te;
//       // wt(i,":",ctmp,tf,te);
//     }
//     wt(ctmp);
//   }
// }