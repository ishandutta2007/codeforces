#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s;
int sum[N];
signed main()
{
	cin>>n>>q>>s;
	s='$'+s;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+(s[i]-'a'+1);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<endl;
	}
	return 0;
}