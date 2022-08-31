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

struct llModMatrix{
  int r, c, mod; ll limit; ll **data;
  ll* operator[](int a){return data[a];}
  void malloc(int r, int c, int mod){int i;this->r=r;this->c=c;this->mod=mod;limit=((1ULL<<63)-1)-(ull)(mod-1)*(mod-1);data=(ll**)std::malloc(sizeof(ll*)*r);data[0]=(ll*)std::malloc(sizeof(ll)*r*c);REP(i,1,r)data[i]=data[i-1]+c;}
  void* malloc(int r, int c, int mod, void *workMemory){int i;this->r=r;this->c=c;this->mod=mod;limit=((1ULL<<63)-1)-(ull)(mod-1)*(mod-1);data=(ll**)workMemory;data[0]=(ll*)(data+r);REP(i,1,r)data[i]=data[i-1]+c;return (void*)(data[0]+r*c);}
  void free(void){std::free(data[0]);std::free(data);}
  void setIdentity(){int i,j;rep(i,r)rep(j,c){data[i][j]=0;if(i==j)data[i][j]=1;}}
  void setZero(){int i,j;rep(i,r)rep(j,c)data[i][j]=0;}
  void operator=(llModMatrix &a){int i,j;r=a.r;c=a.c;rep(i,r)rep(j,c)data[i][j]=a.data[i][j];}
  void operator+=(llModMatrix &a){int i,j;rep(i,r)rep(j,c){data[i][j]+=a.data[i][j];if(data[i][j]>=mod)data[i][j]-=mod;if(data[i][j]<=-mod)data[i][j]+=mod;}}
  void operator-=(llModMatrix &a){int i,j;rep(i,r)rep(j,c){data[i][j]-=a.data[i][j];if(data[i][j]>=mod)data[i][j]-=mod;if(data[i][j]<=-mod)data[i][j]+=mod;}}
  void mixed(void){int i,j;rep(i,r)rep(j,c){if(data[i][j]<0)data[i][j]+=mod;if(data[i][j]&&rand()%2)data[i][j]-=mod;}}
  void add(llModMatrix &a, llModMatrix &b){int i,j;r=a.r;c=a.c;rep(i,r)rep(j,c){data[i][j]=a.data[i][j]+b.data[i][j];if(data[i][j]>=mod)data[i][j]-=mod;if(data[i][j]<=-mod)data[i][j]+=mod;}}
  void sub(llModMatrix &a, llModMatrix &b){int i,j;r=a.r;c=a.c;rep(i,r)rep(j,c){data[i][j]=a.data[i][j]-b.data[i][j];if(data[i][j]>=mod)data[i][j]-=mod;if(data[i][j]<=-mod)data[i][j]+=mod;}}
  void mul(llModMatrix &a, llModMatrix &b){int i,j,k;r=a.r;c=b.c;setZero();rep(i,r)rep(k,a.c)if(a.data[i][k])rep(j,c){data[i][j]+=a.data[i][k]*b.data[k][j];if(data[i][j]>=limit||data[i][j]<=-limit)data[i][j]%=mod;}rep(i,r)rep(j,c)if(data[i][j]>=mod||data[i][j]<=-mod)data[i][j]%=mod;}
  void pow(llModMatrix &a, ull b, void *workMemory){llModMatrix t1,t2;r=c=a.r;workMemory=t1.malloc(r,c,mod,workMemory);workMemory=t2.malloc(r,c,mod,workMemory);setIdentity();t1=a;while(b){if(b%2){t2=*this;this->mul(t2,t1);}t2.mul(t1,t1);t1=t2;b/=2;}}
};

int N, B, K, X;

int main(){
  int i, j, k;
  llModMatrix mt, pw;

  reader(&N,&B,&K,&X);
  mem = mt.malloc(X, X, MD, mem);
  mem = pw.malloc(X, X, MD, mem);

  mt.setZero();
  while(N--){
    reader(&j);
    rep(i,X) mt[i][(10*i+j)%X]++;
  }
  pw.pow(mt,B,mem);
  writerLn(pw[0][K]);

  return 0;
}