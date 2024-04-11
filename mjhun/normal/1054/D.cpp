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

int n,k;
map<int,int> q;

int main(){
	scanf("%d%d",&n,&k);
	int t=0;
	q[t]++;
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		t^=a;
		if(t&1)t^=(1<<k)-1;
		q[t]++;
	}
	ll r=1LL*n*(n+1)/2;
	for(auto _:q){
		int a=_.snd/2;
		r-=1LL*a*(a-1)/2;
		a=(_.snd+1)/2;
		r-=1LL*a*(a-1)/2;
	}
	printf("%lld\n",r);
	return 0;
}