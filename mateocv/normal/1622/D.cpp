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

const ll MOD=998244353;

const int MAXN=5005;

ll comb[MAXN][MAXN];

//ll cant[MAXN][MAXN];

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll sub(ll x, ll y){
	x-=y;
	if(x<0)x+=MOD;
	return x;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	vector<ll> v;
	fore(i,0,n){
		if(s[i]=='1')v.pb(i);
	}
	if(k>SZ(v)){
		cout<<"1\n";
		return 0;
	}
	fore(i,0,MAXN){
		fore(j,0,i+1){
			if(j==0||j==i)comb[i][j]=1;
			else comb[i][j]=add(comb[i-1][j],comb[i-1][j-1]);
		}
	}
	ll res=1;
	fore(i,1,k+1){
		fore(j,0,SZ(v)){
			if(j+i>SZ(v))continue;
			ll l=0;
			if(j)l=v[j-1]+1;
			ll r=n-1;
			if(i+j<SZ(v))r=v[i+j]-1;
			assert(l<=r);
			ll c=0;
			//cout<<l<<" "<<r<<" "<<comb[r-l+1][k]<<"\n";
			c=add(c,comb[r-l+1][i]);
			//cout<<c<<"\n";
			ll l2=v[j]+1,r2=v[i+j-1]-1;
			if(i==1){
				c=sub(c,1);
			}else{
				c=sub(c,comb[r-l2+1][i-1]);
				c=sub(c,comb[r2-l+1][i-1]);
				c=add(c,comb[r2-l2+1][i-2]);
			}
			//cout<<i<<" "<<j<<": "<<c<<"\n";
			res=add(res,c);
		}
	}
	cout<<res<<"\n";
	
	return 0;
}