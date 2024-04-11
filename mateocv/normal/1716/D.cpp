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

const int MAXN=200005;

inline ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

ll pre[MAXN],pos[MAXN];

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll> res(n);
	pre[0]=1;
	fore(i,k,k+701){
		mset(pos,0);
		fore(j,i,n+1){
			if(j>=i)pos[j]=add(pos[j-i],pre[j-i]);
			res[j-1]=add(res[j-1],pos[j]);
		}
		//fore(j,0,n+1)cout<<pos[j]<<" "; cout<<"\n";
		swap(pre,pos);
	}
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}