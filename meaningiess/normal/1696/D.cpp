#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[250005],b[250005],c[250005];
stack<int> s1,s2;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,d=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++)
		{
			while (!s1.empty() && a[s1.top()]>a[i]) b[s1.top()]=i,s1.pop();
			while (!s2.empty() && a[s2.top()]<a[i]) c[s2.top()]=i,s2.pop();
			s1.push(i);s2.push(i);
		}
		while (!s1.empty()) b[s1.top()]=n+1,s1.pop();
		while (!s2.empty()) c[s2.top()]=n+1,s2.pop();
		for (i=1;i<n;) if (a[i]<a[i+1])
		{
			int l=b[i];d++;
			for (;i<l;i=c[i])
			{
				if (c[i]>=l) break;
			}
		}
		else
		{
			int l=c[i];d++;
			for (;i<l;i=b[i])
			{
				if (b[i]>=l) break;
			}
		}
		cout<<d<<endl;
	}
}