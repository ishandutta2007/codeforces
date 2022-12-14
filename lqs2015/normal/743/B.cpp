#include<iostream>
using namespace std;
long long k,n,t,ans,x[111],y[111],c,cc;
int main()
{
	cin>>n>>k;
	t=k-1;
	while(k)
	{
		x[c++]=k%2;
		k/=2;
	}
	while(t)
	{
		y[cc++]=t%2;
		t/=2;
	}
	for (int i=0;i<c;i++)
	{
		if (x[i]!=y[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}