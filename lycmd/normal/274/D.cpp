#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,cur,in[N];
vector<int>e[N],ans;
vector<pair<int,int> >t;
queue<int>q;
void add_edge(int x,int y){
	e[x].push_back(y),in[y]++;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,cur=m;
	for(int i=1;i<=n;i++,cur++){
		t.clear(),t.resize(m);
		for(int j=0;j<m;j++)
			cin>>t[j].first,t[j].second=j+1;
		sort(t.begin(),t.end());
		for(int j=0;j<m;j++){
			cur+=!j||t[j].first!=t[j-1].first;
			if(!~t[j].first)
				continue;
			add_edge(cur,t[j].second);
			add_edge(t[j].second,cur+1);
		}
	}
	for(int i=1;i<=cur;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(x<=m)
			ans.push_back(x);
		for(int y:e[x])
			if(!--in[y])
				q.push(y);
	}
	if(ans.size()<m)
		cout<<-1;
	else
		for(int i:ans)
			cout<<i<<" ";
	cout<<"\n"; 
}