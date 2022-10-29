#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN 200005

int ft[MAXN+1];
void upd(int i0, int v){for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get(int i0, int i1){return get(i1)-get(i0);}

int n,m;
int p[200005];
vector<int> w[200005];
vector<pair<int,int> > q[200005];
int r[200005];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		p[a]=i;
	}
	fore(i,0,m){
		int s,e;
		scanf("%d%d",&s,&e);s--;
		q[s].pb(mp(e,i));
	}
	fore(i,1,n+1)for(int j=i;j<=n;j+=i)w[min(p[i],p[j])].pb(max(p[i],p[j]));
	for(int i=n-1;i>=0;--i){
		for(int t:w[i])upd(t,1);
		for(auto p:q[i])r[p.snd]=get(i,p.fst);
	}
	fore(i,0,m)printf("%d\n",r[i]);
	return 0;
}