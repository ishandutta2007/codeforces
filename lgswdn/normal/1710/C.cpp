#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define r(a) rep(a,0,1)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e5+9,mod=998244353;
int n,t[N],f[2][2][2][2][2][2][2];
char s[N];
void up(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
bool ck(bool a,int b,int c) {return !((b==c&&!a)||(b>c));}

signed main() {
    scanf("%s",s); n=strlen(s);
    reverse(s,s+n); s[0]++;
    rep(i,0,n-1) if(t[i]==2) {
        s[i]='0', s[i+1]++;
        if(i==n-1) n++;
    }
    rep(i,0,n-1) t[i]=s[i]-'0';
    rep(x,0,1) rep(y,0,1) rep(z,0,1) {
        int a=x^y, b=y^z, c=z^x;
        int nx=(x<t[0]), ny=(y<t[0]), nz=(z<t[0]), na=(a+b>c), nb=(b+c>a), nc=(c+a>b);
        f[0][nx][ny][nz][na][nb][nc]++;
    }
    rep(i,1,n-1) {
        int dd=i%2;
        memset(f[dd],0,sizeof(f[dd]));
        r(a) r(b) r(c) r(x) r(y) r(z) {
            int ff=f[dd^1][a][b][c][x][y][z];
            r(na) r(nb) r(nc) {
                int nu=na^nb, nv=nb^nc, nw=nc^na;
                up(f[dd][ck(a,na,t[i])][ck(b,nb,t[i])][ck(c,nc,t[i])][ck(x,nw,nu+nv)][ck(y,nu,nv+nw)][ck(z,nv,nw+nu)],ff);
            }
        }
    }
    printf("%lld\n",f[(n-1)%2][1][1][1][1][1][1]);
    return 0;
}