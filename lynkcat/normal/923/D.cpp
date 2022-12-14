// LUOGU_RID: 93606369
// Lynkcat.
// Problem: A. Picking Strings
// Contest: Codeforces - 11.11
// URL: https://codeforces.com/gym/409566/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
int q;
int s[N],s1[N];
int lst[N],lst1[N];
void BellaKira()
{
	string st,st1;
	cin>>st>>st1;
	int n=st.size(),m=st1.size();
	cin>>q;
	for (int i=1;i<=n;i++)
		if (st[i-1]!='A') s[i]=s[i-1]+1,lst[i]=i;
		else s[i]=s[i-1],lst[i]=lst[i-1];
	for (int i=1;i<=m;i++)
		if (st1[i-1]!='A') s1[i]=s1[i-1]+1,lst1[i]=i;
		else s1[i]=s1[i-1],lst1[i]=lst1[i-1];
	while (q--)
	{
		int l,r,L,R;
		cin>>l>>r>>L>>R;
		int x=s[r]-s[l-1];
		int y=s1[R]-s1[L-1];
		// cout<<"?"<<x<<" "<<y<<" "<<R-max(lst1[R],L-1)<<" "<<r-max(lst[r],l-1)<<endl;
		if (x>y||x%2!=y%2
		||R-max(lst1[R],L-1)>r-max(lst[r],l-1)
		||r-(R-max(lst1[R],L-1))==l-1&&r-l+1!=R-L+1) cout<<0;
		else 
		{
			if (x==y)
			{
				// cout<<"??"<<endl;
				l=max(l,lst[r]+1);
				L=max(L,lst1[R]+1);
				if ((r-l+1==R-L+1)||(r-l+1)%3==(R-L+1)%3&&r-l+1>R-L+1) cout<<1;
				else cout<<0;
			} else
			{
				cout<<1;
			}
				
		}
	}
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}