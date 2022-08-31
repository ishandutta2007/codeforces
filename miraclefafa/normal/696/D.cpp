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

const int N=210;
const ll inf=1ll<<60;
int n,a[N],m;
ll l;
typedef long long matrix[N][N];

matrix ret,tmp,base;

void mul(matrix &a,matrix &b) {
	rep(i,0,m) rep(j,0,m) tmp[i][j]=(i==j)?0:-inf;
	rep(i,0,m) rep(j,0,m) {
		rep(k,0,m) tmp[i][j]=max(tmp[i][j],a[i][k]+b[k][j]);
	}
	rep(i,0,m) rep(j,0,m) a[i][j]=tmp[i][j];
}
void powmod(ll b) {
	rep(i,0,m) rep(j,0,m) ret[i][j]=(i==j)?0:-inf;
	for(;b;b>>=1) {
		if (b&1) mul(ret,base);
		mul(base,base);
	}
}


const int AC_SIGMA=26,AC_V=29,AC_N=210;
struct AC_automaton {
	struct node {
		node *go[AC_V],*fail,*f;
		int fg,id;
	}pool[AC_N],*cur,*root,*q[AC_N];
	node* newnode() {
		node *p=cur++;
		memset(p->go,0,sizeof(p->go));
		p->fail=p->f=NULL; p->fg=0;
		return p;
	}
	void init() { cur=pool; root=newnode();}
	node* append(node *p,int w) {
		if (!p->go[w]) p->go[w]=newnode(),p->go[w]->f=p;
		return p=p->go[w];
	}
	void build() {
		int t=1;
		q[0]=root;
		rep(i,0,t) rep(j,0,AC_SIGMA) if (q[i]->go[j]) {
			node *v=q[i]->go[j],*p=v->f->fail;
			while (p&&!p->go[j]) p=p->fail;
			if (p) v->fail=p->go[j]; else v->fail=root;
			q[t++]=q[i]->go[j];
		}
		rep(i,0,t) {
			if (q[i]->fail) q[i]->fg+=q[i]->fail->fg;
		}
		rep(i,0,t) rep(j,0,AC_SIGMA) if (!q[i]->go[j]) {
			node *p=q[i]->fail;
			while (p&&!p->go[j]) p=p->fail;
			if (p) q[i]->go[j]=p->go[j]; else q[i]->go[j]=root;
		}
		rep(i,0,t) rep(j,0,t) base[i][j]=-inf;
		rep(i,0,t) rep(j,0,AC_SIGMA) {
			base[q[i]-pool][q[i]->go[j]-pool]=max(base[q[i]-pool][q[i]->go[j]-pool],(ll)q[i]->go[j]->fg);
		}
		m=t;
	}
}T;
typedef AC_automaton::node ACnode;

char s[N];
int main() {
	scanf("%d%lld",&n,&l);
	rep(i,0,n) {
		scanf("%d",a+i);
	}
	T.init();
	rep(i,0,n) {
		scanf("%s",s);
		ACnode *p=T.root;
		int m=strlen(s);
		rep(j,0,m) {
			p=T.append(p,s[j]-'a');
		}
		p->fg+=a[i];
	}
	T.build();
	powmod(l);
	ll res=0;
	rep(i,0,m) res=max(res,ret[0][i]);
	printf("%lld\n",res);
}