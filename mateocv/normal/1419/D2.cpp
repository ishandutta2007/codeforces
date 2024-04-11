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

vector<ll> v;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res=0;
	fore(i,0,n)v.pb(0);
	ll npos=0;
	fore(i,0,n){
		if(2*i+1<n){
			v[2*i+1]=a[i];
		}else{
			v[npos]=a[i];
			npos+=2;
		}
	}
	fore(i,0,n){
		if(i!=0&&i!=n-1){
			res+=(v[i]<v[i-1]&&v[i]<v[i+1]);
		}
	}
	cout<<res<<"\n";
	for(auto i:v)cout<<i<<" ";
	return 0;
}