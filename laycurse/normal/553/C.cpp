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

struct mint{
  static unsigned md, W, R, Rinv, mdninv, RR;
  unsigned val;

  mint(){}mint(int a){val=mulR(a);}mint(unsigned a){val=mulR(a);}mint(ll a){val=mulR(a);}mint(ull a){val=mulR(a);}
  unsigned setmod(unsigned m){int i;unsigned t;W=32;md=m;R=(1ULL<<W)%md;RR=(ull)R*R%md;switch(m){case 104857601:Rinv=2560000;mdninv=104857599;break;case 998244353:Rinv=232013824;mdninv=998244351;break;case 1000000007:Rinv=518424770;mdninv=2226617417U;break;case 1000000009:Rinv=171601999;mdninv=737024967;break;case 1004535809:Rinv=234947584;mdninv=1004535807;break;case 1007681537:Rinv=236421376;mdninv=1007681535;break;case 1012924417:Rinv=238887936;mdninv=1012924415;break;case 1045430273:Rinv=254466304;mdninv=1045430271;break;case 1051721729:Rinv=257538304;mdninv=1051721727;break;default:Rinv=get_inv(R,md);mdninv=0;t=0;rep(i,W){if(t%2==0)t+=md,mdninv|=(1U<<i);t/=2;}}}
  unsigned mulR(unsigned a){return(ull)a*R%md;}unsigned mulR(int a){if(a<0)a=a%md+md;return mulR((unsigned)a);}unsigned mulR(ull a){return mulR((unsigned)(a%md));}unsigned mulR(ll a){if(a<0)a=a%md+md;return mulR((unsigned)a);}
  unsigned reduce(unsigned T){unsigned m=T*mdninv;unsigned t=(unsigned)((T+(ull)m*md)>>W);if(t>=md)t-=md;return t;}unsigned reduce(ull T){unsigned m=(unsigned)T*mdninv;unsigned t=(unsigned)((T+(ull)m*md)>>W);if(t>=md)t-=md;return t;}
  unsigned get(){return reduce(val);}
  mint&operator+=(mint a){val+=a.val;if(val>=md)val-=md;return*this;}mint&operator-=(mint a){if(val<a.val)val=val+md-a.val;else val-=a.val;return*this;}mint&operator*=(mint a){val=reduce((ull)val*a.val);return*this;}mint&operator/=(mint a){return*this*=a.inverse();}
  mint operator+(mint a){return mint(*this)+=a;}mint operator-(mint a){return mint(*this)-=a;}mint operator*(mint a){return mint(*this)*=a;}mint operator/(mint a){return mint(*this)/=a;}
  mint operator+(int a){return mint(*this)+=mint(a);}mint operator-(int a){return mint(*this)-=mint(a);}mint operator*(int a){return mint(*this)*=mint(a);}mint operator/(int a){return mint(*this)/=mint(a);}
  mint operator+(ll a){return mint(*this)+=mint(a);}mint operator-(ll a){return mint(*this)-=mint(a);}mint operator*(ll a){return mint(*this)*=mint(a);}mint operator/(ll a){return mint(*this)/=mint(a);}
  mint operator-(void){mint res;if(val)res.val=md-val;else res.val=0;return res;}
  operator bool(void){return val!=0;}operator int(void){return get();}operator ll(void){return get();}
  mint inverse(){int a=val,b=md,u=1,v=0,t;mint r;while(b){t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}if(u<0)u+=md;r.val=(ull)u*RR%md;return r;}
  mint pw(ull b){mint a(*this),r;r.val=R;while(b){if(b&1)r*=a;b>>=1;a*=a;}return r;}
};
unsigned mint::md, mint::W, mint::R, mint::Rinv, mint::mdninv, mint::RR;
mint operator+(int a, mint b){return mint(a)+=b;}mint operator-(int a, mint b){return mint(a)-=b;}mint operator*(int a, mint b){return mint(a)*=b;}mint operator/(int a, mint b){return mint(a)/=b;}
mint operator+(ll a, mint b){return mint(a)+=b;}mint operator-(ll a, mint b){return mint(a)-=b;}mint operator*(ll a, mint b){return mint(a)*=b;}mint operator/(ll a, mint b){return mint(a)/=b;}

mint mval[10000], minv[10000];
void mint_init(int md=MD, mint val[]=mval, int vals=10000, mint inv[]=minv, int invs=10000){int i;val[0].setmod(md);val[0].val=0;REP(i,1,vals){val[i].val=val[i-1].val+mint::R;if(val[i].val >=md)val[i].val-=md;}inv[1].val=1;REP(i,2,invs){inv[i].val=md-((ll)(md/i)*inv[md%i].val%md);}REP(i,1,invs)inv[i].val=(ull)inv[i].val*mint::R%md;}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}


int N, M;

int ind[200000];
int cnt[200000];

int main(){
  int i, j, k;
  mint res;

  mint_init();

  reader(&N,&M);
  unionInit(ind, 2*N);
  while(M--){
    reader(&i,&j,&k);
    i--; j--;
    if(k==1) unionConnect(ind, i, j), unionConnect(ind, i+N, j+N);
    if(k==0) unionConnect(ind, i, j+N), unionConnect(ind, i+N, j);
  }

  rep(i,N) if(unionGet(ind,i)==unionGet(ind,i+N)) break;
  if(i<N){ writerLn(0); return 0; }

  rep(i,2*N) cnt[unionGet(ind,i)] = 1;
  k = 0;
  rep(i,2*N) k += cnt[i];

  res = mval[2].pw(k/2-1);
  writerLn((int)res);

  return 0;
}