#include<cstdio>
#include<iostream>
#include<bitset>

using namespace std;

const int MaxN=124;
const int MOD=1000000007;

int n,m,k;
long long v[MaxN];
bitset<MaxN> s[MaxN];
int ans;

void DFS(int now,int way)
{
	if (now>n)
	{
		ans+=way;
		if (ans>=MOD) ans-=MOD;
		return;
	}
	s[now]=s[now-1];
	DFS(now+1,way);
	if (v[now]&&!s[now-1][now])
	{
		s[now]=s[now-1]|(s[now-1]<<now)|(s[now-1]>>now)|(s[now-1]<<(m-now))|(s[now-1]>>(m-now));
		DFS(now+1,way*v[now]%MOD);
	}
}

int main()
{
	cin>>n>>m>>k;
	while (k--)
	{
		int x;
		scanf("%d",&x);
		x%=m;
		++v[min(x,m-x)];
	}
	n=(m+1)/2;
	s[0][0]=1;
	DFS(1,1);
	cout<<ans<<endl;
	return 0;
}