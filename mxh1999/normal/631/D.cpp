#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 200010
pair<char,ll>	a[maxn],b[maxn];
int n,m,cnt1,cnt2;

int nxt[maxn];
void kmp(int from)
{
	int j=1;
	nxt[2]=1;
	for (int i=3;i<=m;i++)
	{
		while (b[j+1]!=b[i]  && j>1)	j=nxt[j];
		if (b[j+1]==b[i])	j++;
		nxt[i]=j;
	}
}
int main()
{
	read(n),read(m);
	for (int i=1;i<=n;i++)
	{
		int x;char ch;
		read(x);
		ch=getchar();
		while (!(ch<='z' && ch>='a'))	ch=getchar();
		if (cnt1>0 && a[cnt1].first==ch)	a[cnt1].second+=x;else
		{
			cnt1++;
			a[cnt1].first=ch;
			a[cnt1].second=x;
		}
	}
	for (int i=1;i<=m;i++)
	{
		int x;char ch;
		read(x);
		ch=getchar();
		while (!(ch<='z' && ch>='a'))	ch=getchar();
		if (cnt2>0 && b[cnt2].first==ch)	b[cnt2].second+=x;else
		{
			cnt2++;
			b[cnt2].first=ch;
			b[cnt2].second=x;
		}
	}
	n=cnt1,m=cnt2;
	ll mjy=0;
	if (m==1)
	{
		for (int i=1;i<=n;i++)
		if (a[i].first==b[1].first && a[i].second>=b[1].second)	mjy+=a[i].second-b[1].second+1;
		cout<<mjy<<endl;
		return 0;
	}
	if (m==2)
	{
		for (int i=1;i<n;i++)
		if (a[i].first==b[1].first && a[i].second>=b[1].second && a[i+1].first==b[2].first && a[i+1].second>=b[2].second)	mjy++;
		cout<<mjy<<endl;
		return 0;
	}
	kmp(2);
	int j=1;
	for (int i=2;i<n;i++)
	{
		while (j>1 && b[j+1]!=a[i])	j=nxt[j];
		if (b[j+1]==a[i])	j++;
		if (j==m-1)
		{
			bool bo=true;
			if (i>=n || a[i+1].first!=b[m].first || a[i+1].second<b[m].second)	bo=false;
			if (i-m+2<=0 || a[i-m+2].first!=b[1].first || a[i-m+2].second<b[1].second)	bo=false;
			if (bo)	mjy++;
			j=nxt[j];
		}
	}
	cout<<mjy<<endl;
	return 0;
}