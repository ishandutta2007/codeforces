#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,mn,a[100005],b[100005],c[100005],bl,cnt;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>n;mn=1000000001;
		for (int i=1;i<=n;i++)
		  cin>>a[i],mn=min(mn,a[i]);cnt=0;
		for (int i=1;i<=n;i++)
		  if (a[i]%mn==0)
		  {
		  	cnt++;
		  	b[cnt]=a[i];
		  	c[cnt]=i;
		  }
		sort(b+1,b+cnt+1);
		for (int i=1;i<=cnt;i++) a[c[i]]=b[i];
		bl=1;
		for (int i=1;i<=n;i++) { if (a[i]<a[i-1]) bl=0;}
		if (bl) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	}
}