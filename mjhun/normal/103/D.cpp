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

#define S 550

int n,q;
ll x[300005];
ll s[600005];
ll r[300005];
vector<pair<int,int> > w[S];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",x+i);
	scanf("%d",&q);
	fore(i,0,q){
		int a,b;
		scanf("%d%d",&a,&b);a--;
		if(b<S)w[b].pb(mp(a,i));
		else {
			for(int j=a;j<n;j+=b)r[i]+=x[j];
		}
	}
	fore(b,1,S){
		for(int i=n-1;i>=0;--i)s[i]=x[i]+s[i+b];
		for(auto p:w[b])r[p.snd]=s[p.fst];
	}
	fore(i,0,q)printf("%lld\n",r[i]);
	return 0;
}