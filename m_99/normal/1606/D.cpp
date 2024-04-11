#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector a(n,vector<int>(m));
		rep(i,n){
			rep(j,m){
				scanf("%d",&a[i][j]);
			}
		}
		vector mini(n,vector<int>(m,Inf));
		vector minip(n,vector<int>(m,Inf));
		vector maxi(n,vector<int>(m,-Inf));
		
		rep(i,n){
			for(int j=m-2;j>=0;j--){
				mini[i][j] = min(mini[i][j+1],a[i][j+1]);
				maxi[i][j] = max(maxi[i][j+1],a[i][j+1]);
			}
			minip[i][0] = a[i][0];
			for(int j=1;j<m;j++){
				minip[i][j] = min(minip[i][j-1],a[i][j]);
			}
		}
		int ans = -1;
		string s = "";
		vector<int> bs(n,-Inf);
		rep(i,m-1){
			vector<pair<int,int>> ps(n);
			rep(j,n){
				bs[j] = max(bs[j],a[j][i]);
				ps[j] = make_pair(bs[j],j);
			}
			sort(ps.begin(),ps.end());
			vector<int> mini2(n,Inf),maxi2(n,-Inf);
			for(int j=n-2;j>=0;j--){
				mini2[j] = min(mini2[j+1],minip[ps[j+1].second][i]);
				maxi2[j] = max(maxi2[j+1],maxi[ps[j+1].second][i]);
			}
			
			int cm = Inf;
			rep(j,n-1){
				cm = min(cm,mini[ps[j].second][i]);
			
				if((cm>maxi2[j]) && ps[j].first!=ps[j+1].first && ps[j].first<mini2[j]){
					ans = i+1;
					s.resize(n,'A');
					rep(k,n){
						if(k<=j)s[ps[k].second] = 'B';
						else s[ps[k].second] = 'R';
					}
					goto L;
					
					
				}
			}
			
			
		}
		L:;
		if(ans==-1)printf("NO\n");
		else{
			printf("YES\n");
			cout<<s<<' '<<ans<<endl;
		}
		
	}
	
	return 0;
	
}