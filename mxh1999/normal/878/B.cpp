#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100010;
pair<int,int> a[maxn];
ll sum[maxn];
int n,m,k;

struct Ans
{
	ll ans;
	pair<int,int> pre,suf;
};
inline ll getsum(int l,int r)
{
	if (l>r)	return 0;
	return sum[r]-sum[l-1];
}

Ans doit(int l,int r,int m)
{
	if (m==0 || (l>r))
	{
		Ans tmp;
		tmp.ans=0;
		tmp.suf=tmp.pre=make_pair(0,0);
		return tmp;
	}
	if (l==r)
	{
		Ans tmp;
		tmp.ans=(a[l].second*1LL*m)%k;
		tmp.suf=tmp.pre=make_pair(a[l].first,(int)tmp.ans);
		return tmp;
	}
	if (a[l].first!=a[r].first)
	{
		Ans tmp;
		tmp.ans=getsum(l,r)*m;
		tmp.pre=a[l];
		tmp.suf=a[r];
		return tmp;
	}
	if ((a[l].second+a[r].second)%k!=0)
	{
		ll q=(a[l].second+a[r].second)%k;
		Ans tmp;
		tmp.ans=getsum(l+1,r-1)*m+q*(m-1)+a[l].second+a[r].second;
		tmp.pre=a[l];
		tmp.suf=a[r];
		return tmp;
	}
	Ans qaq=doit(l+1,r-1,m);
	if (qaq.ans==0)
	{
		Ans tmp;
		tmp.ans=(a[l].second+a[r].second)%k;
		if (tmp.ans==0)	tmp.pre=tmp.suf=make_pair(0,0);
		else tmp.pre=tmp.suf=make_pair(a[l].first,(int)tmp.ans);
		return tmp;
	}
	if (qaq.ans==qaq.pre.second)
	{
		if (qaq.pre.first==a[l].first)
		{
			Ans tmp;
			tmp.ans=(qaq.ans+a[l].second+a[r].second)%k;
			if (tmp.ans==0)	tmp.pre=tmp.suf=make_pair(0,0);
			else tmp.pre=tmp.suf=make_pair(a[l].first,(int)tmp.ans);
			return tmp;
		}	else
		{
			Ans tmp;
			tmp.ans=qaq.ans+a[l].second+a[r].second;
			tmp.pre=a[l];
			tmp.suf=a[r];
			return tmp;
		}
	}
	Ans tmp=qaq;
	tmp.ans+=a[l].second+a[r].second;
	if (tmp.pre.first==a[l].first)
	{
		tmp.pre.second+=a[l].second;
		tmp.ans-=tmp.pre.second;
		tmp.pre.second%=k;
		tmp.ans+=tmp.pre.second;
		if (tmp.pre.second==0)	tmp.pre.first=0;
	}	else	tmp.pre=a[l];
	if (tmp.suf.first==a[r].first)
	{
		tmp.suf.second+=a[r].second;
		tmp.ans-=tmp.suf.second;
		tmp.suf.second%=k;
		tmp.ans+=tmp.suf.second;
		if (tmp.suf.second==0)	tmp.suf.first=0;
	}	else	tmp.suf=a[r];
	return tmp;
}
int main()
{
	//freopen("b.in","r",stdin);
	//bool bo=false;
	scanf("%d%d%d",&n,&k,&m);
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		/*
		if (i==1)
		{
			if (n==1000 && k==42 && m==1000 && x==8)	bo=true;
		}
		*/
		if (cnt==0 || a[cnt].first!=x)
		{
			cnt++;
			a[cnt].first=x;
		}
		a[cnt].second++;
		if (a[cnt].second==k)
		{
			a[cnt]=make_pair(0,0);
			cnt--;
		}
	}
	for (int i=1;i<=cnt;i++)
		sum[i]=sum[i-1]+a[i].second;
	/*
	if (bo)
	{
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++)
			printf("%d %d\n",a[i].first,a[i].second);
	}
	*/
	Ans ans=doit(1,cnt,m);
	cout<<ans.ans<<endl;
	return 0;
}