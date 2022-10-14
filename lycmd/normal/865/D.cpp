#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int x;cin>>x;
		if(!q.empty()&&q.top()<x)
		    ans+=x-q.top(),q.pop(),q.push(x);
		q.push(x);
	}
	cout<<ans<<"\n";
}