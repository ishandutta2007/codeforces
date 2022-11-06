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
	ll q[n-1],va=1,mini=300000;
	fore(i,0,n-1){
		cin>>q[i];
		mini=min(mini,va);
		va+=q[i];
		mini=min(mini,va);
	}
	ll res[n],cop[n];
	res[0]=2-mini;
	cop[0]=res[0];
	fore(i,1,n){
		res[i]=res[i-1]+q[i-1];
		cop[i]=res[i];
	}
	sort(cop,cop+n);
	ll anda=0;
	fore(i,0,n){
		if(cop[i]==i+1)anda++;
	}
	if(anda==n){
		fore(i,0,n)cout<<res[i]<<" ";
	}else{
		cout<<-1;
	}
	/*va=2-mini;
	cout<<va<<" ";
	fore(i,0,n-1){
		cout<<va+q[i]<<" ";
		va+=q[i];
	}*/
	
	return 0;
}