#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
struct node {
  struct node *child[2];
  int cnt;
};
typedef struct node node;
node *newnode() {
	node *r = new node;
	for (ll i=0;i<2;i++) r->child[i]=NULL;
	r->cnt=0;
	return r;
}
void ins(node *r, ll x, ll k) {
	//printf("Ins %lld %lld\n",x,k);
	if (k<0) return;
	ll b=(x>>k)&1;
	if (r->child[b]==NULL) {
		r->child[b]=newnode();
	}
	r->child[b]->cnt++;
	ins(r->child[b],x,k-1);
}
void rm(node *r, ll x, ll k) {
	if (k<0) return;
	ll b=(x>>k)&1;
	r->child[b]->cnt--;
	rm(r->child[b],x,k-1);
	if (0==r->child[b]->cnt) {
		delete r->child[b];
		r->child[b]=NULL;
	}
}
ll query(node *r, ll x, ll k) {
	if (k<0) return 0;
	ll b=(x>>k)&1;
	ll want=b^1;
	if (r->child[want]!=NULL) {
		return (1LL<<k)|query(r->child[want],x,k-1);
	}
	else {
		return query(r->child[b],x,k-1);
	}
}
const ll mk=31;
//const ll mk=5;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll q; cin>>q;
	//printf("Got q:%lld\n",q);
	node *r=newnode();
	ins(r,0,mk);
	for (ll ii=0;ii<q;ii++) {
		//printf("Getting\n");
		char c; ll x; cin>>c>>x;
		//printf("Got %c %lld\n",c,x);
		if (c=='+') {
			ins(r,x,mk);
		}
		else if (c=='-') {
			rm(r,x,mk);
		}
		else {
			ll ans=query(r,x,mk);
			cout<<ans<<"\n";
			//printf("%lld\n",ans);
		}
	}
}