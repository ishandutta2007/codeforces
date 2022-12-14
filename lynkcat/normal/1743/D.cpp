#include<bits/stdc++.h>
using namespace std;
int n;
string st;
void fc()
{
	long long sum=0,val=0;
	cin>>n;
	cin>>st;
	int l=-1;
	for (int i=0;i<st.size();i++)
		if (st[i]=='1')
		{
			break;
		}  else l=i;
	string st1;
	for (int i=l+1;i<st.size();i++) st1+=st[i];
	st=st1;
	n=st.size();
	if (n==0) return cout<<0<<'\n',void();
	int nw=0;
	int len=1;
	for (int i=2;i<=n;i++)
	{
		int l=0,r=0;
		for (int j=min(n-len,n-i);j<n;j++)
		{
			int x=st[j]-'0';
			int y=st[j]-'0';
			if (j>=n-len) x|=st[l]-'0',l++;
			if (j>=n-i) y|=st[r]-'0',r++;
			// cout<<"?"<<len<<" "<<i<<" "<<x<<" "<<y<<" "<<j<<'\n';
			if (x^y)
			{
				if (x<y)
				{
					len=i;
				}
				break;
			}
		}
	}
	// cout<<"?"<<len<<'\n';
	for (int i=0;i<n-len;i++) cout<<st[i];
	for (int i=n-len;i<n;i++)
		cout<<((st[i]-'0')|(st[i-(n-len)]-'0'));
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int T=1;
	while (T--)
	{
		fc();
	}
}