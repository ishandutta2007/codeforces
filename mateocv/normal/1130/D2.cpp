#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll> v[n];
	ll a,b;
	fore(i,0,m){
		cin>>a>>b;
		a--;b--;
		if(a<b){
			v[a].pb(b-a);	
		}else{
			v[a].pb(b+n-a);
		}
//		cout<<"holaaaaaa"<<endl;
	}
	ll cost[n];
	fore(i,0,n){
		if(SZ(v[i])){
			sort(v[i].rbegin(),v[i].rend());
			cost[i]=1ll*n*(SZ(v[i])-1)+v[i].back();
		//	cout<<"holaaaaaa"<<endl;	
		}else{
			cost[i]=0;
		}
		
	}
//	cout<<"holaaaaaa"<<endl;
	ll res[n];
	fore(i,0,n){
		ll maxi=0;
		fore(j,0,n){
		    if(SZ(v[(j+i)%n])){maxi=max(maxi,cost[(i+j)%n]+j);}
			
		}
		res[i]=maxi;
	}
	fore(i,0,n){
		cout<<res[i]<<" ";
	}
	return 0;
}