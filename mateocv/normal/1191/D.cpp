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
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	map<ll,ll> mp;
	fore(i,0,n)mp[a[i]]++;
	if((mp.count(0)&&mp[0]>=2)){
		cout<<"cslnb"; return 0;
	}
	ll tot=0,ind=-1;
	for(auto i:mp){
		if(i.snd>=3){
			cout<<"cslnb"; return 0;
		}
		if(i.snd>=2){
			tot++,ind=i.fst;
			if(tot>=2){
				cout<<"cslnb"; return 0;
			}
		}
	}
	if(mp.count(ind-1)){
		cout<<"cslnb"; return 0;
	}
	sort(a,a+n);
	fore(i,0,n){
		res+=max(0ll,a[i]-i);
	}
	if(res%2==0){
		cout<<"cslnb";
	}else{
		cout<<"sjfnb";
	}
	return 0;
}