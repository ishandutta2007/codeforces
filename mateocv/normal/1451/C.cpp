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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string a,b; cin>>a>>b;
		ll cant[26][2];
		mset(cant,0);
		for(auto i:a)cant[i-'a'][0]++;
		for(auto i:b)cant[i-'a'][1]++;
		ll d[26];
		mset(d,0);
		fore(i,0,26)d[i]=cant[i][0]-cant[i][1];
		ll br=0;
		fore(i,0,26){
			if(abs(d[i])%k!=0){
				cout<<"NO\n";
				br++; break;
			}
		}
		if(br)continue;
		ll sum=0;
		fore(i,0,26){
			sum+=d[i];
			if(sum<0){
				cout<<"NO\n";
				br++; break;
			}
		}
		if(br)continue;
		cout<<"YES\n";
	}
	
	return 0;
}