#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
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

typedef bitset<1048576> bs;
int getid(string s) {
	int len=SZ(s),id=0;
	if (len>19) return -1;
	rep(j,0,len) id=id*2+s[j]-'0';
	return id+(1<<len)-2;
}
int n,m,u,v;
char s[110];
string t;
struct blk {
	string bg,ed;
	bs S;
	bool full;
	void add(string s) {
		int m=SZ(s);
		rep(j,0,m) rep(k,j,m) {
			string f=s.substr(j,k-j+1);
			int id=getid(f);
			if (id==-1) continue;
			S[id]=1;
		}
	}
	void simply() {
		if (SZ(bg)>20) {
			bg=bg.substr(0,20);
			full=0;
		}
		if (SZ(ed)>20) {
			ed=ed.substr(SZ(ed)-20,20);
			full=0;
		}
	}
	int query() {
		per(i,1,20) {
			int d=(1<<i)-2,val=1;
			rep(j,0,(1<<i)) {
				if (!S[d+j]) { val=0; break;}
			}
			if (val) return i;
		}
		return 0;
	}
}b[210];
void gao(int p,int u,int v) {
	b[p].S=b[u].S|b[v].S;
	if (b[u].full) b[p].bg=b[u].bg+b[v].bg,b[p].full=1; else b[p].bg=b[u].bg;
	if (b[v].full) b[p].ed=b[u].ed+b[v].ed,b[p].full=1; else b[p].ed=b[v].ed;
	b[p].add(b[u].ed+b[v].bg);
	b[p].simply();
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",s);
		t=s;
		b[i].add(t);
		b[i].bg=t; b[i].ed=t;
		b[i].full=1;
		b[i].simply();
	}
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		gao(n+i,u-1,v-1);
		printf("%d\n",b[n+i].query());
	}
}