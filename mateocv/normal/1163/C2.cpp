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
	ll p[n][2];
	fore(i,0,n)fore(k,0,2)cin>>p[i][k];
	set<pair<pair<ll,ll>,ll>> l;
	fore(i,0,n){
		fore(j,i+1,n){
			pair<pair<ll,ll>,ll> pa;
			ll a=p[i][1]-p[j][1], b=p[j][0]-p[i][0], c=p[i][0]*p[j][1]-p[j][0]*p[i][1];
			if(a<0)a*=-1,b*=-1,c*=-1;
			if(a==0&&b<0)b*=-1,c*=-1;
			ll g=abs(__gcd(__gcd(a,b),c));
			a/=g,b/=g,c/=g;
			pa={{a,b},c};
			l.insert(pa);
		}
	}
	map<pair<ll,ll>,ll>m;
	for(auto i:l){
		m[i.fst]++;
	}
	ll sum=0,res=0;
	for(auto i:m){
		sum+=i.snd;
	}
	for(auto i:m){
		res+=i.snd*(sum-i.snd);
	}
	//for(auto i:l)cout<<i.fst<<" "<<i.snd.fst<<" "<<i.snd.snd<<"\n";
	cout<<res/2;
	return 0;
}