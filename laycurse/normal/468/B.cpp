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

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

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

#define INF 2000000000LL

int N, A, B;
int P[200000];
int res[200000];
int inv[200000];
ullHash<int> inA, inB, place, cnt;
int dame;

int docheck[1000000], dosz;

int isCan(int ind, int st){
  int tar, all, used;
  if(st==0){
    tar = A - P[ind];
  } else {
    tar = B - P[ind];
  }
  if(tar <= 0) return 0;
  if(tar == P[ind]) return 1;

  if(st==0 && inA.get(tar)) return 1;
  if(st==1 && inB.get(tar)) return 1;

  all = cnt.get(tar);
  used = inA.get(tar) + inB.get(tar);
  if(all > used) return 1;
  return 0;
}

int next_ind(int v){
  int used = inA.get(v) + inB.get(v);
  return place.get(INF*(used+1)+v) - 1;
}

int main(){
  int i, j, k;
  int fgA, fgB;
  int used, cur, tar, tt, ccc;

  reader(&N,&A,&B);
  rep(i,N) reader(P+i);

  rep(i,N) res[i] = -1;

  inA.init(200000, 200000);
  inB.init(200000, 200000);
  place.init(200000, 200000);
  cnt.init(200000, 200000);

  rep(i,N){
    k = cnt.increase(P[i]);
    inv[i] = k;
    place.set(INF*k+P[i], i+1);
  }

  dosz = 0;
  rep(i,N) docheck[dosz++] = i;
  while(dosz){
    i = docheck[--dosz];

    if(res[i] >= 0) continue;

    used = inA.get(P[i]) + inB.get(P[i]);
    ccc = inv[i];
    if(used + 1 != ccc) continue;
    
    fgA = isCan(i, 0);
    fgB = isCan(i, 1);
    if(fgA && fgB) continue;
    if(!fgA && !fgB){ dame=1; break; }

    if(fgA){
      res[i] = 0; used++;
      inA.increase(P[i]);
      tar = A - P[i];
      if(inA.get(tar)==0){
        j = next_ind(tar);
        inA.increase(P[j]);
        res[j] = 0;
        tt = B - tar;
        k = next_ind(tt);
        if(tt >= 0) docheck[dosz++] = k;
      }
      j = next_ind(P[i]);
      if(j >= 0) docheck[dosz++] = j;
    } else {
      res[i] = 1; used++;
      inB.increase(P[i]);
      tar = B - P[i];
      if(inB.get(tar)==0){
        j = next_ind(tar);
        inB.increase(P[j]);
        res[j] = 1;
        tt = A - tar;
        k = next_ind(tt);
        if(tt >= 0) docheck[dosz++] = k;
      }
      j = next_ind(P[i]);
      if(j >= 0) docheck[dosz++] = j;
    }
  }
  rep(i,N) if(res[i]==-1) res[i] = 0;

  if(dame){
    puts("NO");
  } else {
    puts("YES");
    rep(i,N) printf("%d%c",res[i],i==N-1?'\n':' ');
  }
  
  myed;
  return 0;
}