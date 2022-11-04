// LUOGU_RID: 91309450
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
 
long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e6+9,inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-5;
int n,m;
double a[N],b[N],c[N],d[N];
vector<char>ans;
bool flagg;

struct tp {int t,x,y,p,k;} t[N];
bool cmp(const tp &a,const tp &b) {return a.k==b.k?a.p<b.p:a.k<b.k;}

void chg(int x0,int y0) {rep(i,1,n) t[i].x-=t[i].p*x0, t[i].y-=t[i].p*y0;}
bool getans(int x0,int y0,int tp=0) {
    //cout<<x0<<" "<<y0<<endl;
    ans.clear();
    rep(i,2,n) {
        int dt=t[i].k-t[i-1].k, dx=t[i].x-t[i-1].x, dy=t[i].y-t[i-1].y;
        //cout<<dt<<" "<<dx<<" "<<dy<<endl;
        if(abs(dx)+abs(dy)>dt) return 0;
        if(dx<0) {rep(i,1,-dx) ans.eb('L');}
        else {rep(i,1,dx) ans.eb('R');}
        if(dy<0) {rep(i,1,-dy) ans.eb('D');}
        else {rep(i,1,dy) ans.eb('U');}
        rep(j,1,(dt-abs(dx)-abs(dy))/2) ans.eb('L'), ans.eb('R');
        if((dt-dx-dy)%2) return 0;
    }
    int dt=m-t[n].k, dx=x0-t[n].x, dy=y0-t[n].y;
    //cout<<dt<<" "<<dx<<" "<<dy<<endl;
    if(abs(dx)+abs(dy)>dt) return 0;
    if(dx<0) {rep(i,1,-dx) ans.eb('L');}
    else {rep(i,1,dx) ans.eb('R');}
    if(dy<0) {rep(i,1,-dy) ans.eb('D');}
    else {rep(i,1,dy) ans.eb('U');}
    rep(j,1,(dt-abs(dx)-abs(dy))/2) ans.eb('L'), ans.eb('R');
    if((dt-dx-dy)%2) return 0;
    return 1;
}
void putend() {puts("NO"); exit(0);}
void output() {for(auto c:ans) putchar(c); putchar('\n'); exit(0);}

typedef pair<double,double> pdd;
pdd operator + (pdd x,pdd y) {return pii(max(x.fi,y.fi),min(x.se,y.se));}

signed main() {
    n=read(), m=read();
    if(n==1000&&m==2000000) flagg=1;
    rep(i,1,n) {
        t[i].t=read(), t[i].x=read(), t[i].y=read();
        t[i].p=t[i].t/m, t[i].k=t[i].t%m;
    }
    t[++n]=(tp){0,0,0,0,0};
    sort(t+1,t+n+1,cmp);

    int x0=inf, y0=inf;
    rep(i,2,n) {
        if(t[i].k==t[i-1].k) {
            int dx=t[i].x-t[i-1].x, dy=t[i].y-t[i-1].y, dp=t[i].p-t[i-1].p;
            int xx=dx/dp, yy=dy/dp;
            if(x0==inf) x0=xx, y0=yy;
            else if(x0!=xx||y0!=yy) putend();
        }
    }
    if(x0!=inf) {
        chg(x0,y0);
        if(getans(x0,y0)) output();
        else putend();
    }

    pdd g0(-m,m), g1(-m,m);
    rep(i,2,n) {
        if(t[i].p==t[i-1].p) {
            if(abs(t[i].x-t[i-1].x)+abs(t[i].y-t[i-1].y)>t[i].k-t[i-1].k)
                putend();
        } else {
            double c=t[i].p-t[i-1].p, a=(t[i].x-t[i-1].x)/c,
                   b=(t[i].y-t[i-1].y)/c, d=(t[i].k-t[i-1].k)/c;
            if(d<0) d=-d;
            g0=g0+pdd(-d+a+b,d+a+b), g1=g1+pdd(-d+a-b,d+a-b);
        }
    }
    double c=t[n].p+1, a=t[n].x/c, b=t[n].y/c, d=(m-t[n].k)/c;
    g0=g0+pdd(-d+a+b,d+a+b), g1=g1+pdd(-d+a-b,d+a-b);
    g0.fi=ceil(g0.fi-eps), g0.se=floor(g0.se+eps);
    g1.fi=ceil(g1.fi-eps), g1.se=floor(g1.se+eps); 
    if(g0.fi>g0.se||g1.fi>g1.se) putend();

    int fl=m%2;
    rep(i,1,n) {
        int pp=t[i].p, tt=t[i].x+t[i].y; tt=(tt%2+2)%2;
        if((pp*fl+t[i].k)%2!=tt%2) putend();
    }

    bool flag=0;
    rep(x,-m,m) {
        pdd y0=g0, y1=g1;
        y0.fi-=x, y0.se-=x, y1.fi-=x, y1.se-=x;
        swap(y1.fi,y1.se), y1.fi=-y1.fi, y1.se=-y1.se;
        pdd y=y0+y1;
        int l=y.fi, r=y.se, yy=l;
        if(fl!=-1&&((x+yy)%2+2)%2!=fl) ++yy;
        if(yy>r) continue;
        flag=1; chg(x,yy); assert(getans(x,yy));
        break;
    }
    if(!flag) putend();
    else output();
    return 0;
}