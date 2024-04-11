#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(S);N<=(int)(E);N++)
const int N=300300;
LL a[N];
typedef pair<LL,int> P;
queue<P> q1,q2;
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v,d;
		cin>>u>>v>>d;
		a[u]+=d;
		a[v]-=d;
	}
	F(i,1,n){
		if(a[i]>0)q1.push(P(a[i],i));
		if(a[i]<0)q2.push(P(-a[i],i));
	}
	vector<pair<P,LL> > ans;
	while(!q1.empty()&&!q2.empty()){
		LL mx=min(q1.front().first,q2.front().first);
		ans.push_back(make_pair(P(q1.front().second,q2.front().second),mx));
		q1.front().first-=mx;
		q2.front().first-=mx;
		while(!q1.empty()&&q1.front().first==0)q1.pop();
		while(!q2.empty()&&q2.front().first==0)q2.pop();
	}
	cout<<ans.size()<<endl;
	F(i,0,ans.size()-1){
		cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
	}
	return 0;
}