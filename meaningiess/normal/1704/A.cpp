#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;cin>>n>>m;
		string a,b;cin>>a>>b;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		for (i=0;i<m;i++) if (a[i]!=b[i]) break;
		if (i<m-1) {puts("NO");continue;}
		int tp[2]={(a[n-1]=='0'),(a[n-1]=='1')};
		for (i=n-2;i>=m-1;i--)
		{
			if (tp[0] && tp[1]) continue;
			tp[a[i]-'0']=1;
		}
		if (tp[b[m-1]-'0']) puts("YES");else puts("NO");
	}
}