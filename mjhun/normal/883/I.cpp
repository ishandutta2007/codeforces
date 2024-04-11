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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,k;
ll x[300005];
set<int> w;

bool can(ll t){
	w.clear();
	w.insert(n);
	for(int i=n-1;i>=0;--i){
		int p=upper_bound(x,x+n,x[i]+t)-x; // primera pos que no puedo
		if(i+k>p)continue;
		int j=*w.lower_bound(i+k);
		if(x[j-1]-x[i]>t)continue;
		w.insert(i);
	}
	return w.count(0);
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%lld",x+i);
	sort(x,x+n);
	ll s=0,e=1LL<<30;
	while(e-s>1){
	    ll m=(s+e)/2;
	    if(can(m-1))e=m;
	    else s=m;
	}
	printf("%lld\n",s);
	return 0;
}