#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
typedef pair<int,int> hashv;
const ll mod1=1000000007;
const ll mod2=1000000009;

hashv operator + (hashv a,hashv b) {
	int c1=a.fi+b.fi,c2=a.se+b.se;
	if (c1>=mod1) c1-=mod1;
	if (c2>=mod2) c2-=mod2;
	return mp(c1,c2);
}

hashv operator - (hashv a,hashv b) {
	int c1=a.fi-b.fi,c2=a.se-b.se;
	if (c1<0) c1+=mod1;
	if (c2<0) c2+=mod2;
	return mp(c1,c2);
}

hashv operator * (hashv a,hashv b) {
	return mp(1ll*a.fi*b.fi%mod1,1ll*a.se*b.se%mod2);
}

char s[N];
int nxt[N],lag[N];
hashv hv[N][20],pw[N];
int ch[N],len[N],p[N][20];

stack<int> st;

int main() {
	scanf("%s",s);
	int n=strlen(s);
	hashv base=hashv(13331,23333);
	pw[0]=hashv(1,1);
	rep(i,1,n+1) pw[i]=pw[i-1]*base;
	per(i,0,n) {
		nxt[i]=-1;
		if (s[i]=='(') {
			if (!st.empty()) nxt[i]=st.top(),st.pop();
		} else {
			st.push(i);
		}
		p[i][0]=i+1;
		hv[i][0]=mp(s[i],s[i]);
		len[i]=len[i+1]+1;
		rep(j,1,20) if ((1<<j)<=len[i]) {
			p[i][j]=p[p[i][j-1]][j-1];
			hv[i][j]=hv[i][j-1]*pw[1<<(j-1)]+hv[p[i][j-1]][j-1];
		}
		if (nxt[i]!=-1) {
			int x=i,y=nxt[i]+1;
			per(j,0,20) if ((1<<j)<=len[x]&&(1<<j)<=len[y]) {
				if (hv[x][j]==hv[y][j]) x=p[x][j],y=p[y][j];
			}
			if (y==n||hv[x][0]>hv[y][0]) {
				y=nxt[i]+1;
				rep(j,0,20) p[i][j]=p[y][j],hv[i][j]=hv[y][j];
				len[i]=len[y];
			}
		}
		rep(j,0,20) if ((1<<j)<=len[i]) {

		}
	}
	int x=0;
	rep(i,0,len[0]) {
		putchar(hv[x][0].fi);
		x=p[x][0];
	}
	puts("");
}