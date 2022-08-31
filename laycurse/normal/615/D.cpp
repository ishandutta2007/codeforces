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
  void setmod(unsigned m){int i;unsigned t;W=32;md=m;R=(1ULL<<W)%md;RR=(ull)R*R%md;switch(m){case 104857601:Rinv=2560000;mdninv=104857599;break;case 998244353:Rinv=232013824;mdninv=998244351;break;case 1000000007:Rinv=518424770;mdninv=2226617417U;break;case 1000000009:Rinv=171601999;mdninv=737024967;break;case 1004535809:Rinv=234947584;mdninv=1004535807;break;case 1007681537:Rinv=236421376;mdninv=1007681535;break;case 1012924417:Rinv=238887936;mdninv=1012924415;break;case 1045430273:Rinv=254466304;mdninv=1045430271;break;case 1051721729:Rinv=257538304;mdninv=1051721727;break;default:Rinv=get_inv(R,md);mdninv=0;t=0;rep(i,W){if(t%2==0)t+=md,mdninv|=(1U<<i);t/=2;}}}
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
  bool operator==(int a){return get()==a;}
  bool operator!=(int a){return get()!=a;}
};
unsigned mint::md, mint::W, mint::R, mint::Rinv, mint::mdninv, mint::RR;
mint operator+(int a, mint b){return mint(a)+=b;}mint operator-(int a, mint b){return mint(a)-=b;}mint operator*(int a, mint b){return mint(a)*=b;}mint operator/(int a, mint b){return mint(a)/=b;}
mint operator+(ll a, mint b){return mint(a)+=b;}mint operator-(ll a, mint b){return mint(a)-=b;}mint operator*(ll a, mint b){return mint(a)*=b;}mint operator/(ll a, mint b){return mint(a)/=b;}

mint mval[10000], minv[10000];
void mint_init(int md=MD, mint val[]=mval, int vals=10000, mint inv[]=minv, int invs=10000){int i;val[0].setmod(md);val[0].val=0;REP(i,1,vals){val[i].val=val[i-1].val+mint::R;if(val[i].val >=md)val[i].val-=md;}inv[1].val=1;REP(i,2,invs){inv[i].val=md-((ll)(md/i)*inv[md%i].val%md);}REP(i,1,invs)inv[i].val=(ull)inv[i].val*mint::R%md;}

template<class T> void sort(int N, T a[], void *mem = NULL){sort(a,a+N);}
template<class T1, class T2> void sort(int N, T1 a[], T2 b[], void *mem){int i;pair<T1,T2> *r=(pair<T1, T2>*)mem;rep(i,N)r[i].first=a[i],r[i].second=b[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second;}
template<class T1, class T2, class T3> void sort(int N, T1 a[], T2 b[], T3 c[], void *mem){int i;pair<T1,pair<T2,T3> > *r=(pair<T1,pair<T2,T3> >*)mem;rep(i,N)r[i].first=a[i],r[i].second.first=b[i],r[i].second.second=c[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second.first,c[i]=r[i].second.second;}
template<class T1, class T2, class T3, class T4> void sort(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem){int i;pair<pair<T1,T2>,pair<T3,T4> > *r=(pair<pair<T1,T2>,pair<T3,T4> >*)mem;rep(i,N)r[i].first.first=a[i],r[i].first.second=b[i],r[i].second.first=c[i],r[i].second.second=d[i];sort(r,r+N);rep(i,N)a[i]=r[i].first.first,b[i]=r[i].first.second,c[i]=r[i].second.first,d[i]=r[i].second.second;}

template<class T> void unique(T arr[], int &sz, int sorted=0){int i,k=0;if(!sorted)sort(arr,arr+sz);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k++]=arr[i];sz=k;}
template<class T, class S> void unique(T arr[], S val[], int &sz, void *mem, int sorted=0){int i,k=0;if(!sorted)sort(sz,arr,val,mem);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k]=arr[i],val[k++]=val[i];else val[k-1] += val[i];sz=k;}
template<class T, class S, class V> void unique(T arr[], S v1[], V v2[], int &sz, void *mem, int sorted=0){int i,k=0;if(!sorted)sort(sz,arr,v1,v2,mem);rep(i,sz)if(!k||arr[k-1]!=arr[i])arr[k]=arr[i],v1[k]=v1[i],v2[k++]=v2[i];else v1[k-1] += v1[i],v2[k-1] += v2[i];sz = k;}


int M, P[220000], cnt[220000];

int main(){
  int i, j, k;
  ull num;
  mint res, tmp, mul, tt;

  mint_init();

  reader(&M);
  rep(i,M) reader(P+i);
  rep(i,M) cnt[i] = 1;
  unique(P, cnt, M, mem);

  res = mval[1];
  num = 1;
  rep(i,M){
    tmp = mval[1];
    mul = mval[1];
    rep(j,cnt[i]+1){
      tmp *= mul;
      mul *= P[i];
    }
    res = res.pw(cnt[i]+1) * tmp.pw(num);
    num = num * (cnt[i]+1) % (MD-1);
  }

  writerLn((int)res);
  
  return 0;
}