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

const int N=151000;
int n,t[N],ans,s,val[N];
set<PII> ret;
VI pos;
bool valid(int x) {
	if (x%2==0) {
		return (x==n-1||t[x]<t[x+1])&&(x==0||t[x]<t[x-1]);
	} else {
		return (x==n-1||t[x]>t[x+1])&&(x==0||t[x]>t[x-1]);
	}
}
void upd(int x) {
	if (x<0||x>=n) return;
	s-=val[x];
	val[x]=valid(x);
	s+=val[x];
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",t+i);
	rep(i,0,n) {
		val[i]=valid(i);
		if (!val[i]) pos.pb(i);
		s+=val[i];
	}
	if (SZ(pos)>=10) {
		puts("0"); return 0;
	}
	for (auto u:pos) rep(v,0,n) {
		swap(t[u],t[v]);
		upd(u-1); upd(u); upd(u+1); upd(v-1); upd(v); upd(v+1);
		if (s==n) {
			ret.insert(mp(min(u,v),max(u,v)));
		}
		swap(t[u],t[v]);
		upd(u-1); upd(u); upd(u+1); upd(v-1); upd(v); upd(v+1);
	}
	printf("%d\n",SZ(ret));
}