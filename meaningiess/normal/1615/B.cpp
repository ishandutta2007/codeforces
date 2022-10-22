#include<bits/stdc++.h>
#define ll long long
using namespace std;
int s[200010][20];
int main()
{
	int T;cin>>T;
	int i,j;
	for (i=1;i<=200000;i++) for (j=0;j<19;j++) {s[i][j]=s[i-1][j];if (i&(1<<j)) s[i][j]++;}
	while (T--)
	{
		int l,r;cin>>l>>r;
		int mx=0;
		for (i=0;i<19;i++) mx=max(mx,s[r][i]-s[l-1][i]);
		cout<<r-l+1-mx<<endl;
	}
}