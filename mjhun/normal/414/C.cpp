#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL ""
#endif
#define K ((1<<20)+10)
using namespace std;

typedef long long ll;

int ft[K];

void fu(int x, int v){
	for(;x<K;x+=x&-x)ft[x]+=v;
}

int fq(int x){
	int r=0;
	for(;x>0;x-=x&-x)r+=ft[x];
	return r;
}

int n;
int a[1<<20];
pair<int,int> aa[1<<20];
ll d[21];

ll ninv(int s, int e, int j){
	ll r=0;
	for(int i=s;i!=e;i+=j){
		r+=fq(K-a[i]-2);
		fu(K-a[i]-1,1);
	}
	for(int i=s;i!=e;i+=j){
		fu(K-a[i]-1,-1);
	}
	return r;
}

ll cd(int k){
	ll r=0;
	fore(j,0,1<<(n-k)){
		r+=ninv(j*(1<<k),(j+1)*(1<<k),1)-ninv((j+1)*(1<<k)-1,j*(1<<k)-1,-1);
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,1<<n){
		scanf("%d",a+i);
		aa[i]=mp(a[i],i);
	}
	sort(aa,aa+(1<<n));
	int c=0;
	fore(i,0,(1<<n)){
		if(i>0&&aa[i].fst!=aa[i-1].fst)c++;
		a[aa[i].snd]=c;
	}
	fore(i,0,n+1)d[i]=cd(i);
	ll ii=ninv(0,1<<n,1);
	//fore(i,0,1<<n)printf(" %d",a[i]);puts("");
	//printf(" %lld\n",ii);
	int q;
	scanf("%d",&q);
	c=0;
	while(q--){
		int k;
		scanf("%d",&k);c^=(1<<k);
		int s=0;ll r=ii;
		for(int i=n;i>=0;--i){
			if(c&(1<<i)){
				if(s)r+=d[i];
				else r-=d[i];
				s^=1;
			}
		}
		printf(LL "\n",r);
	}
	return 0;
}