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

int n;
ll a[64],b[64];
ll x[64];
ll f[64][128];
vector<vector<int> > w;


bool can(ll t, bool d=false){
	fore(i,0,n){
		x[i]=1000*a[i]-t*b[i];
		if(d)printf(" %lld",x[i]);
	}
	if(d)puts("");
	int i=0;
	w.clear();
	while(i<n){
		int j=i;
		while(j<n&&a[i]==a[j])j++;
		vector<int> t;
		fore(k,i,j)t.pb(k);
		sort(t.begin(),t.end(),[&](int i, int j){return x[i]<x[j];});
		w.pb(t);
		i=j;
	}
	fore(i,0,64)fore(j,0,128)f[i][j]=1LL<<60;
	f[0][0]=0;
	fore(i,0,SZ(w))fore(k,0,n+1){
		f[i+1][k+SZ(w[i])]=min(f[i+1][k+SZ(w[i])],f[i][k]);
		ll s=0;
		fore(j,0,SZ(w[i])){
			s+=x[w[i][j]];
			int z=max(k-j-1,0)+SZ(w[i])-1-j;
			//if(k+SZ(w[i])-1-j-j-1>=0)
				f[i+1][z]=min(f[i+1][z],s+f[i][k]);
		}
	}
	return f[SZ(w)][0]<=0;
}

pair<ll,ll> asd[64];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,n)scanf("%lld",b+i);
	fore(i,0,n)asd[i]=mp(a[i],b[i]);
	sort(asd,asd+n);
	fore(i,0,n)a[i]=asd[i].fst;
	fore(i,0,n)b[i]=asd[i].snd;
	ll s=0,e=1e11+1e5;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	//can(s,true);
	printf("%lld\n",s);
	return 0;
}