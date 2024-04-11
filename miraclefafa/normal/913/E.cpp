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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct ope {
	string ans;
	int key,pro;
};
set<ope> q;
vector<ope> v;
ope ans[400][10];
char t[40];
int _;
bool operator <(ope a,ope b) {
	return SZ(a.ans)==SZ(b.ans)?a.ans<b.ans:SZ(a.ans)<SZ(b.ans);
}
void upd(int key,int pro,string s) {
	ope v=(ope){s,key,pro};
	if (ans[key][pro].ans.empty()) {
		ans[key][pro]=v;
		q.insert(v);
	} else if (v<ans[key][pro]) {
		q.erase(ans[key][pro]);
		ans[key][pro]=v;
		q.insert(v);
	}
}
int main() {
	upd(0xf0,0,"x");
	upd(0xcc,0,"y");
	upd(0xaa,0,"z");
	while (!q.empty()) {
		auto it=q.begin();
		ope c=*it;
		q.erase(it);
		upd(c.key,0,"("+c.ans+")");
		if (c.pro==0) upd(c.key^0xff,0,"!"+c.ans);
		v.pb(c);
		for (auto p:v) {
			if (c.pro<=1&&p.pro<=1) {
				upd(c.key&p.key,1,min(c.ans+'&'+p.ans,p.ans+'&'+c.ans));
			}
			if (c.pro<=2&&p.pro<=2) {
				upd(c.key|p.key,2,min(c.ans+'|'+p.ans,p.ans+'|'+c.ans));
			}
		}
	}
	rep(i,0,256) {
		ans[i][0]=min(ans[i][0],min(ans[i][1],ans[i][2]));
	}
	for (scanf("%d",&_);_;_--) {
		scanf("%s",t);
		int z=0;
		per(j,0,8) z=z*2+t[j]-'0';
		printf("%s\n",ans[z][0].ans.c_str());
	}
}