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

ll st[1<<20];

void st_upd(int k, int s, int e, int p, ll v){
	if(s+1==e)st[k]=max(st[k],v);
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,v);
		else st_upd(2*k+1,m,e,p,v);
		st[k]=max(st[2*k],st[2*k+1]);
	}
}

ll st_query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return 0;
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return max(st_query(2*k,s,m,a,b),st_query(2*k+1,m,e,a,b));
}

int n;
ll r[100005],h[100005];
vector<ll> v;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%lld%lld",r+i,h+i);
		v.pb(r[i]*r[i]*h[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	fore(i,0,n){
		int k=lower_bound(v.begin(),v.end(),r[i]*r[i]*h[i])-v.begin();
		st_upd(1,0,SZ(v),k,v[k]+st_query(1,0,SZ(v),0,k));
	}
	printf("%.12lf\n",st[1]*acos(-1));
	return 0;
}