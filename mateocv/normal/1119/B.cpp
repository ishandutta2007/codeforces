#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll h;
map<ll,ll> m;
ll solve(){
	ll tot=0;
	for(auto i:m){
		tot+=i.snd;
	}
	ll sum=0;
	ll va=tot%2;
	for(auto i:m){
		fore(j,0,i.snd){
			if(va){
				sum+=i.fst;
			}
			va=1-va;
		}
	}
	if(sum<=h)return 1;
	return 0;
}

int main(){FIN;
	ll n; cin>>n>>h;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,0,n){
		m[a[i]]++;
		if(!solve()){
			cout<<i; return 0;
		}
	}
	cout<<n;
	return 0;
}