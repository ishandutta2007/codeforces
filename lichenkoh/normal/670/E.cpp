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
  node *prev;
  node *next;
  node *paired;
  char c;
};
const ll MAXN=500000+4;
int h[MAXN];
node* a[MAXN];
char ans[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,p; cin>>n>>m>>p;
	string s; cin>>s;
	string q;cin>>q;
	ll t=0;
	for (ll i=0;i<n;i++) {
		node *x=new node;
		a[i]=x;
		x->c=s[i];
		if (s[i]=='(') {
			h[t]=i;
			t++;
		}
		else {
			t--;
			x->paired=a[h[t]];
			a[h[t]]->paired=x;
		}
	}
	for (ll i=0;i<n;i++) {
		if (i>0) a[i]->prev=a[i-1];
		else a[i]->prev=NULL;
		if (i<n-1) a[i]->next=a[i+1];
		else a[i]->next=NULL;
	}
	node* x=a[p-1];
	for (ll j=0;j<m;j++) {
		if (q[j]=='R') {
			x=x->next;
		}
		else if (q[j]=='L') {
			x=x->prev;
		}
		else {
			node *l,*r;
			if (x->c=='(') {
				l=x; r=x->paired;
			}
			else {
				l=x->paired; r=x;
			}
			l=l->prev; r=r->next;
			if (l!=NULL&&r!=NULL) {
				l->next=r;
				r->prev=l;
				x=r;
			}
			else if (l!=NULL&&r==NULL) {
				l->next=r;
				x=l;
			}
			else if (l==NULL&&r!=NULL) {
				r->prev=l;
				x=r;
			}
		}
	}
	while(x->prev!=NULL) x=x->prev;
	ll idx=0;
	while(x!=NULL) {
		ans[idx]=x->c;
		x=x->next;
		idx++;
	}
	ans[idx]='\0';
	printf("%s\n",ans);
}