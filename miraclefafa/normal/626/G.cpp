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

#define prev prrrr
struct frac {
	ll a,b;
};
bool operator < (const frac &a,const frac &b) {
	// a.a*b.b< a.b*b.a
	if (fabs((double)a.b*b.a-(double)a.a*b.b)>=1e17) {
		return (double)a.a*b.b<(double)a.b*b.a;
	} else return a.a*b.b-a.b*b.a<0;
}
const int N=201000;
int n,t,q,p[N],l[N],cv[N],ty,id;
frac prev[N],nxtv[N];
set<pair<frac,int> > prv,nxt;
double ans;
void calc(int id) {
	prev[id]=(frac){(ll)p[id]*l[id],(ll)(cv[id]+l[id]-1)*(cv[id]+l[id])};
	nxtv[id]=(frac){(ll)p[id]*l[id],(ll)(cv[id]+l[id])*(cv[id]+l[id]+1)};
}
void add(int id) {
	ans+=(double)p[id]*cv[id]/(l[id]+cv[id]);
	calc(id);
	if (cv[id]!=0) prv.insert(mp(prev[id],id));
	if (cv[id]!=l[id]) nxt.insert(mp(nxtv[id],id));
}
void del(int id) {
	ans-=(double)p[id]*cv[id]/(l[id]+cv[id]);
	if (cv[id]!=0) prv.erase(mp(prev[id],id));
	if (cv[id]!=l[id]) nxt.erase(mp(nxtv[id],id));
}
void gopre(int id) {
	del(id);
	assert(cv[id]);
	cv[id]--;
	add(id);
}
void gonxt(int id) {
	del(id);
	assert(cv[id]!=l[id]);
	cv[id]++;
	add(id);
}
int main() {
//	freopen("G.in","r",stdin);
	scanf("%d%d%d",&n,&t,&q);
	rep(i,0,n) scanf("%d",p+i);
	rep(i,0,n) {
		scanf("%d",l+i);
		calc(i);
		add(i);
	}
	int cf=0;
	while (cf<t&&!nxt.empty()) {
		gonxt(nxt.rbegin()->se);
		cf++;
	}
	rep(i,0,q) {
		scanf("%d%d",&ty,&id); --id;
		if (ty==1) {
			del(id);
			++l[id]; calc(id); add(id);
		} else {
			del(id); --l[id];
			if (cv[id]>l[id]) --cv[id],--cf;
			calc(id); add(id);
		}
		while (!nxt.empty()&&!prv.empty()) {
			if (prv.begin()->fi<nxt.rbegin()->fi) {
				int id1=prv.begin()->se,id2=nxt.rbegin()->se;
				gopre(id1); gonxt(id2);
			} else break;
		}
		while (cf<t&&!nxt.empty()) {
			gonxt(nxt.rbegin()->se);// largest
			cf++;
		}
		printf("%.10f\n",ans);
	}
}