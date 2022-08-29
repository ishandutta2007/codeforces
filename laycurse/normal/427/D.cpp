#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t') break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t') break;c[s++]=i;}return s;}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

#define ll long long
#define ull unsigned ll

template<class T>
struct ullHash{
  ull *key; T *val; unsigned memory, size, mask;

  void clear(){memset(val,0,size*sizeof(T));}
  void clear(int sz){size=1;while(size<sz)size*=2;mask=size-1;clear();}
  void init(int mem, int sz){memory=mem;size=1;while(size<sz)size*=2;mask=size-1;if(memory<size)memory=size;key=(ull*)malloc(memory*sizeof(ull));val=(T*)malloc(memory*sizeof(T));if(size)clear();}
  int function(ull a){return (a*97531)&mask;}
  T get(ull a){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;if(key[i]!=a) return 0;return val[i];}
  void set(ull a, T v){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;val[i]=v;}
  T increase(ull a, T v = 1){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;return val[i]+=v;}
};


#define D 13579
ull pw[5010];

int main(){
  char a[10000], b[10000]; int as, bs;
  int i, j, k, res;
  ullHash<int> hash;
  ull hs;

  hash.init(16000, 16000);

  pw[0] = 1;
  REP(i,1,5010) pw[i] = pw[i-1] * D;

  as = reader(a);
  bs = reader(b);

  res = -1;
  REP(k,1,as+1){
    if(k > bs) break;
    hash.clear();

    hs = 0;
    rep(i,k) hs = hs * D + a[i];
    hash.increase(hs);
    REP(i,k,as){
      hs = hs * D + a[i] - pw[k] * a[i-k];
      hash.increase(hs);
    }

    hs = 0;
    rep(i,k) hs = hs * D + b[i];
    hash.increase(hs, 10000);
    REP(i,k,bs){
      hs = hs * D + b[i] - pw[k] * b[i-k];
      hash.increase(hs, 10000);
    }

    hs = 0;
    rep(i,k) hs = hs * D + a[i];
    if(hash.get(hs)==10001){ res = k; break; }
    REP(i,k,as){
      hs = hs * D + a[i] - pw[k] * a[i-k];
      if(hash.get(hs)==10001){ res = k; break; }
    }
    if(res != -1) break;
  }

  writer(res, '\n');

  myed;
  return 0;
}