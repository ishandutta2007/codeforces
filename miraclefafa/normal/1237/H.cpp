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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int f[]={0,2,1,3};

const int N=5100;
int a[N],b[N],p[N],q[N],cntp[10],cntq[10],z[N];
int _,n;
char s[N],t[N];
VI ret;

void gao(int x) {
	reverse(a,a+x);
	rep(i,0,x) a[i]=f[a[i]];
	ret.pb(x*2);
	//rep(j,0,n) printf("%d",a[j]); puts("");
}

bool gao() {
	ret.clear();
	rep(i,0,n) a[i]=p[i],b[i]=q[i];
	
	per(i,0,n) {
		if (a[i]==b[i]) continue;
		int cc=0;
		rep(j,0,i) {
			if (a[j]==b[i]) {
				z[cc++]=j;
			}
		}
		if (cc>0) {
			int x=z[rnd(cc)];
			gao(x+1);
			gao(i+1);
		} else {
			cc=0;
			rep(j,0,i+1) {
				if (f[a[j]]==b[i]) {
					z[cc++]=j;
				}
			}
			assert(cc>0);
			int x=z[rnd(cc)];
			gao(x+1);
			gao(1);
			gao(i+1);
		}
	}
	if (SZ(ret)<=2*n+1) {
		printf("%d\n",SZ(ret));
		for (auto x:ret) printf("%d ",x); puts("");
		return 1;
	}
	return 0;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%s",s);
		scanf("%s",t);
		n=strlen(s)/2;
		rep(i,0,4) cntp[i]=cntq[i]=0;
		rep(i,0,n) {
			p[i]=(s[2*i]-'0')*2+(s[2*i+1]-'0');
			q[i]=(t[2*i]-'0')*2+(t[2*i+1]-'0');
			cntp[p[i]]++; cntq[q[i]]++;
		}
		if (cntp[0]!=cntq[0]||cntp[3]!=cntq[3]) {
			puts("-1");
			continue;
		}
		while (!gao());
	}
}