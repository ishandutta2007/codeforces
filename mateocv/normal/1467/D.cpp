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

ll MOD=1000000007;
ll a[5050],c[5050][5050],sum[5050];

int main(){FIN;
	ll n,k,q; cin>>n>>k>>q;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)c[i][0]=1;
	fore(i,0,k){
		fore(j,0,n){
			if(j-1>=0)c[j-1][i+1]=(c[j-1][i+1]+c[j][i])%MOD;
			if(j+1<n)c[j+1][i+1]=(c[j+1][i+1]+c[j][i])%MOD;
		}
	}
	fore(i,0,n){
		fore(j,0,k+1)sum[i]=(sum[i]+c[i][j]*c[i][k-j])%MOD;
	}
	//fore(i,0,n)cout<<sum[i]<<" ";
	//cout<<"\n";
	ll res=0;
	fore(i,0,n)res=(res+a[i]*sum[i])%MOD;
	while(q--){
		ll pos,val; cin>>pos>>val; pos--;
		res=(res-(a[pos]*sum[pos])%MOD+MOD)%MOD;
		a[pos]=val;
		res=(res+sum[pos]*a[pos])%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}