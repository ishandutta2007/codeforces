#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN = 1000006;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	ll b[q];
	fore(i,0,q)cin>>b[i];
	fore(i,0,n){
		upd(a[i],1);
	}
	fore(i,0,q){
		if(b[i]>0){
			upd(b[i]-1,1);
		}else{
			ll l=0,r=n;
			while(l<=r){
				ll m=(l+r)/2;
				if(get(m)>=-b[i])r=m-1;
				else l=m+1;
			}
			upd(l-1,-1);
		}
	}
	fore(i,0,n){
		if(get(i+1)>0){
			cout<<i+1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}