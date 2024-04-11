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
	ll a[n],b[n];
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i],b[i]--;
	ll ord[n];
	fore(i,0,n){
		ord[a[i]]=i;
	}
	//fore(i,0,n)cout<<ord[i]<<" "; cout<<"\n";
	ll mini=n;
	ll res=0;
	fore(i,0,n){
		if(ord[b[n-1-i]]>mini)res++;//,cout<<b[n-1-i]<<" ";
		mini=min(mini,ord[b[n-1-i]]);
	}
	cout<<res;
	return 0;
}