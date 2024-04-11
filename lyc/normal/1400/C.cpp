#include<bits/stdc++.h>
using namespace std;
int t,x,a[100005],bl,T,bll;
string st;
signed main()
{
	cin>>T;
	while (T--)
	{
		cin>>st;
		cin>>x;
		st=' '+st;bl=1;
		memset(a,-1,sizeof(a));int n=st.length()-1;
		for (int i=1;i<=n;i++)
		{
			if (i+x<=n)
			{
				if (st[i]=='1') a[i+x]=1; else a[i+x]=0;
			}
			if (i-x>=1)
			{
				if (st[i]=='1') {if (a[i-x]==-1) a[i-x]=1;} else a[i-x]=0;
			}
			if (st[i]=='1'&&i+x>n&&i-x<1) bl=0;
		}
		for (int i=1;i<=n;i++)
		{
			if (st[i]=='1')
			{
				bll=0;
				if (i+x<=n) bll|=a[i+x];
				if (i-x>=1) bll|=a[i-x];
				if (!bll) {bl=0;break;}
			} else
			{
				bll=0;
				if (i+x<=n) bll|=a[i+x];
				if (i-x>=1) bll|=a[i-x];
				if (bll) {bl=0;break;}
			} 
		}for (int i=1;i<=n;i++)  if (a[i]==-1) a[i]=0;
		if (bl) {for (int i=1;i<=n;i++) cout<<a[i]; }else cout<<-1;
		cout<<endl;
	}
}