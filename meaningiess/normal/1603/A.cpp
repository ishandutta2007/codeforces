#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x,ll y){return !y?x:gcd(y,x%y);}
int a[100010];
int main()
{
	int T,n,i;cin>>T;
	while (T--)
	{
		cin>>n;int flg=1;ll tp=1;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];
			if (tp<=1e9)tp=tp/gcd(tp,i+1)*(i+1);
			if (a[i]%tp==0) flg=0;
		}
		if (flg) puts("YES");else puts("NO");
	}
}