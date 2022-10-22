#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010],h[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,k,i;cin>>n>>k;
		for (i=1;i<=n;i++) h[i]=0;
		for (i=1;i<=n;i++) {cin>>a[i];h[a[i]]++;}
		int x=0;while (x-(n-x)<k) x++;
		int l,r,res=n+1,nw=0,s=0;
		for (i=1;i<=n;i++)
		{
			while (nw<n && s<x) nw++,s+=h[nw];
			if (s>=x && nw-i+1<res) res=nw-i+1,l=i,r=nw;
			s-=h[i];
		}
		cout<<l<<' '<<r<<endl;s=0;int lst=0;k--;
		for (i=1;i<=n && k;i++)
		{
			if (a[i]<=r && a[i]>=l) s++;else s--;
			if (s==1) {cout<<lst+1<<' '<<i<<endl;lst=i;s=0;k--;}
		}
		cout<<lst+1<<' '<<n<<endl;
	}
}