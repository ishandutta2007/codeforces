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

int n,m,q;
ll a[100005],b[100005];
ll sa;
set<ll> w;

ll query(){
	auto it=w.lower_bound(sa);
	ll r=1LL<<60;
	if(it!=w.end())r=min(r,abs((*it)-sa));
	if(it!=w.begin()){
		--it;
		r=min(r,abs((*it)-sa));
	}
	return r;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	fore(i,0,n){
		scanf("%lld",a+i);
		if(i%2==0)sa+=a[i];
		else sa-=a[i];
	}
	fore(i,0,m)scanf("%lld",b+i);
	ll sb=0;
	fore(i,0,n){
		if(i%2==0)sb+=b[i];
		else sb-=b[i];
	}
	w.insert(sb);
	fore(i,n,m){
		sb-=b[i-n];
		sb*=-1;
		if((n-1)%2==0)sb+=b[i];
		else sb-=b[i];
		w.insert(sb);
	}
	printf("%lld\n",query());
	while(q--){
		int s,e; ll x;
		scanf("%d%d%lld",&s,&e,&x);s--;
		if((e-s)%2){
			if(s%2==0){
				sa+=x;
			}
			else {
				sa-=x;
			}
		}
		//deb(" %lld\n",sa);
		printf("%lld\n",query());
	}
	return 0;
}