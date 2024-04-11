#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	map<int,int> cnt;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++; 
	}
	int nc=cnt.size(),c0=0,sum=0;
	for(int i=0;i<=n;i++)
		if(cnt[i]==0)
			c0++;
	priority_queue<int> q;
	for(auto x:cnt)
		if(x.first>n){
			q.push(x.second);
			sum+=x.second;
		}
	int res=nc;
	for(int i=n;i>=0;i--){
		c0-=cnt[i]==0;
		if(cnt[i]){
			q.push(cnt[i]);
			sum+=cnt[i];
		}
		while(sum>k)
			sum-=q.top(),q.pop();
		if(k<c0)continue;
		res=min(res,nc-(int)q.size()-i+c0);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}