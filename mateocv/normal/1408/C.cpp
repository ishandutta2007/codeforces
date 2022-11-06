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
	ll t; cin>>t;
	cout<<fixed<<setprecision(15);
	while(t--){
		ll n,lar; cin>>n>>lar;
		ll a[n+2];
		a[0]=0;
		a[n+1]=lar;
		fore(i,0,n)cin>>a[i+1];
		n+=2;
		vector<double> vt[2]={{0},{0}};
		fore(i,0,n-1){
			double va=vt[0].back();
			va+=1.*(a[i+1]-a[i])/(i+1);
			vt[0].pb(va);
		}
		fore(i,0,n-1){
			double va=vt[1].back();
			va+=1.*(a[n-1-i]-a[n-2-i])/(i+1);
			vt[1].pb(va);
		}
	/*	fore(k,0,2){
			for(auto i:vt[k])cout<<i<<" "; cout<<"\n";
		}*/
		ll l=0,r=0;
		while(l+r<n-2){
			if(vt[0][l+1]<vt[1][r+1]){
				l++;
			}else{
				r++;
			}
		}
		double pos[2];
		pos[0]=a[l];
		pos[1]=a[n-1-r];
		if(vt[0][l]<vt[1][r]){
			pos[0]+=(vt[1][r]-vt[0][l])*(l+1);
		}else{
			pos[1]-=(vt[0][l]-vt[1][r])*(r+1);
		}
		//cout<<pos[0]<<" "<<pos[1]<<"\n";
		double res=max(vt[0][l],vt[1][r])+(pos[1]-pos[0])/(l+r+2);
		cout<<res<<"\n";
	}
	
	return 0;
}