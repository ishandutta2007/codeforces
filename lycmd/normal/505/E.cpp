#include<bits/stdc++.h>
#define node pair<int,int>
#define int long long
#define day first
#define id second
using namespace std;
int const N=233333;
int n,m,k,p,h[N],a[N],cnt[N];
priority_queue<node,vector<node>,greater<node> >q; 
int check(int x){
	q=priority_queue<node,vector<node>,greater<node> >();
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)
		if(x-a[i]*m<h[i])q.push(make_pair(x/a[i],i));
	for(int i=1;!q.empty()&&i<=m;i++)
		for(int j=1;!q.empty()&&j<=k;j++){
			if(q.empty())goto end;
			node t=q.top();q.pop();
			if(t.day<i)return 0;
			cnt[t.id]++;
			if(x+cnt[t.id]*p-a[t.id]*m<h[t.id])
				q.push(make_pair(x+cnt[t.id]*p/a[t.id],t.id));
		}
	end:return q.empty();
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++)cin>>h[i]>>a[i];
	int l=0,r=1e13;
	while(l<r-1){
		int mid=l+r>>1;
		if(check(mid))r=mid;else l=mid;
	} 
	cout<<r<<endl;
}