#include<bits/stdc++.h>
using namespace std;
int n,m,c,t[1005];
int main()
{
	for(cin>>n>>m>>c,memset(t,0,sizeof(t));m--;)
	{
		int x;cin>>x;
		if((x<<1)<=c) {for(int i=1;i<=n;i++) if(t[i]>x||!t[i]) {t[i]=x,cout<<i<<endl;break;}}
		else {for(int i=n;i>=1;i--) if(t[i]<x||!t[i]) {t[i]=x,cout<<i<<endl;break;}}
		fflush(stdout);
	}
	return 0;
}