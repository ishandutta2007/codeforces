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

int main(){FIN;
	ll n; cin>>n;
	ll a;
	set<ll> st[2];
	vector<ll> v;
	fore(i,0,n){
		cin>>a;
		if(!st[0].count(a)){
			st[0].insert(a);
		}else 
		if(!st[1].count(a)){
			st[1].insert(a);
		}else{
			cout<<"NO"; return 0;
		}
	}
	for(auto i:st[1]){
		v.pb(i);
	}
	sort(v.rbegin(),v.rend());
	cout<<"YES\n";
	cout<<SZ(st[0])<<"\n";
	for(auto i:st[0])cout<<i<<" ";
	cout<<"\n";
	cout<<SZ(v)<<"\n";
	fore(i,0,SZ(v))cout<<v[i]<<" ";
	
	return 0;
}