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
	string s; cin>>s;
	ll res=0;
	ll l=-1,r=SZ(s);
	vector<ll> v[2];
	while(1){
		//cout<<l<<" "<<r<<endl;
		ll br=0;
		fore(i,l+1,r){
			/*if(i<0){
				continue;
			}*/
			if(s[i]=='('){
				v[0].pb(i);
				l=i; res++; break;
			}
			if(i+1==r)br++;
		}
		if(br||l+1==r)break;
		for(ll i=r-1;i>l;i--){
			/*if(i==SZ(s)){
				continue;
			}*/
			if(s[i]==')'){
				v[1].pb(i);
				r=i; res++; break;
			}
			if(i-1==l)br++;
		}
		if(br||l+1==r)break;
	}
	if(res<2){
		cout<<0; return 0;
	}
	cout<<"1\n"<<res-res%2<<"\n";
	fore(i,0,res/2)cout<<v[0][i]+1<<" ";
	reverse(ALL(v[1]));
	fore(i,0,res/2)cout<<v[1][i]+1<<" ";
	
	
	return 0;
}