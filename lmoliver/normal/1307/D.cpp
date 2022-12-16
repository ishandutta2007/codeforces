#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
const int N=200200;
int a[N];
VI es[N];
int dis1[N],dis2[N];
void bfs1(int s){
	queue<int> q;
	q.push(s);
	dis1[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int out:es[x]){
			if(dis1[out]==0){
				dis1[out]=dis1[x]+1;
				q.push(out);
			}
		}
	}
}
void bfs2(int s){
	queue<int> q;
	q.push(s);
	dis2[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int out:es[x]){
			if(dis2[out]==0){
				dis2[out]=dis2[x]+1;
				q.push(out);
			}
		}
	}
}
// d1[i]+d2[j]<=..
// d1[i]-d2[i]<=d1[j]-d2[j]
struct BIT{
	static const int M=N*3;
	int a[M];
	BIT(){
		clear();
	}
	void clear(){
		for(int i=0;i<M;i++){
			a[i]=INT_MIN;
		}
	}
	void set(int x,int v){
		for(x+=M/2;x<M;x+=x&-x){
			a[x]=max(a[x],v);
		}
	}
	int query(int x){
		int ans=INT_MIN;
		x+=M/2;
		for(;x>0;x-=x&-x){
			ans=max(ans,a[x]);
		}
		return ans;
	}
};
BIT b;
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	while(m--){
		int u,v;
		cin>>u>>v;
		es[u].push_back(v);
		es[v].push_back(u);
	}
	bfs1(1);
	bfs2(n);
	for(int i=1;i<=n;i++){
		dis1[i]--;
		dis2[i]--;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		int x=a[i];
		int d=-(dis1[x]-dis2[x]);
		// cerr<<x<<" "<<dis1[x]<<" "<<b.query(d)<<endl;
		ans=max(ans,dis1[x]+b.query(d)+1);
		b.set(d,dis2[x]);
	}
	b.clear();
	for(int i=k;i>=1;i--){
		int x=a[i];
		int d=-(dis1[x]-dis2[x]);
		// cerr<<x<<" "<<dis1[x]<<" "<<b.query(d)<<endl;
		ans=max(ans,dis1[x]+b.query(d)+1);
		b.set(d,dis2[x]);
	}
	// cerr<<ans<<endl;
	ans=min(ans,dis1[n]);
	cout<<ans<<endl;
	return 0;
}