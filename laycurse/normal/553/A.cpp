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

int get_inv(ll a, int md){ll t=a,s=md,u=1,v=0,e;while(s){e=t/s;t-=e*s;u-=e*v;swap(t,s);swap(u,v);}if(u<0)u+=md;return u;}
struct combination{
  int *f,*v,m,s;unsigned **d;
  void* init(void *mem, int md, int lim=1000100, int small=0){int i,j;m=md;s=small;f=(int*)mem;v=f+lim;d=(unsigned**)(v+lim);d[0]=(unsigned*)(d+s);REP(i,1,s)d[i]=d[i-1]+s;mem=(void*)(d[0]+s*s);if(lim){f[0]=1;REP(i,1,lim)f[i]=(ll)f[i-1]*i%m;v[lim-1]=get_inv(f[lim-1],m);for(i=lim-1;i;i--)v[i-1]=(ll)v[i]*i%m;}REP(i,1,s)d[0][i]=0;rep(i,s)d[i][0]=1;REP(i,1,s)REP(j,1,s){d[i][j]=d[i-1][j-1]+d[i-1][j];if(d[i][j]>=m)d[i][j]-=m;}return mem;}
  ll C(int a, int b){if(b<0||b>a)return 0;if(a<s)return d[a][b];return (ll)f[a]*v[b]%m*v[a-b]%m;}
  ll P(int a, int b){if(b<0||b>a)return 0;return (ll)f[a]*v[a-b]%m;}
  ll H(int a, int b){if(a==0&&b==0)return 1;if(a<=0||b<0)return 0;return C(a+b-1,b);}
};


int N, A[10000];

int main(){
  int i, j, k;
  combination comb;
  int now;
  ll res = 1;

  comb.init(mem, MD);

  reader(&N);
  rep(i,N) reader(A+i);

  now = 1;
  rep(i,N){
    res *= comb.H(now, A[i]-1);
    res %= MD;
    now += A[i];
  }

  writerLn(res);

  return 0;
}