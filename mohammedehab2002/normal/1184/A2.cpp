#include <iostream>
#include <algorithm>
using namespace std;
bool b[200005],ok[200005];
int main()
{
	int n,ans=0;
	string s;
	cin >> n >> s;
	for (int i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			ok[i]=1;
			for (int j=0;j<i;j++)
			b[j]=0;
			for (int j=i;j<n;j++)
			b[j]=(b[j-i]^(s[j-i]-'0'));
			for (int j=0;j<i;j++)
			ok[i]&=(b[j]^(s[j-i+n]-'0')==b[j-i+n]);
		}
	}
	for (int i=1;i<=n;i++)
	ans+=ok[__gcd(i,n)];
	printf("%d",ans);
}