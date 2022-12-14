#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300005];
bool judge(int n)
{
	bool flag = true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}
signed main()
{
	int tt; cin>>tt;
	memset(a,0,sizeof(a));
	for(int i=2;i<=30004;i++)
	{
		if(judge(i))
		{
			a[i] = 1;
		}
	}
	
	while(tt--)
	{
		int n;cin>>n;
		int b = n+1;
		while(a[b]!=1) b++;
		int c = b+n;
		while(a[c]!=1) c++;
		int e = __gcd(b,c);
		int f = b*c/e;
		cout<<f<<endl;
	}
 }