#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,a[100010],b[100010],s[100010];
int dfs(int x)
{
	if (x==n+1) return 1;
	for (int i=0;i<4;i++)
	{
		if ((s[x-1]|i)==a[x-1] && (s[x-1]&i)==b[x-1])
		{
			s[x]=i;if (dfs(x+1)) return 1;
		}
	}
	return 0;
}
int main()
{
	int i;cin>>n;
	for (i=1;i<n;i++) cin>>a[i];
	for (i=1;i<n;i++) cin>>b[i];
	for (i=0;i<4;i++) {s[1]=i;if (dfs(2)) break;}
	if (i==4) {cout<<"NO";return 0;}cout<<"YES"<<endl;
	for (i=1;i<=n;i++) cout<<s[i]<<' ';
}