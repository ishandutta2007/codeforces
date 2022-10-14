#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
priority_queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int x;cin>>x;
		if(q.push(x),x<q.top())
			ans+=q.top()-x,q.pop(),q.push(x);
	}
	cout<<ans<<"\n";
	return 0;
}