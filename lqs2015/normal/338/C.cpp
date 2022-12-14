#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[11],pnt[11],ts,pos,prime[111111],cnt,ccnt,mn,fl[11][11],pf[11],wei[11];
long long cur,jz;
bool f[1111111];
bool ss(long long n)
{
	for (long long i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
bool ch(long long i)
{
	long long sz=pf[i],au[11],lst[11];
	for (long long j=1;j<=sz;j++) au[j]=fl[i][j];
	sort(au+1,au+sz+1);
	for (long long j=1;j<=sz;j++) lst[j]=au[j];
	for (long long j=1;j<sz;j++)
	{
		bool flag=0;
		for (long long k=j+1;k<=sz;k++)
		{
			if (lst[k]%au[j]==0)
			{
				lst[k]/=au[j];
				flag=1;
				break;
			}
		}
		if (!flag) return 0;
	}
	return 1;
}
bool check()
{
	for (long long i=1;i<=cnt;i++)
	{
		if (!ch(i)) return 0;
	}
	return 1;
}
bool dfs(long long i)
{
	if (i==ccnt+1)
	{
		if (check()) return 1;
		return 0;
	}
	for (long long j=1;j<=cnt;j++)
	{
		if (fl[j][1]%wei[i]) continue;
		fl[j][++pf[j]]=wei[i];
		if (dfs(i+1)) return 1;
		pf[j]--;
	}
	return 0;
}
int main()
{
	cin>>n;
	for (long long i=0;i<n;i++) cin>>a[i];
	for (long long i=2;i<=1000000;i++)
	{
		if (!f[i])
		{
			for (long long j=i+i;j<=1000000;j+=i)
			f[j]=1;
		}
	}
	for (long long i=2;i<=1000000;i++)
	{
		if (!f[i]) prime[++cnt]=i;
	}
	for (long long i=0;i<n;i++)
	{
		ts=a[i];pos=1;
		if (ss(ts)) 
		{
			pnt[i]=0;
			continue;
		}
		while(ts>1)
		{
			while(pos<=cnt && ts%prime[pos]) pos++;
			if (pos>cnt) break;
			ts/=prime[pos];
			pnt[i]++;
		}
		if (ts>1) pnt[i]++;
	}
	mn=1e18;
	for (long long i=0;i<n;i++) jz+=(pnt[i]+1);
	for (long long i=1;i<(1<<n);i++)
	{
		cnt=0;cur=jz;ccnt=0;
		for (long long j=0;j<n;j++)
		{
			if (i&(1<<j)) 
			{
				cnt++;
				fl[cnt][1]=a[j];
				pf[cnt]=1;
			}
			else 
			{
				wei[++ccnt]=a[j];
				cur-=pnt[j];
				if (!pnt[j]) cur--;
			}
		}
		if (cnt>1) cur++;
		if (dfs(1)) mn=min(mn,cur);
	}
	cout<<mn<<endl;
	return 0;
}