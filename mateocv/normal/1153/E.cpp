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

vector<ll> resp[3];

void ask(ll a,ll b,ll c,ll d,ll e){
	cout<<"? "<<min(a,c)<<" "<<min(b,d)<<" "<<max(a,c)<<" "<<max(b,d)<<endl;
	ll l; cin>>l; resp[e].pb(l);
	if(l==-1)assert(0);
}

int main(){FIN;
	int n; cin>>n;
	fore(i,1,n+1){
		ask(i,1,i,n,0);
	}
	fore(i,1,n+1){
		ask(1,i,n,i,1);
	}
	ll imp[2][2]={-1,-1,-1,-1};
	fore(k,0,2){
		fore(i,0,n){
			if(resp[k][i]%2){
				if(imp[k][0]<0){
					imp[k][0]=i+1;
				}else{
					imp[k][1]=i+1;
				}
			}
		}
	}
	if(imp[0][0]!=-1&&imp[0][1]!=-1&&imp[1][0]!=-1&&imp[1][1]!=-1){
		ask(imp[0][0],imp[1][0],imp[0][0],imp[1][0],2);
		if(resp[2][0]%2){
			cout<<"! "<<imp[0][0]<<" "<<imp[1][0]<<" "<<imp[0][1]<<" "<<imp[1][1]<<endl;
		}else{
			cout<<"! "<<imp[0][1]<<" "<<imp[1][0]<<" "<<imp[0][0]<<" "<<imp[1][1]<<endl;
		}
		return 0;
	}
	//cout<<imp[0][0]<<endl;
	if(imp[0][0]==-1){
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			ask(l,imp[1][0],m,imp[1][0],2);
			if(resp[2].back()%2){
				r=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<"! "<<l<<" "<<imp[1][0]<<" "<<l<<" "<<imp[1][1]<<endl;
		return 0;
	}else{
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			ask(imp[0][0],l,imp[0][0],m,2);
			if(resp[2].back()%2){
				r=m-1;
			}else{
				l=m+1;
			}
		}
		cout<<"! "<<imp[0][0]<<" "<<l<<" "<<imp[0][1]<<" "<<l<<endl;
		return 0;
	}
	
	return 0;
}