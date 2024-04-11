#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,INF=0x3f3f3f3f;
int ans=INF,n[4];
set<pair<int,int> >s;
pair<int,int>a[4][N];
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<4;i++)
		cin>>n[i];
	for(int i=0;i<4;i++)
		for(int j=0;j<n[i];j++)
			cin>>a[i][j].first,a[i][j].second=j;
	for(int i=0,m,x,y;i<3;i++){
		s.clear(),a[i][n[i]]={INF,n[i]};
		sort(&a[i][0],&a[i][n[i]]);
		for(cin>>m;m--;)
			cin>>x>>y,s.insert({x-1,y-1});
		for(int y=0;y<n[i+1];y++)
			for(int x=0;x<=n[i];x++)
				if(!s.count({a[i][x].second,y})){
					a[i+1][y].first+=a[i][x].first;
					break;
				}
	}
	for(int i=0;i<n[3];i++)
		ans=min(ans,a[3][i].first);
	cout<<(ans<INF?ans:-1)<<"\n";
}