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
	ll n; cin>>n;
	string s,t; cin>>s>>t;
	vector<ll> v1,v2;
	fore(i,0,n){
		if(s[i]=='a'&&t[i]=='b')v1.pb(i);
		if(s[i]=='b'&&t[i]=='a')v2.pb(i);
	}
	if((SZ(v1)+SZ(v2))%2==1){
		cout<<-1; return 0;
	}
	cout<<(SZ(v1)+SZ(v2))/2+(SZ(v1)%2)<<"\n";
	fore(i,0,SZ(v1)/2){
		cout<<v1[2*i]+1<<" "<<v1[2*i+1]+1<<"\n";
	}
	fore(i,0,SZ(v2)/2){
		cout<<v2[2*i]+1<<" "<<v2[2*i+1]+1<<"\n";
	}
	if(SZ(v1)%2){
		cout<<v1.back()+1<<" "<<v1.back()+1<<"\n";
		cout<<v1.back()+1<<" "<<v2.back()+1<<"\n";
	}
	
	return 0;
}