#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int n,m;
ll x[N],y[N],a,l;
map<ll,int> pos,ps;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) scanf("%I64d",x+i);
	x[n]=-(1ll<<40); x[n+1]=1ll<<40;
	n+=2;
	rep(i,0,n) y[i]=x[i],pos[y[i]]=i;
	sort(x,x+n);
	rep(i,0,n) ps[x[i]]=i;
	rep(i,0,m) {
		scanf("%I64d%I64d",&a,&l);
		a=y[a-1]; 
		int pre=-1,cur=lower_bound(x,x+n,a)-x,dir=0;
		while (1) {
			if (x[cur]-x[cur-1]>l&&x[cur+1]-x[cur]>l) {
				printf("%d\n",pos[x[cur]]+1);
				break;
			} else {
				if (dir==0) {
					int nxt=ps[x[upper_bound(x,x+n,x[cur]+l)-x-1]];
					if (nxt==pre&&l>=2*(x[nxt]-x[cur])) {
						l%=2*(x[nxt]-x[cur]);
					} else {
						l-=x[nxt]-x[cur];
						pre=cur; cur=nxt; dir=1;
					}
				} else {
					int nxt=ps[x[lower_bound(x,x+n,x[cur]-l)-x]];
					if (nxt==pre&&l>=2*(x[cur]-x[nxt])) {
						l%=2*(x[cur]-x[nxt]);
					} else {
						l-=x[cur]-x[nxt];
						pre=cur; cur=nxt; dir=0;
					}
				}
			}
		}
	}
}