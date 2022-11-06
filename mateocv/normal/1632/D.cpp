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

const int K=18;

ll st[K][1<<K];

void st_init(vector<ll> a){
	fore(i,0,SZ(a))st[0][i]=a[i];
	fore(k,1,K){
		fore(i,0,SZ(a)-(1<<k)+1){
			st[k][i]=__gcd(st[k-1][i],st[k-1][i+(1<<(k-1))]);
		}
	}
}

ll st_query(int l, int r){
	int k=31-__builtin_clz(r-l);
	return __gcd(st[k][l],st[k][r-(1<<k)]);
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	st_init(a);
	ll pos=-1;
	vector<ll> res;
	if(a[0]==1){
		res.pb(1);
		pos=0;
	}else{
		res.pb(0);
	}
	fore(i,1,n){
		ll npos=i;
		ll br=0;
		while(npos>pos){
			ll val=st_query(npos,i+1);
			ll l=pos+1,r=npos;
			while(l<=r){
				ll m=(l+r)/2;
				if(st_query(m,i+1)==val)r=m-1;
				else l=m+1;
			}
			ll mini=i+1-npos,maxi=i+1-l;
			if(mini<=val&&val<=maxi){
				br++; break;
			}
			npos=r;
		}
		res.pb(res.back());
		if(br){
			pos=i;
			res.back()++;
		}
	}
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}