#include<bits/stdc++.h>
#define ll long long
using namespace std;
int p[111],q[111],a[111];
int main()
{
	int n,i,j,tp,nw;cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<'?';
		for (j=1;j<=n;j++) if (j!=i) cout<<" 1";else cout<<" 2";
		cout<<endl;cin>>tp;if (tp!=i) p[i]=tp;fflush(stdout);
	}
	for (i=1;i<=n;i++)
	{
		printf("?");
		for (j=1;j<=n;j++) if (j!=i) cout<<" 2";else cout<<" 1";
		cout<<endl;cin>>tp;if (tp!=i) q[tp]=i;if (tp==0) nw=i;fflush(stdout);
	}
	for (i=1;i<=n;i++)
	{
		a[nw]=i;
		if (p[nw]) nw=p[nw];else nw=q[nw];
	}
	cout<<"!";
	for (i=1;i<=n;i++) cout<<' '<<a[i];cout<<endl;fflush(stdout);
}