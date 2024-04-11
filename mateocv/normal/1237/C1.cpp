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
	ll a[n][3];
	fore(i,0,n)cin>>a[i][0]>>a[i][1]>>a[i][2];
	ll vis[n];
	mset(vis,0);
	fore(i,0,n){
		if(vis[i])continue;
		ll mini=1e18;
		ll minid=-1;
		fore(j,0,n){
			if(!vis[j]&&i!=j){
				if((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2])<mini){
					mini=(a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]);
					minid=j;
				}
			}
		}
		//cout<<mini<<"\n";
		cout<<i+1<<" "<<minid+1<<"\n";
		vis[minid]=1;
		vis[i]=1;
	}
	
	return 0;
}