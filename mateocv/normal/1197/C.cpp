#include <bits/stdc++.h>
#define pb push_back
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
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> v;
	fore(i,0,n-1)v.pb(a[i+1]-a[i]);
	sort(ALL(v));
	fore(i,0,k-1)v.pop_back();
	ll sum=0;
	for(auto i:v)sum+=i; 
	cout<<sum;
	return 0;
}