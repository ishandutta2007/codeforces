#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,m,a[N],vis[N];
priority_queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=m;i++)
			cin>>a[i];
		sort(a+1,a+m+1),a[0]=a[m]-n;
		q=priority_queue<int>();
		for(int i=1;i<=m;i++)
			q.push(a[i]-a[i-1]-1);
		int ans=0,k=0;
		while(!q.empty()){
			int x=q.top()-k*2;q.pop();
			if(x<1)
				break;
			else if(x<3)
				k++,ans++;
			else
				k+=2,ans+=x-1;
		}
		cout<<n-ans<<"\n";
	}
    return 0;
}