#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll ksm(int a,int b)
{
	ll res=1;
	while (b){if (b&1) res*=a;a*=a;b>>=1;}
	return res;
}
int main()
{
	int n,i,cnt,x;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;cnt=__builtin_popcount(x);
		cout<<ksm(2,cnt)<<endl;
	}
}