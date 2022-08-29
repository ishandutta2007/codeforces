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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

template<class T>
struct fenwick{
  int size, memory; T *data;
  void malloc(int mem){memory=mem;data=(T*)std::malloc(sizeof(T)*mem);}
  void *malloc(int mem, void *workMemory){memory=mem;data=(T*)workMemory;return (void*)(data+mem);}
  void free(void){memory=0;free(data);}
  void init(int N){size=N;memset(data,0,sizeof(T)*N);}
  void add(int k, T val){while(k<size)data[k]+=val,k|=k+1;}
  T get(int k){T res=0;while(k>=0)res+=data[k],k=(k&(k+1))-1;return res;}
  T range(int a, int b){if(b==-1)b=size-1;return get(b)-get(a-1);}
  int kth(T k){int i=0,j=size,c;T v;while(i<j){c=(i+j)/2;v=get(c);if(v<=k)i=c+1;else j=c;}return i==size?-1:i;}
};

int N;
int P[222222], Q[222222];

int res[222222];
int cnt[222222];

int main(){
  int i, j, k;
  void *mem = malloc(70000000);
  fenwick<int> t;

  reader(&N);
  rep(i,N) reader(P+i);
  rep(i,N) reader(Q+i);

  t.malloc(N);
  
  t.init(N);
  rep(i,N) t.add(i,1);
  rep(i,N){
    k = t.get(P[i]-1);
    cnt[N-1-i] += k;
    t.add(P[i], -1);
  }

  t.init(N);
  rep(i,N) t.add(i,1);
  rep(i,N){
    k = t.get(Q[i]-1);
    cnt[N-1-i] += k;
    t.add(Q[i], -1);
  }

  REP(i,1,N){
    cnt[i+1] += cnt[i] / (i+1);
    cnt[i] %= (i+1);
  }

  t.init(N);
  rep(i,N) t.add(i,1);
  rep(i,N){
    k = t.kth(cnt[N-i-1]);
    res[i] = k;
    t.add(k,-1);
  }

  writerArr(res,N);

  myed;
  return 0;
}