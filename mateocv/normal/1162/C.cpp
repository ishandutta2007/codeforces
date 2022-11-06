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
	ll n,k; cin>>n>>k;
	ll a[k];
	fore(i,0,k)cin>>a[i];
	vector<ll> v[100005];
	fore(i,0,k){
		v[a[i]].pb(i);
	}
	ll res=0;
	fore(i,1,n+1){
		if(SZ(v[i])==0){
			if(i==1||i==n){res+=2;
			}else res+=3;
		}else{
			if(i>1){
				ll p=v[i][0];
				res++;
				fore(j,0,SZ(v[i-1])){
					if(v[i-1][j]>=p){res--;break;}
					//if(j==SZ(v[i-1])-1)res+=1/*,cout<<i<<" "<<i-1<<"\n"*/;
				}
			}
			if(i<n){
				ll p=v[i][0];
				res++;
				fore(j,0,SZ(v[i+1])){
					if(v[i+1][j]>=p){res--;break;}
					//if(j==SZ(v[i+1])-1)res+=1,/*cout<<i<<" "<<i-1<<"\n"*/;
				}
			}
		}
	}
	cout<<res;
	return 0;
}