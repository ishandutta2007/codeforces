#include <bits/stdc++.h>
using namespace std;
int n,m,p;
int d[200000];
long long int a[200000];
long long int s[200000];
long long int dp[101][100002];
deque<int> r;
int c=0;
double eps=1e-5;
bool cut_end(int t,int i)
{
	int x,y;
	x=r.back();
	r.pop_back();
	y=r.back();
	r.push_back(x);
	double k1,k2,k3,n1,n2,n3;
	n1=dp[t][y];
	n2=dp[t][x];
	n3=dp[t][i];
	k1=y;
	k2=x;
	k3=i;
	double xc2,xc3;
	xc3=(n3-n1)/(k1-k3);
	xc2=(n2-n1)/(k1-k2);
	if(xc3-xc2>-eps) return true;
	else return false;
}
int main()
{
	int x,y;
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d",&x);
		d[i+1]=d[i]+x;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		a[i]=y-d[x-1];
	}
	sort(a+1,a+m+1);
	s[1]=a[1];
	for(int i=2;i<=m;i++) s[i]=s[i-1]+a[i];
	for(long long i=1;i<=m;i++) dp[0][i]=i*a[i];
	for(long long t=1;t<p;t++)
	{
		r.clear();
		for(int i=1;i<=t && i<=m;i++) dp[t][i]=s[i];
		r.push_back(t);
		for(long long i=t+1;i<=m;i++)
		{
			dp[t][i]=dp[t-1][r.front()]-(r.front())*a[i]+(i*a[i]-s[i]);
			x=r.front();
			r.pop_front();
			while(r.size()>=1 && dp[t][i]>=dp[t-1][r.front()]-(r.front())*a[i]+(i*a[i]-s[i]))
			{
				dp[t][i]=dp[t-1][r.front()]-(r.front())*a[i]+(i*a[i]-s[i]);
				x=r.front();
				r.pop_front();
			}
			r.push_front(x);
			while(r.size()>=2 && cut_end(t-1,i)) r.pop_back();
			r.push_back(i);
			dp[t][i]+=s[i];
		}
	}
	printf("%I64d",dp[p-1][m]-s[m]);
	return 0;
}