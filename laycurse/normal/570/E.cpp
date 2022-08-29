#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}

char memarr[47000000]; void *mem = memarr;
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
  bool operator==(int a){return get()==a;}
  bool operator!=(int a){return get()!=a;}
};
unsigned mint::md, mint::W, mint::R, mint::Rinv, mint::mdninv, mint::RR;
mint operator+(int a, mint b){return mint(a)+=b;}mint operator-(int a, mint b){return mint(a)-=b;}mint operator*(int a, mint b){return mint(a)*=b;}mint operator/(int a, mint b){return mint(a)/=b;}
mint operator+(ll a, mint b){return mint(a)+=b;}mint operator-(ll a, mint b){return mint(a)-=b;}mint operator*(ll a, mint b){return mint(a)*=b;}mint operator/(ll a, mint b){return mint(a)/=b;}

mint mval[10000], minv[10000];
void mint_init(int md=MD, mint val[]=mval, int vals=10000, mint inv[]=minv, int invs=10000){int i;val[0].setmod(md);val[0].val=0;REP(i,1,vals){val[i].val=val[i-1].val+mint::R;if(val[i].val >=md)val[i].val-=md;}inv[1].val=1;REP(i,2,invs){inv[i].val=md-((ll)(md/i)*inv[md%i].val%md);}REP(i,1,invs)inv[i].val=(ull)inv[i].val*mint::R%md;}

template<class T> void *malloc2d(T ***arr, int x, int y, void *mem){int i;(*arr)=(T**)mem;(*arr)[0]=(T*)((*arr)+x);REP(i,1,x)(*arr)[i]=(*arr)[i-1]+y;return((*arr)[x-1]+y);}

int X, Y;
char mp[555][555];

mint **dp, **nx;

int main(){
  int i, j, k, a, b, d;
  int x1, y1, x2, y2;
  int x11, y11, x22, y22;
  int step;
  mint res;

  mint_init();

  reader(&X,&Y);
  rep(i,X) reader(mp[i]);
  mem = malloc2d(&dp, X, X, mem);
  mem = malloc2d(&nx, X, X, mem);

  rep(i,X) rep(j,X) dp[i][j] = mval[0];
  rep(i,X) rep(j,X) nx[i][j] = mval[0];
  if(mp[0][0]==mp[X-1][Y-1]) dp[0][X-1] = mval[1];

  step = X+Y-2;
  for(k=0;k+1<step;k+=2){
    rep(x1,X) REP(x2,x1,X) if(dp[x1][x2].val){
      y1 = k/2 - x1;
      y2 = Y-1 - (k/2 - (X-1 - x2));
      rep(d,4){
        x11 = x1; x22 = x2;
        y11 = y1; y22 = y2;
        if(d<2) x11++; else y11++;
        if(d%2) x22--; else y22--;
        if(x11 >= X || x22 < 0) continue;
        if(y11 >= Y || y22 < 0) continue;
        if(mp[x11][y11] != mp[x22][y22]) continue;
        nx[x11][x22] += dp[x1][x2];
      }
      dp[x1][x2].val = 0;
    }

    swap(dp, nx);
  }

  res = mval[0];
  rep(i,X) res += dp[i][i];
  if(k==step-1){
    REP(i,1,X) res += dp[i-1][i];
  }

  writerLn( (int)res );

  return 0;
}