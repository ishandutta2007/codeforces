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
typedef int ll;

vector<ll> v[9000009];

vector<ll> st;

long long solve(ll id){
	long long res=0;
	vector<ll> sum;
	for(auto i:v[id])sum.pb(i%3000+1);
	//sum.pb(SZ(v[id]));
	sort(ALL(sum));
	ll j=0;
	fore(i,0,SZ(sum)){
		ll br=0;
		while(v[id][j]/3000<sum[i]){
			j++;
			if(j==SZ(v[id])){
				br++; break;
			}
		}
		if(br)break;
		res+=SZ(v[id])-j;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			fore(j,i+1,n){
				if(!SZ(v[3000*a[i]+a[j]]))st.pb(3000*a[i]+a[j]);
				v[3000*a[i]+a[j]].pb(3000*i+j);
			}
		}
		long long res=0;
		for(auto i:st){
			res+=solve(i);
		}
		cout<<res<<"\n";
		for(auto i:st)v[i].clear();
		st.clear();
	}
	
	return 0;
}