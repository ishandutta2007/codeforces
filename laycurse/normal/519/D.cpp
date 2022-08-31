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

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

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

int N;
int X[26];
ll sum[110000];
char S[110000];

int main(){
  int i, j, k;
  ll res = 0;
  ullHash<int> hs;

  rep(i,26) reader(X+i);
  N = reader(S);

  sum[0] = 0;
  rep(i,N) sum[i+1] = sum[i] + X[S[i]-'a'];

  hs.init(150000, 150000);
  rep(k,26){
    hs.clear(150000);
    rep(i,N) if(S[i]=='a'+k){
      res += hs.get(sum[i]-X[k]);
      hs.increase(sum[i]);
    }
  }

  writerLn(res);

  return 0;
}