#include<bits/stdc++.h>
#define int long long
using namespace std;
int const dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,ans;
vector<vector<int> >a;
vector<pair<int,int> >bl;
set<array<int,4> >s;
int test(int i,int j){
	if(a[i][j]==1)return 1;
	for(int p=0;p<4;p++){
		int tx=i+dx[p],ty=j+dy[p];
		if(tx<0||ty<0||tx>=n||ty>=m)continue;
		if(a[tx][ty]<a[i][j])
			return 1;
	}
	return 0;
}
int check(){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!test(i,j))
				return 0;
	return 1;
}
int check1(){
	for(auto t:bl)
		if(!test(t.first,t.second))
			return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,a.resize(n);
	for(auto&i:a)i.resize(m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	if(check())
		cout<<"0\n",exit(0);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]==1||!test(i,j)){
				bl.push_back({i,j});
				for(int p=0;p<4;p++){
					int tx=i+dx[p],ty=j+dy[p];
					if(tx<0||ty<0||tx>=n||ty>=m)continue;
					bl.push_back({tx,ty});
				}
			}
	sort(bl.begin(),bl.end());
	bl.erase(unique(bl.begin(),bl.end()),bl.end());
	if(bl.size()>15)
		cout<<"2\n",exit(0);
	for(int i=0;i<(int)bl.size();i++)
		for(int x=0;x<n;x++)
			for(int y=0;y<m;y++){
				int cnt=0;
				bl.push_back({x,y}),cnt++;
				for(int p=0;p<4;p++){
					int tx=x+dx[p],ty=y+dy[p];
					if(tx<0||ty<0||tx>=n||ty>=m)continue;
					bl.push_back({tx,ty}),cnt++;
				}
				swap(a[bl[i].first][bl[i].second],a[x][y]);
				if(check1()){
					if(!s.count({x,y,bl[i].first,bl[i].second}))
						s.insert({bl[i].first,bl[i].second,x,y});
				}
				swap(a[bl[i].first][bl[i].second],a[x][y]);
				while(cnt--)
					bl.pop_back();
			}
	if(s.size())
		cout<<"1 "<<s.size()<<"\n";
	else
		cout<<"2\n";
}