#include<bits/stdc++.h>
#define int long long
using namespace std;
int const pr[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,ans=LLONG_MAX;
void solve(int cur,int t,int pre,int cnt){
	if(cnt>n||t>16)
		return;
	if(cnt==n){
		ans=cur;return;
	}
	for(int i=1;i<=pre;i++)
		if(1.0*cur*pr[t]<ans)
			solve(cur*=pr[t],t+1,i,cnt*(i+1));
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,solve(1,1,64,1),cout<<ans<<"\n";
}//