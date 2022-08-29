#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

template<class T>
struct ullHash{
  ull *key; T *val; unsigned memory, size, mask;

  void clear(){memset(val,0,size*sizeof(T));}
  void clear(int sz){size=1;while(size<sz)size*=2;mask=size-1;clear();}
  void init(int mem, int sz){memory=mem;size=1;while(size<sz)size*=2;mask=size-1;if(memory<size)memory=size;key=(ull*)malloc(memory*sizeof(ull));val=(T*)malloc(memory*sizeof(T));if(size)clear();}
  int function(ull a){return (((a*123456789789ULL)>>32)*987654321321ULL)&mask;}
  T get(ull a){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;if(key[i]!=a) return 0;return val[i];}
  void set(ull a, T v){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;val[i]=v;}
  T increase(ull a, T v = 1){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;return val[i]+=v;}
};

char memarr[17000000]; void *mem = memarr;
#define INF 1000000000

int N, n1, n2;
int L[33], M[33], W[33];

int pw[22];
int dL[2][1600000], dM[2][1600000], dW[2][1600000];

int opt, res1, res2;

int main(){
  int i, j, k, m;
  ull hs;
  ullHash<int> hash;

  hash.init(1000000, 1000000);

  pw[0] = 1;
  REP(i,1,22) pw[i] = pw[i-1] * 3;

  reader(&N);
  rep(i,N) reader(L+i,M+i,W+i);

  n1 = (N+1)/2;
  n2 = N/2;

  rep(i,pw[n1]){
    rep(j,n1){
      m = i / pw[j] % 3;
      if(m!=0) dL[0][i] += L[j];
      if(m!=1) dM[0][i] += M[j];
      if(m!=2) dW[0][i] += W[j];
    }
  }

  rep(i,pw[n2]){
    rep(j,n2){
      m = i / pw[j] % 3;
      if(m!=0) dL[1][i] += L[n1+j];
      if(m!=1) dM[1][i] += M[n1+j];
      if(m!=2) dW[1][i] += W[n1+j];
    }
  }

  opt = -INF;
  rep(i,pw[n2]){
    hs = (dM[1][i] - dL[1][i] + INF/2) + (ull)(dW[1][i] - dL[1][i] + INF/2) * INF;
    k = hash.get(hs) - 1;
    if(k >= 0 && dL[1][k] >= dL[1][i]) continue;
    hash.set(hs, i+1);
  }

  rep(i,pw[n1]){
    hs = (dL[0][i] - dM[0][i] + INF/2) + (ull)(dL[0][i] - dW[0][i] + INF/2) * INF;
    k = hash.get(hs) - 1;
    if(k == -1) continue;
    if(opt < dL[0][i] + dL[1][k]){
      opt = dL[0][i] + dL[1][k];
      res1 = i; res2 = k;
    }
  }

  if(opt==-INF){
    writerLn("Impossible");
    return 0;
  }

  rep(j,n1){
    m = res1 / pw[j] % 3;
    if(m==0) writerLn("MW");
    if(m==1) writerLn("LW");
    if(m==2) writerLn("LM");
  }
  rep(j,n2){
    m = res2 / pw[j] % 3;
    if(m==0) writerLn("MW");
    if(m==1) writerLn("LW");
    if(m==2) writerLn("LM");
  }

  return 0;
}