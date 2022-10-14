#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int n,m,ans,f[N][26],in[N],vis[N];
string s;
vector<int>e[N];
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s,s=" "+s;
	for(int x,y;m--;){
		cin>>x>>y;
		e[x].push_back(y);
		in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i),f[i][s[i]-97]++;
	while(q.size()){
		int x=q.front();q.pop();
		for(int y:e[x]){
			for(int j=0;j<26;j++)
				f[y][j]=max(f[y][j],f[x][j]+(s[y]==j+97));
			if(!--in[y])
				q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(in[i])
			cout<<"-1\n",exit(0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			ans=max(ans,f[i][j]);
	cout<<ans<<"\n";
}//?