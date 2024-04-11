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
	ll p[n];
	fore(i,0,n)cin>>p[i];
	ll u[n+1];
	fore(i,0,n)u[p[i]]=i;
	//ll vis[n+1];
	set<ll> s;
	s.insert(-1);
	s.insert(n);
	ll res=0;
	for(int i=n;i>=1;i--){
		ll lb=*s.lower_bound(u[i]);
		auto it=s.upper_bound(u[i]);
		it--;
		ll ub=*(it);
		if(n-lb>ub+1){
			fore(j,u[i]+1,lb){
				if(ub<u[i-p[j]]&&u[i-p[j]]<u[i])res++;//,cout<<p[j]<<" "<<i-p[j]<<"\n";
			}
		}else{
			fore(j,ub+1,u[i]){
				if(u[i]<u[i-p[j]]&&u[i-p[j]]<lb)res++;//,cout<<p[j]<<" "<<i-p[j]<<"\n";
			}
		}
		//cout<<lb<<" "<<ub<<"\n";
		s.insert(u[i]);
	}
	cout<<res;
	return 0;
}