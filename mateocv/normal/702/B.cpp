#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	map<ll,ll> m; ll lle;
	fore(i,0,n){
		cin>>lle;
		if(!m.count(lle)){
			m[lle]=1;
		}else{
			m[lle]++;
		}
	}
	ll res=0;
	for(auto i:m){
		fore(j,1,31){
			if(m.count((1<<j)-i.fst)&&(1<<j)>i.fst){
				res+=i.snd*m[(1<<j)-i.fst];
				if(i.fst==(1<<j)-i.fst)res-=i.snd;
			}
		}
	}
	//cout<<(1<<30);
	cout<<res/2;
	return 0;
}