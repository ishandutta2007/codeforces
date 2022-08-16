#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1<<18;

int n;
char s[MaxN],t[MaxN];
int ps[MaxN],pt[MaxN],get[MaxN],F[MaxN],p[MaxN];
pair<int,int> v[20][MaxN];

void init()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;++i)
		t[n-i+1]=s[i];
	for (int i=2;i<=n;++i)
	{
		int j=pt[i-1];
		while (j)
		{
			if (t[j+1]==t[i]) break;
			j=pt[j];
		}
		if (t[j+1]==t[i]) pt[i]=j+1;
		else pt[i]=0;
	}
	for (int i=1;i<=n;++i)
	{
		int j=ps[i-1];
		while (j)
		{
			if (t[j+1]==s[i]) break;
			j=pt[j];
		}
		if (t[j+1]==s[i]) ps[i]=j+1;
		else ps[i]=0;
	}
	for (int i=1;i<=n;++i)
		if (ps[i])
		{
			if (get[ps[i]]) continue;
			get[ps[i]]=i;
		}
	int begin=0,delta=0;
	for (int i=1;i<=n;++i)
	{
		if (i<begin+delta)
			F[i]=min(F[2*begin-i],begin+delta-i-1);
		while (i-F[i]-1>0&&i+F[i]+1<=n)
		{
			if (s[i-F[i]-1]!=s[i+F[i]+1]) break;
			++F[i];
		}
		if (begin+delta<i+F[i])
		{
			begin=i;
			delta=F[i];
		}
	}
	for (int i=1;i<=n;++i)
		v[0][i]=make_pair(F[i],i);
	for (int k=1;k<=17;++k)
		for (int i=1;i<=n;++i)
			v[k][i]=max(v[k-1][i],v[k-1][i+(1<<(k-1))]);
	for (int i=2;i<=n;++i)
		p[i]=p[i>>1]+1;
}

pair<int,int> getmax(int L,int R)
{
	int x=p[R-L+1];
	return max(v[x][L],v[x][R-(1<<x)+1]);
}

vector<pair<int,int> > list;

void work()
{
	int ans=min(n,1);
	list.push_back(make_pair(1,1));
	for (int i=1;i<=n;++i)
		if (F[i]*2+1>ans)
		{
			ans=F[i]*2+1;
			list.clear();
			list.push_back(make_pair(i-F[i],i+F[i]));
		}
	for (int i=1;i<=n;++i)
	{
		if (!get[i]) break;
		if (get[i]+i>=n) break;
		int Lp=get[i]+1,Rp=n-i,len=0;
		int L=1,R=(Rp-Lp)/2;
		while (L<=R)
		{
			int mid=(L+R)>>1;
			if (Lp+mid>Rp-mid)
				R=mid-1;
			else if (getmax(Lp+mid,Rp-mid).first>=mid)
			{
				len=mid;
				L=mid+1;
			}
			else
				R=mid-1;
		}
		if (len*2+1+i*2>ans)
		{
			ans=len*2+1+i*2;
			list.clear();
			list.push_back(make_pair(get[i]-i+1,get[i]));
			int way=getmax(Lp+len,Rp-len).second;
			list.push_back(make_pair(way-F[way],way+F[way]));
			list.push_back(make_pair(n-i+1,n));
		}
	}
	cout<<list.size()<<endl;
	for (int i=0;i<list.size();++i)
		cout<<list[i].first<<" "<<list[i].second-list[i].first+1<<endl;
}

int main()
{
	init();
	work();
	return 0;
}