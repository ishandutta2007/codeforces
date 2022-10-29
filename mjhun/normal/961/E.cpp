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

ll ft[MAXN+1];
void upd(int i0, ll v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
ll get(int i0){
	ll r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}

vector<int> e[200005];
int n;ll r;

int main(){
	scanf("%d",&n);
	fore(i,1,n+1){
		for(int j:e[i])upd(j,-1);
		int k;
		scanf("%d",&k);k=min(k,n+2);
		r+=get(k+1);
		if(k>i){
			upd(i,1);
			e[k+1].pb(i);
		}
	}
	printf("%lld\n",r);
	return 0;
}