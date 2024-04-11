#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,m;
pair<int,PII> p[N];
PII e[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&p[i].fi,&p[i].se.fi);
		p[i].se.fi*=-1; p[i].se.se=i;
	}
	sort(p,p+m);
	int cnt=0; ll E=0; PII pre=mp(2,1);
	rep(i,0,m) {
		int id=p[i].se.se;
		if (p[i].se.fi==-1) { cnt++; E+=cnt; e[id]=mp(0,cnt); }
		else {
			if (E==0) {
				puts("-1"); return 0;
			} else {
				e[id]=pre;
				pre.se++;
				if (pre.se==pre.fi) pre.fi++,pre.se=1;
			}
		}
		--E;
	}
	rep(i,0,m) {
		printf("%d %d\n",e[i].fi+1,e[i].se+1);
	}
}