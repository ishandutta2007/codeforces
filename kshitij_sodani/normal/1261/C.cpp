//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,m;
vector<int> it[1000003];
vector<int> dist[1000003];
vector<int> ans[1000003];
vector<int> pre[1000003];
vector<int> x={0,0,1,-1,1,1,-1,-1};
vector<int> y={-1,1,0,0,-1,1,1,-1};
	int cur;
int co2=0;
bool check(int mi,bool pp=false){
	int co=0;
		queue<pair<int,int>> ss;
		vector<pair<int,int>> ee;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dist[i][j]=-1;
			int x=i-mi;
			int y=j-mi;
			if(x<1 or y<1){
				continue;
			}
			x+=2*mi;
			y+=2*mi;
			if(x>n or y>m){
				continue;
			}
			llo xx=pre[i+mi][j+mi]-pre[i+mi][j-mi-1]-pre[i-mi-1][j+mi]+pre[i-mi-1][j-mi-1];
			if(xx==(2*mi+1)*(2*mi+1)){
				ee.pb({i,j});
				dist[i][j]=0;
				ss.push({i,j});
			}
			
		}
	}

	while(ss.size()){
		pair<int,int> no=ss.front();
		ss.pop();
		co++;
		if(dist[no.a][no.b]<mi){
			for(int i=0;i<8;i++){
				int xx=no.a+x[i];
				int yy=no.b+y[i];
				/*if(xx>n+1 or yy>m+1){
					continue;
				}*/
				if(it[xx][yy]==1 and dist[xx][yy]==-1){
					dist[xx][yy]=dist[no.a][no.b]+1;
					ss.push({xx,yy});
				}
			}
		}
	}
	if(pp){
		for(auto j:ee){
			ans[j.a][j.b]=1;
		}
	}
	return co==co2;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=m+1;j++){
			dist[i].pb(-1);
			it[i].pb(0);
			ans[i].pb(0);
			pre[i].pb(0);
		}
	}
	
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='.'){
				it[i+1][j+1]=0;
			}
			else{
				it[i+1][j+1]=1;
				co2++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+it[i][j];
		}
	}
	/*
	int ma=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(it[i][j]==1 and vis[i][j]==0){
				cur=dist[i][j];
				dfs({i,j});
				ma=min(ma,cur);
			}
		}
	}*/
	
	int low=0;
	int high=max(n,m);
	while(low<high-1){
		int mid=(low+high)/2;
		if(check(mid)){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	int ac=low;
	if(check(high)){
		ac=max(ac,high);
	}
	cout<<ac<<endl;
	check(ac,true);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ans[i+1][j+1]==1){
				cout<<'X';
			}
			else{
				cout<<".";
			}
		}
		cout<<endl;
	}
	








 
	return 0;
}