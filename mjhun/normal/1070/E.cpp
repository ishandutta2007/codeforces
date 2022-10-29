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

int n,m;ll tt;
int p[200005];
vector<int> ps;

bool ok(int k){
	ll t=tt;
	int q=0;ll s=0;
	fore(i,0,n)if(p[i]<=k){
		if(t-p[i]<0)return false;
		t-=p[i];
		s+=p[i];
		q++;
		if(q==m)t-=s,s=0,q=0;
	}
	return true;
}

int doit(int k){
	ll t=tt;
	int q=0;ll s=0;int r=0;
	fore(i,0,n)if(p[i]<=k){
		if(t-p[i]<0)break;
		t-=p[i];
		s+=p[i];
		q++;
		r++;
		if(q==m)t-=s,s=0,q=0;
	}
	return r;
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		ps.clear();
		scanf("%d%d%lld",&n,&m,&tt);
		fore(i,0,n)scanf("%d",p+i),ps.pb(p[i]);
		sort(ps.begin(),ps.end());
		ps.erase(unique(ps.begin(),ps.end()),ps.end());
		int s=0,e=SZ(ps);
		while(e-s>1){
			int m=(s+e)/2;
			if(ok(ps[m]))s=m;
			else e=m;
		}
		pair<int,int> r=mp(doit(ps[s]),ps[s]);
		if(s<SZ(ps)-1)r=max(r,mp(doit(ps[s+1]),ps[s+1]));
		if(tt<r.snd)r.snd=tt;
		printf("%d %d\n",r.fst,r.snd);
	}
	return 0;
}