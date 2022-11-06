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

ll ask(string s, ll x, ll y){
	cout<<s<<" "<<x+1<<" "<<y+1<<endl;
	ll res; cin>>res;
	return res;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll> s;
	fore(i,0,3){
		s.pb(ask("or",i,(i+1)%3)+ask("and",i,(i+1)%3));
	}
	vector<ll> res(n);
	fore(i,0,3){
		res[i]=(s[0]+s[1]+s[2])/2-s[(i+1)%3];
	}
	fore(i,3,n){
		res[i]=res[0]^ask("or",0,i)^ask("and",0,i);
	}
	sort(ALL(res));
	cout<<"finish "<<res[k-1]<<endl;
	
	return 0;
}