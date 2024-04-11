#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

#define MAXALPHA 26
struct Node {
	Node *child[MAXALPHA];
	ll leaf;
};
typedef struct Node node;
node *init() {
	node *v = (node*)malloc(sizeof(struct Node));
	for (ll i = 0; i < MAXALPHA; i++) {
		v->child[i] = NULL;
	}
	v->leaf = UNDEF;
	return v;
}
void insert(node *root, string s, ll leafnum) {
	node *v = root;
	ll slen = s.length();
	for (ll i = 0; i < slen; i++) {
		ll c;
		if (s[i] >= 'a') {
			c = s[i]-'a';
		}
		else {
			c=s[i]-'A';
		}
		node *next = v->child[c];
		//printf("Insert: %c %x\n",s[i],next);
		if (next == NULL) {
			v->child[c] = init();
			//printf("New: %c %x\n",s[i],v->child[c]);
		}
		v = v->child[c];
	}
	v->leaf = leafnum;
	//printf("%s %d\n",s.c_str(),v->leaf);
}
const ll MAXM=100004;
const pair<ll,ll> UNDEFP = MP(UNDEF,UNDEF);
const pair<ll,ll> START = MP(-2LL,-2LL);
string w[MAXM];

pair<ll,ll> f[10004];

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >> n;
	string t; cin >> t;
	ll m; cin >> m;
	for (ll i=0;i<m;i++) {
		cin >> w[i];
	}
	node *root = init();
	//printf("rt1:%d %d\n",root->leaf,UNDEF);
	for (ll i=0;i<m;i++) {
		insert(root, w[i],i);
	}
	for (ll i=0;i<=n;i++) {
		f[i]=UNDEFP;
	}
	f[0]=START;
	for (ll x=0;x<n;x++) {
		node *v = root;
		for (ll y=x;y>=0;y--) {
			ll c=t[y]-'a';
			v = v->child[c];
			if (v==NULL) break;
			if (v->leaf!=UNDEF&&f[y]!=UNDEFP) {
				f[x+1] = MP(y,v->leaf);
				//printf("%d->%d:%d\n",y,x+1,v->leaf);
				break;
			}
		}
	}
	{
		vector<ll> tmp;
		pair<ll,ll> good = f[n];
		while(good!=START) {
			tmp.PB(good.second);
			good=f[good.first];
		}
		reverse(tmp.begin(),tmp.end());
		for (auto&idx:tmp) {
			printf("%s ",w[idx].c_str());
		}
		printf("\n");
	}
}