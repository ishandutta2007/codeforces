#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=998244353;
ll n, q, p[MX], add[MX], dp[MX], u;
ll SEG[MX*4], LAZY[MX*4];
int SEGR[MX*4], SEGL[MX*4];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
ll mod(ll x_) {
	return (x_ + MOD)%MOD;
}
void buildSeg(int p=0, int l=0, int r=n-1) {
    LAZY[p] = 1;
    if(l == r) {
        SEG[p] = dp[l];
    } else {
        int m=(l+r)/2;
        buildSeg(p*2+1,l,m);
        buildSeg(p*2+2,m+1,r);
        SEG[p] = mod(SEG[p*2+1] + SEG[p*2+2]);
    }
}
void multSeg(int i, int j, ll v, ll lazy=1, int p=0, int l=0, int r=n-1) {
    SEG[p] = mod(SEG[p]*lazy);
    LAZY[p] = mod(LAZY[p]*lazy);
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        SEG[p] = mod(SEG[p]*v);
        LAZY[p] = mod(LAZY[p]*v);
    } else {
        int m=(l+r)/2;
        multSeg(i,j,v,LAZY[p],p*2+1,l,m);
        multSeg(i,j,v,LAZY[p],p*2+2,m+1,r);
        LAZY[p] = 1;
        SEG[p] = mod(SEG[p*2+1] + SEG[p*2+2]);
    }
}
void buildSegR(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        SEGR[p] = n-1;
    } else {
        int m=(l+r)/2;
        buildSegR(p*2+1,l,m);
        buildSegR(p*2+2,m+1,r);
        SEGR[p] = -1;
    }
}
void updateSegR(int i, int j, int v, int lazy=-1, int p=0, int l=0, int r=n-1) {
    if(lazy != -1) SEGR[p] = lazy;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        SEGR[p] = v;
    } else {
        int m=(l+r)/2;
        updateSegR(i,j,v,SEGR[p],p*2+1,l,m);
        updateSegR(i,j,v,SEGR[p],p*2+2,m+1,r);
        SEGR[p] = -1;
    }
}
int getSegR(int i, int lazy=-1, int p=0, int l=0, int r=n-1) {
    if(lazy != -1) SEGR[p] = lazy;
    if(i < l || i > r) return 0;
    if(l == r) return SEGR[p];
    int m=(l+r)/2;
    int a=getSegR(i,SEGR[p],p*2+1,l,m);
    int b=getSegR(i,SEGR[p],p*2+2,m+1,r);
    SEGR[p] = -1;
    return max(a,b);
}
void buildSegL(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        SEGL[p] = 0;
    } else {
        int m=(l+r)/2;
        buildSegL(p*2+1,l,m);
        buildSegL(p*2+2,m+1,r);
        SEGL[p] = -1;
    }
}
void updateSegL(int i, int j, int v, int lazy=-1, int p=0, int l=0, int r=n-1) {
    if(lazy != -1) SEGL[p] = lazy;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        SEGL[p] = v;
    } else {
        int m=(l+r)/2;
        updateSegL(i,j,v,SEGL[p],p*2+1,l,m);
        updateSegL(i,j,v,SEGL[p],p*2+2,m+1,r);
        SEGL[p] = -1;
    }
}
int getSegL(int i, int lazy=-1, int p=0, int l=0, int r=n-1) {
    if(lazy != -1) SEGL[p] = lazy;
    if(i < l || i > r) return 0;
    if(l == r) return SEGL[p];
    int m=(l+r)/2;
    int a=getSegL(i,SEGL[p],p*2+1,l,m);
    int b=getSegL(i,SEGL[p],p*2+2,m+1,r);
    SEGL[p] = -1;
    return max(a,b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    RE(i,n) cin>>p[i];
    ll inv100 = inv(100);
    RE(i,n) add[i] = 1*inv(mod(p[i]*inv100));
    REV(i,0,n) dp[i] = mod(add[i] * (i==n-1 ? 1 : dp[i+1]));
    dp[n] = 1;

    buildSeg();
    buildSegR();
    buildSegL();
    RE(i,q) {
    	cin>>u; u-=2;
        if(getSegR(u) == u) {
            //remove checkpoint
            int r = getSegR(u+1);
            int l = getSegL(u);
            updateSegL(u+1,r,l);
            updateSegR(l,u,r);
            multSeg(l,u,mod(dp[u+1]*inv(dp[r+1])));
        } else {
            //add checkpoint
            int l = getSegL(u);
            int r = getSegR(u);
            updateSegL(u+1,r,u+1);
            updateSegR(l,u,u);
            multSeg(l,u,inv(mod(dp[u+1]*inv(dp[r+1]))));
        }
    	cout<<SEG[0]<<endl;
    }
}