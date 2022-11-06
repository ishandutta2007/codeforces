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

vector<pair<ll,ll>> v={{0,0},{0,1},{0,2},{0,-1},{0,-2},{1,0},{2,0},{-1,0},{-2,0},{1,2},{2,1},{2,2},{-1,-2},{-2,-1},{-2,-2}};

vector<pair<ll,ll>> gen(ll n){
	auto res=v;
	fore(i,0,SZ(res)){
		res[i].fst+=n;
		res[i].snd+=n;
	}
	return res;
} 

int main(){FIN;
	ll n; cin>>n;
	set<pair<ll,ll>> res;
	fore(i,0,n){
		auto p=gen(2*i);
		for(auto i:p)res.insert(i);
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	
	return 0;
}