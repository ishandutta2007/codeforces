#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=1000010;
vector<node>const dir={{-1,0},{0,-1},{0,1},{1,0}};
int t,n,m,sx,sy;
string s[N];
queue<node>q;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]="#"+s[i]+"#";
		s[0]=s[n+1]=string(m+2,'#');
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='L')
					sx=i,sy=j;
		for(auto i:dir){
			int tx=sx+i.first,ty=sy+i.second;
			if(s[tx][ty]=='.')
				q.push({tx,ty});
		}
		while(!q.empty()){
			node t=q.front();q.pop();
			int x=t.first,y=t.second,cnt=0;
			for(auto i:dir)
				cnt+=s[x+i.first][y+i.second]=='.';
			if(cnt<2){
				s[x][y]='+';
				for(auto i:dir){
					int tx=x+i.first,ty=y+i.second;
					if(s[tx][ty]=='.')
						q.push({tx,ty});
				}
			}
		}
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=m;j++)
				cout<<s[i][j];
	}
}