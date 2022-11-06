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

void print(vector<ll> v){
	for(auto i:v)cout<<i+1<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)a[i]=i;
		cout<<n<<"\n";
		print(a);
		fore(i,1,n){
			swap(a[i],a[i-1]);
			print(a);
		}
	}
	
	return 0;
}