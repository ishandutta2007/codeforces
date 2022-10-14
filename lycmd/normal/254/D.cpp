#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int const N=1010,M=305,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,d,tot,vis[N][N],f[N][N],ord[N][N];
node pos[N];
set<node>s;
vector<node>r,w,c;
bitset<M>sta[N];
char a[N][N];
queue<pair<node,int> >q;
void bfs1(node s,vector<node>&c){
	q.push({s,0}),vis[s.first][s.second]=1;
	while(!q.empty()){
		node t=q.front().first;
		int w=q.front().second;q.pop();
		c.push_back(t);
		if(w==d)continue;
		for(int i=0;i<4;i++){
			int tx=t.first+dx[i],ty=t.second+dy[i];
			if(a[tx][ty]=='X'||vis[tx][ty])
				continue;
			vis[tx][ty]=1,q.push({{tx,ty},w+1});
		}
	}
	for(node i:c)
		vis[i.first][i.second]=0;
}
void bfs2(node s,bitset<M>&res){
	vector<node>c;
	q.push({s,0}),vis[s.first][s.second]=1;
	while(!q.empty()){
		node t=q.front().first;
		int w=q.front().second;q.pop();
		c.push_back(t);
		if(ord[t.first][t.second])
			res[ord[t.first][t.second]-1]=1;
		if(w==d)continue;
		for(int i=0;i<4;i++){
			int tx=t.first+dx[i],ty=t.second+dy[i];
			if(a[tx][ty]=='X'||vis[tx][ty])
				continue;
			vis[tx][ty]=1,q.push({{tx,ty},w+1});
		}
	}
	for(node i:c)
		vis[i.first][i.second]=0;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='R')
				r.push_back({i,j}),ord[i][j]=r.size();
			if(a[i][j]!='X')
				w.push_back({i,j});
		}
	if(r.size()>290)
		cout<<"-1\n",exit(0);
	for(auto&i:r){
		c.clear();
		bfs1(i,c);
		for(auto&j:c)
			if(!s.count(j))
				s.insert(j),pos[++tot]=j,bfs2(j,sta[tot]);
	}
	for(int i=1;i<=tot;i++)
		if(sta[i].count()==r.size()){
			node j=pos[i]==w[0]?w[1]:w[0];
			cout<<pos[i].first<<" "<<pos[i].second<<" "
				<<j.first<<" "<<j.second<<"\n",exit(0);
		}
	for(int i=1;i<=tot;i++)
		for(int j=i+1;j<=tot;j++)
			if((sta[i]|sta[j]).count()==r.size())
				cout<<pos[i].first<<" "<<pos[i].second<<" "
					<<pos[j].first<<" "<<pos[j].second<<"\n",exit(0);
	cout<<"-1\n";
}