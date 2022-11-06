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
	fore(i,0,SZ(v)){
		cout<<v[i];
		if(i<SZ(v)-1)cout<<".";
	}
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> s;
		for(auto i:a){
			if(i==1)s.pb(1);
			else{
				while(SZ(s)&&s.back()!=i-1)s.pop_back();
				assert(SZ(s));
				s[SZ(s)-1]++;
			}
			print(s);
		}
	}
	
	return 0;
}