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

vector<ll> rb(ll n, ll b, ll c){
	vector<ll> res;
	fore(_,0,c){
		res.pb(n%b);
		n/=b;
	}
	reverse(ALL(res));
	return res;
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll pw=1,c=0;
	while(pw<n){
		pw*=k;
		c++;
	}
	cout<<c<<"\n";
	fore(i,0,n){
		fore(j,i+1,n){
			auto ri=rb(i,k,c),rj=rb(j,k,c);
			fore(ii,0,c){
				if(ri[ii]!=rj[ii]){
					cout<<ii+1<<" ";
					break;
				}
			}
		}
	}
	cout<<"\n";
	
	return 0;
}