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

ll sum(ll n){
	ll res=0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}

ll solve0(ll n){
	vector<ll> d;
	while(n>0){
		d.pb(min(n,9ll));
		n-=d.back();
	}
	reverse(ALL(d));
	ll res=0;
	for(auto i:d){
		res*=10;
		res+=i;
	}
	return res;
}
ll solve08(ll n){
	vector<ll> d;
	ll ya=0;
	while(n>0){
		if(ya==0){
			d.pb(min(n,8ll));
			n-=d.back();
			ya++;
		}else{
			d.pb(min(n,9ll));
			n-=d.back();	
		}
	}
	reverse(ALL(d));
	ll res=0;
	for(auto i:d){
		res*=10;
		res+=i;
	}
	return res;
}

ll INF=9e18;

ll s1[12][12][160];

ll solve1(ll a, ll b, ll n){
	ll &res=s1[a][b][n];
	if(res>=-1)return res;
	res=INF;
	if(n>=9ll*a){
		ll s=solve1(a,b,n-9ll*a);
		if(s!=-1){
			res=min(res,10ll*s+9);
		}
	}
	if((n-b)%(a+b)==0&&n>=b){
		ll cc=(n-b)/(a+b);
		ll c=solve0(cc);
		if(c%10==9){
			c=solve08(cc);
		}
		if(c!=-1)res=min(res,c);
	}
	//cout<<a<<" "<<b<<" "<<n<<" "<<res<<"\n";
	if(res==INF)res=-1;
	return res;
}

ll s2[160][12];

ll solve(ll n, ll k){
	ll &res=s2[n][k];
	if(res>=-1)return res;
	res=INF;
	if(k==0){
		return res=solve0(n);
	}else{
		fore(i,0,10){
			ll va=0;
			ll a=0,b=0;
			fore(j,0,k+1){
				va+=(i+j)%10;
				if(i+j<10)a++;
				else b++;
			}
			if(va>n)continue;
			ll s=solve1(a,b,n-va);
			if(s!=-1)res=min(res,10ll*s+i);
		}
		if(res==INF)res=-1;
		return res;
	}
}

int main(){FIN;
	ll t; cin>>t;
	fore(i,0,12){
		fore(j,0,12){
			fore(k,0,160){
				s1[i][j][k]=-2;
			}
		}
	}
	fore(i,0,160){
		fore(j,0,12){		
			s2[i][j]=-2;
		}
	}
	while(t--){
		ll n,k; cin>>n>>k;
		cout<<solve(n,k)<<"\n";
	}
	
	return 0;
}