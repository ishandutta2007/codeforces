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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=100100;
string s[N],t[N];
int n,ty[N],e,sv[N],ot[N],ct[N];
char tmp[10];
map<string,int> hs;

set<int> ovv,inp[2],inc[2];
vector<pair<string,string>> ret;
string trans(int x) {
	string t;
	while (x) t.pb(x%10+'0'),x/=10;
	reverse(all(t));
	return t;
}
void gao(int id,string ss) {
	ret.pb(mp(t[id],ss));
	t[id]=ss;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		int x=i;
		s[i]=trans(i);
		hs[s[i]]=i;
	}
	rep(i,1,n+1) {
		scanf("%s",tmp);
		t[i]=tmp;
		scanf("%d",ty+i); ty[i]^=1;
		if (ty[i]==0) e++;
	}
	bool cor=1,extra=0;
	rep(i,1,e+1) inc[0].insert(i);
	rep(i,e+1,n+1) inc[1].insert(i);
	rep(i,1,n+1) {
		if (!hs.count(t[i])) cor=0,ot[i]=1,extra=1;
		else {
			int v=hs[t[i]];
			sv[i]=v; ovv.insert(v);
			if ((v>e)!=ty[i]) {
				cor=0,ct[i]=0;
				inp[ty[i]].insert(i);
			} else ct[i]=1;
		}
	}
	if (cor) {
		puts("0");
		return 0;
	}
	if (!extra) {
		int x=1;
		while (ovv.count(x)) x++;
		rep(i,1,n+1) if (ct[i]==0) {
			gao(i,trans(x));
			ot[i]=1; inp[ty[i]].erase(i);
			break;
		}
	}
	rep(i,1,n+1) if (ot[i]==0) {
		inc[sv[i]>e].erase(sv[i]);
	}
	while (!inp[0].empty()||!inp[1].empty()) {
		if (!inp[0].empty()&&!inc[0].empty()) {
			int p=*inp[0].begin(),v=*inc[0].begin();
			inp[0].erase(p); inc[0].erase(v);
			gao(p,s[v]);
			inc[1].insert(sv[p]);
		} else if (!inp[1].empty()&&!inc[1].empty()) {
			int p=*inp[1].begin(),v=*inc[1].begin();
			inp[1].erase(p); inc[1].erase(v);
			gao(p,s[v]);
			inc[0].insert(sv[p]);			
		} else assert(0);
	}
	rep(i,1,n+1) if (ot[i]) {
		assert(!inc[ty[i]].empty());
		int v=*inc[ty[i]].begin();
		inc[ty[i]].erase(v);
		gao(i,s[v]);
	}
	printf("%d\n",SZ(ret));
	for (auto p:ret) {
		printf("move %s %s\n",p.fi.c_str(),p.se.c_str());
	}
}