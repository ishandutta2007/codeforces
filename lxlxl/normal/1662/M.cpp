#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int mxr=0,mxw=0;
		for(int i=1;i<=m;i++)
		{
			int r,w;
			cin>>r>>w;
			mxr=max(mxr,r);
			mxw=max(mxw,w);
		}
		if(mxr+mxw<=n)
		{
			for(int i=1;i<=mxr;i++)cout<<'R';
			for(int i=1;i<=mxw;i++)cout<<'W';
			for(int i=mxr+mxw+1;i<=n;i++)cout<<'R';
			cout<<'\n';
		}
		else
		{
			cout<<"IMPOSSIBLE\n";
		}
	}
	return 0;
}