#include<bits/stdc++.h>
using namespace std;
int const N=5010;
int n,m,k,ans,in[N],f[N][N],pre[N][N];
vector<pair<int,int> >e[N];
vector<int>p; 
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		e[a].push_back({b,c}),in[b]++;
	}
	memset(f,0x3f,sizeof f),f[1][1]=0;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto i:e[x]){
			int y=i.first,w=i.second;
			for(int j=1;j<=n;j++)
				if(f[y][j]>f[x][j-1]+w&&f[x][j-1]+w<=k)
					f[y][j]=f[x][j-1]+w,pre[y][j]=x,y==n&&(ans=max(ans,j));
			if(!--in[y])q.push(y);
		}
	}
	for(int i=ans,cur=n;i;cur=pre[cur][i--])
		p.push_back(cur);
	reverse(p.begin(),p.end());
	cout<<p.size()<<"\n";
	for(int x:p)cout<<x<<" ";
}