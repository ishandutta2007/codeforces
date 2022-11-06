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
	ll n,t; cin>>n>>t;
	ll s[n],d[n];
	fore(i,0,n)cin>>s[i]>>d[i];
	ll res=0,mini=1ll*1e18;
	fore(i,0,n){
		if(s[i]>=t){
			if(s[i]<mini){
				mini=s[i];
				res=i+1;
			}
			continue;
		}
		fore(j,1,100001){
			if(s[i]+j*d[i]>=t){
				if(s[i]+j*d[i]<mini){
					mini=s[i]+j*d[i];
					res=i+1;
				}
				break;
			}
		}
	}
	cout<<res;
	
	return 0;
}