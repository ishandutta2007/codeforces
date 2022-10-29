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

const ll INF=(1LL<<62)-1;
const ll asd=(1LL<<32)-1;

vector<ll> a;

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		int n;
		{
		ll l,r,x,y,z,b1,b2;
		scanf("%d%lld%lld%lld%lld%lld%lld%lld",&n,&l,&r,&x,&y,&z,&b1,&b2);
		a.clear();a.resize(n);
		fore(i,0,n){
			ll b;
			if(i==0)b=b1;
			else if(i==1)b=b2;
			else b=(b1*x+b2*y+z)&asd;
			a[i]=b%(r-l+1)+l;
			if(i>1)b1=b2,b2=b;
			//printf(" %lld",a[i]);
		}
		}
		//puts("");
		ll mn=INF,r=INF;
		fore(i,0,n){
			if(a[i]>mn)r=min(r,mn*a[i]);
			mn=min(mn,a[i]);
		}
		if(r>0){
			ll asd=0;
			for(int i=n-1;i>=0;--i){
				if(asd&&a[i]<asd)r=min(r,a[i]*asd);
				if(a[i]<0&&(!asd||a[i]>asd))asd=a[i];
			}
		}
		if(r==INF)puts("IMPOSSIBLE");
		else printf("%lld\n",r);
	}
	return 0;
}