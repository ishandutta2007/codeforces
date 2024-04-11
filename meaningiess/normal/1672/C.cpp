#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,s1=0,s2=0;cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<n;i++) if (a[i]==a[i+1]) {s1=i;break;}
		for (i=1;i<n;i++) if (a[i]==a[i+1]) s2=i;
		if (s1==s2) {puts("0");continue;}
		cout<<max(1,s2-s1-1)<<endl;
	}
}