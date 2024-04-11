#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5010;
int n,k,x,ans=-1,a[N],f[N][N];
deque<int>q[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(f,-1,sizeof f);
	q[0].push_back(f[0][0]=0);
	for(int i=1;i<=n;i++)
		for(int j=x;j;j--){
			while(q[j-1].size()&&q[j-1].front()<i-k)
				q[j-1].pop_front();
			if(!q[j-1].size())
				continue;
			f[i][j]=f[q[j-1].front()][j-1]+a[i];
			while(q[j].size()&&f[q[j].back()][j]<=f[i][j])
				q[j].pop_back();
			q[j].push_back(i);
		}
	for(int i=n-k+1;i<=n;i++)
		ans=max(ans,f[i][x]);
	cout<<ans<<"\n";
}
//