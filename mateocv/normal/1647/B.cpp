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

bool valid(ll x, ll y, ll n, ll m){
	return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<string> s(n);
		fore(i,0,n)cin>>s[i];
		bool res=1;
		vector<pair<ll,ll>> dir={{0,1},{1,0},{0,-1},{-1,0}};
		fore(i,0,n){
			fore(j,0,m){
				if(s[i][j]=='1'){
					fore(ii,0,SZ(dir)){
						ll i1=i+dir[ii].fst,j1=j+dir[ii].snd;
						ll i2=i+dir[(ii+1)%4].fst,j2=j+dir[(ii+1)%4].snd;
						ll i3=i+dir[ii].fst+dir[(ii+1)%4].fst,j3=j+dir[ii].snd+dir[(ii+1)%4].snd;
						if(valid(i1,j1,n,m)&&valid(i2,j2,n,m)&&valid(i3,j3,n,m)){
							if(s[i1][j1]=='1'&&s[i2][j2]=='1'&&s[i3][j3]=='0'){
								res=0;
							}
						}
					}
				}
			}
		}
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}