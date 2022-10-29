#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=(1LL*r*a)%MOD;
		e>>=1;
		a=(1LL*a*a)%MOD;
	}
	return r;
}

vector<int> ds[100005];
int a[100005];
int n;

int main(){
	fore(i,1,100001)for(int j=i;j<100001;j+=i)ds[j].pb(i);
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	sort(a,a+n);
	int rr=0;
	fore(l,1,a[n-1]+1){
		int m=ds[l].size();
		assert(ds[l][m-1]==l);
		int k=a+n-lower_bound(a,a+n,l);
		int r=(pm(m,k)+MOD-pm(m-1,k))%MOD;
		fore(i,1,m){
			int d=ds[l][m-1-i];assert(d<ds[l][m-i]);
			int k2=a+n-lower_bound(a,a+n,d);
			r=(1LL*r*pm(m-i,k2-k))%MOD;
			k=k2;
		}
		rr+=r;
		rr%=MOD;
	}
	printf("%d\n",rr);
	return 0;
}