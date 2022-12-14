#include<iostream>
using namespace std;
int n,m,cnt,ans;
int main()
{
	cin>>n>>m;
	ans=1e9;
	if (n>=m)
	{
		cout<<n-m<<endl;
		return 0;
	}
	while(n!=m)
	{
		if (n>m) ans=min(ans,cnt+n-m); 
		if (m%2) m++;
		else m/=2;
		cnt++;
		if (m==1) break;
	}
	if (m!=1 || n==1) ans=min(ans,cnt);
	cout<<ans<<endl;
	return 0;
}