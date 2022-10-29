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

#define MAXN 10000005

int q[MAXN],p[MAXN];
vector<int> ps;
ll z[1<<20];

bool asd(ll n, ll p, ll k){ // true si p^k divide a n!
	ll pp=p;
	while(k>0&&pp<=n){
		k-=n/pp;
		pp*=p;
	}
	return k<=0;
}

bool can(ll n){
	fore(i,0,SZ(ps))if(!asd(n,ps[i],z[i]))return false;
	return true;
}

int main(){
	memset(p,-1,sizeof(p));
	fore(i,2,MAXN)if(p[i]<0){
		int k=SZ(ps);ps.pb(i);
		p[i]=k;
		if(1LL*i*i>=MAXN)continue;
		for(int j=i*i;j<MAXN;j+=i)p[j]=k;
	}
	int k;
	scanf("%d",&k);
	while(k--){
		int x;
		scanf("%d",&x);
		q[x]++;
	}
	int a=0;
	for(int i=MAXN-1;i>1;--i){
		a+=q[i];
		int x=i;
		while(x>1){
			z[p[x]]+=a;
			x/=ps[p[x]];
		}
	}
	ll s=1,e=1e14;
	while(e-s>1){
		ll m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	printf("%lld\n",s);
	return 0;
}