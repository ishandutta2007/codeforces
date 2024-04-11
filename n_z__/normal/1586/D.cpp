#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[101];
int g[101];
main()
{
	int n;
	cin>>n;
	int now=1;
	for(int x=n;x>1;x--)
	{
		cout<<"? ";
		for(int y=1;y<n;y++)
		cout<<x<<' ';
		cout<<1<<endl;
		cout.flush();
		int y;
		cin>>y;
		if(y!=0)ans[now]=y,now++;
	}
	if(now==1){
		ans[1]=n;
	}
	if(now==n){
		ans[n]=n;
		goto nxt;
	}
	ans[now]=n;
	now++;
	for(int x=n-1;x>=1;x--)
	{
		cout<<"? ";
		for(int y=1;y<n;y++)
		cout<<x<<' ';
		cout<<n<<endl;
		cout.flush();
		int y;
		cin>>y;
		if(y!=0)ans[now]=y,now++;
	}
	nxt:cout<<"! ";
	for(int x=1;x<=n;x++)
	g[ans[x]]=x;
	for(int x=1;x<=n;x++)
	cout<<g[x]<<' ';
}