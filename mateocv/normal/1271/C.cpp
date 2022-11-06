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
	ll s[2]; cin>>s[0]>>s[1];
	ll a[n][2];
	fore(i,0,n)cin>>a[i][0]>>a[i][1];
	fore(i,0,n)a[i][0]-=s[0],a[i][1]-=s[1];
	ll res[4]={0,0,0,0};
	fore(i,0,n){
		if(a[i][1]>0)res[0]++;
		if(a[i][0]>0)res[1]++;
		if(a[i][1]<0)res[2]++;
		if(a[i][0]<0)res[3]++;
	}
	pair<ll,ll> pos[4]={{0,1},{1,0},{0,-1},{-1,0}};
	ll maxi=max({res[0],res[1],res[2],res[3]});
	cout<<maxi<<"\n";
	fore(k,0,4){
		if(res[k]==maxi){
			cout<<s[0]+pos[k].fst<<" "<<s[1]+pos[k].snd; break;
		}
	}
	
	return 0;
}