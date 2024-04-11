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

int n,q,x,y;
char ch[10];
set< pair<int,PII> > st;
set<int> pr;
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	st.insert(mp(0,mp(0,0)));
	st.insert(mp(n+1,mp(0,0)));
	rep(i,0,q) {
		scanf("%d%d%s",&x,&y,ch);
		if (pr.count(x)) {
			puts("0");
			continue;
		}
		pr.insert(x);
		pair<int,PII> seg=*(--st.upper_bound(mp(x,mp(n+2,n+2))));
		if (ch[0]=='L') {
			st.erase(seg);
			printf("%d\n",x-seg.se.fi);
			st.insert(mp(seg.fi,mp(seg.se.fi,y)));
			st.insert(mp(x,mp(seg.se.fi,seg.se.se)));
		} else {
			printf("%d\n",y-seg.se.se);
			st.insert(mp(x,mp(x,seg.se.se)));
		}
//		for (auto it:st) printf("%d %d %d\n",it.fi,it.se.fi,it.se.se);
	}
}