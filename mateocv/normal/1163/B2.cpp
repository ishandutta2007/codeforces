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

set<ll> s[100005];
ll ap[100005];

int main(){FIN;
	ll n; cin>>n;
	ll tot=0, maxi=0;
	ll co, res=0;
	fore(i,1,n+1){
		cin>>co;
		if(ap[co]==0){
			ap[co]=1;
			s[1].insert(co);
			tot++;
			if(maxi==0)maxi=1;
		}else{
			ap[co]++;
			s[ap[co]].insert(co);
			s[ap[co]-1].erase(co);
			maxi=max(maxi,ap[co]);
		}
		if(tot==1)res=i;
		else if(maxi==1) res=i;
		else if((maxi-1)*(SZ(s[maxi-1])+1)==i-1)res=i;
		else if(SZ(s[maxi])*maxi==i-1)res=i;
	}
	cout<<res;
	return 0;
}