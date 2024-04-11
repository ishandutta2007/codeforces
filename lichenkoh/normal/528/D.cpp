#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
const double pi=acos(-1);
const int mxn=1<<18;
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x;y=_y;}
  point operator+(const point &t)const{return point(x+t.x,y+t.y);}
  point operator-(const point &t)const{return point(x-t.x,y-t.y);}
  point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
  point operator*(const double &t)const{return point(x*t,y*t);}
};
point makeunit(double x){return point(cos(x),sin(x));}
int sz=0;
point w[mxn*2+1];
void init(int n)
{
  if(sz==n)return;
  sz=1;
  while(sz<n)sz<<=1;
  w[0]=point(1,0);
  point tw=makeunit(2*pi/sz);
  for(int i=1;i<=sz;i++)w[i]=w[i-1]*tw;
}
void FFT(point a[],bool rev)
{
  for(int i=0,j=0;i<sz;i++)
  {
    if(i>j)swap(a[i],a[j]);
    for(int l=sz>>1;(j^=l)<l;l>>=1);
  }
  for(int l=1;l<sz;l<<=1)
  {
    int l2=l<<1;
    for(int i=0;i<sz;i+=l2)
    {
      for(int j=0;j<l;j++)
      {
        point t=a[i+j+l]*w[rev?sz-sz/l2*j:sz/l2*j];
        a[i+j+l]=a[i+j]-t;
        a[i+j]=a[i+j]+t;
      }
    }
  }
  if(rev)for(int i=0;i<sz;i++)a[i]=a[i]*(1.0/sz);
}


char s[mxn],t[mxn];
point a[mxn],b[mxn];
char CT[4]={'A','T','G','C'};
int final[mxn];
int cnt[mxn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int sn,tn,k; scanf("%d %d %d\n%s\n%s\n",&sn,&tn,&k,s,t);
  init(mxn);
  for (int ch=0;ch<4;ch++) {
    char c=CT[ch];
    memset(cnt,0,sizeof cnt);
    for (int i=0;i<sn;i++) {
      if (s[i]==c) {
        int l=max(0,i-k);
        int r=min(sn,i+k+1);
        //printf("c:%c l:%d r:%d\n",c,l,r);
        cnt[l]++;
        cnt[r]--;
      }
    }
    memset(a,0,sizeof a);
    int lcnt=0;
    for (int i=0;i<sn;i++) {
      lcnt+=cnt[i];
      if (lcnt>0) {
        a[i].x=1;
        //printf("c:%c i:%d a:%f\n",c,i,a[i].x);
      }
    }
    memset(b,0,sizeof b);
    int want=0;
    for (int i=0;i<tn;i++) {
      if (t[tn-1-i]==c) {
        want++;
        b[i].x=1;
        //printf("c:%c i:%d b:%f\n",c,i,b[i].x);
      }
    }
    FFT(a,false);
    FFT(b,false);
    for (int i=0;i<mxn;i++) a[i]=a[i]*b[i];
    FFT(a,true);
    for (int i=0;i<mxn;i++) {
      if ((a[i].x+0.5)>=want) {
        final[i]|=1<<ch;
      }
    }
  }
  int finalans=0;
  for (int i=0;i<mxn;i++) {
    if (final[i]==(1<<4)-1) finalans++;
  }
  printf("%d\n",finalans);
}