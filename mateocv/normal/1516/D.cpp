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

const int MAXN=100005;

bool isprime[MAXN];
vector<ll> prime;
int SPF[MAXN];
 
void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

vector<ll> pr(ll n){
	vector<ll> res;
	while(n>1){
		ll s=SPF[n];
		if(SZ(res)==0||res.back()!=s){
			res.pb(s);
		}
		n/=s;
	}
	return res;
}

vector<ll> a;

ll ne[20][MAXN];

ll vis[MAXN];

int main(){FIN;
	mset(isprime,true);
	sieve(MAXN-1);
	ll n,q; cin>>n>>q;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	ll r=0;
	fore(i,0,n){
		if(r==n)ne[0][i]=r;
		else{
			while(1){
				auto p=pr(a[r]);
				ll br=0;
				for(auto i:p)br+=vis[i];
				if(br){
					ne[0][i]=r;
					break;
				}else{
					for(auto i:p)vis[i]++;
					r++;
					if(r==n){
						ne[0][i]=r;
						break;
					}
				}
			}
			auto p=pr(a[i]);
			for(auto i:p)vis[i]--;
		}
	}
	ne[0][n]=n;
	fore(j,1,20){
		fore(i,0,n+1){
			ne[j][i]=ne[j-1][ne[j-1][i]];
		}
	}
	while(q--){
		ll l,r; cin>>l>>r; l--; r--;
		ll res=0;
		for(ll k=19;k>=0;k--){
			if(ne[k][l]<=r){
				res+=(1ll<<k);
				l=ne[k][l];
			}
		}
		cout<<res+1<<"\n";
	}
	
	return 0;
}