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

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n][m];
	ll maxi[n],mini[n];
	fore(i,0,n){
		mini[i]=1024;
	}
	mset(maxi,0);
	ll sum=0;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			mini[i]=min(mini[i],a[i][j]);
			maxi[i]=max(maxi[i],a[i][j]);
			if(j==0)sum^=a[i][j];
		}
	}
	//vector<ll> v;
	fore(i,0,n){
		if(maxi[i]!=mini[i]){
			sum^=a[i][0];
			if((sum^mini[i])>0){
				cout<<"TAK\n"; //cout<<sum<<" ";
				fore(j,0,n){
					if(j!=i){
						cout<<1<<" ";	
					}else{
						fore(r,0,m){
							if(a[i][r]==mini[i]){
								cout<<r+1<<" "; break;
							}
						}	
					}
				}
				return 0;
			}else if((sum^maxi[i])>0){
				cout<<"TAK\n"; //cout<<sum<<" "; //cout<<maxi[i];
				fore(j,0,n){
					if(j!=i){
						cout<<1<<" ";	
					}else{
						fore(r,0,m){
							if(a[i][r]==maxi[i]){
								cout<<r+1<<" "; break;
							}
						}	
					}
				}
				return 0;
			}
			sum^=a[i][0];
		}
	}
	if(sum>0){
		cout<<"TAK\n";
		fore(i,0,n)cout<<1<<" ";
		return 0;
	}	
	cout<<"NIE";
	
	return 0;
}