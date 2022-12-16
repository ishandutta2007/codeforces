#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
const int N=200200;
int n,m,k;
int p[N];
VI ins[N];
VI ous[N];
int dis[N];
void ae(int u,int v){
	ous[u].push_back(v);
	ins[v].push_back(u);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		ae(u,v);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>p[i];
	}
	queue<int> q;
	dis[p[k]]=1;
	q.push(p[k]);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int out:ins[x]){
			if(dis[out]==0){
				dis[out]=dis[x]+1;
				q.push(out);
			}
		}
	}
	int mn=0,mx=0;
	for(int i=1;i<k;i++){
		int dmn=1,dmx=0;
		if(dis[p[i]]==dis[p[i+1]]+1){
			dmn=0;
		}
		else{
			dmx=1;
		}
		for(int out:ous[p[i]]){
			if(out!=p[i+1]&&dis[p[i]]==dis[out]+1){
				dmx=1;
			}
		}
		mn+=dmn;
		mx+=dmx;
	}
	cout<<mn<<" "<<mx<<endl;
	return 0;
}