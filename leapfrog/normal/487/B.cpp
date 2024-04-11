//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,l,s,a[100005],dp[100005];
deque<int>mx,mn,q;
int main()
{
	read(n),read(s),read(l);for(int i=1;i<=n;i++) read(a[i]);
	memset(dp,0x3f,sizeof(dp)),dp[0]=0;
	for(int i=1;i<l;i++)
	{
		while(!mx.empty()&&a[mx.front()]<=a[i]) mx.pop_front();
		while(!mn.empty()&&a[mn.front()]>=a[i]) mn.pop_front();
		mx.push_front(i),mn.push_front(i);
	}
	int wh=1;for(int i=l;i<=n;i++)
	{
		while(!mx.empty()&&a[mx.front()]<=a[i]) mx.pop_front();
		while(!mn.empty()&&a[mn.front()]>=a[i]) mn.pop_front();
		mx.push_front(i),mn.push_front(i);
		for(;wh<=i;wh++)
		{
			if(!mx.empty()&&mx.back()<wh) mx.pop_back();
			if(!mn.empty()&&mn.back()<wh) mn.pop_back();
			if(a[mx.back()]-a[mn.back()]<=s) break;
		}
		while(!q.empty()&&dp[q.front()]>=dp[i-l]) q.pop_front();
		q.push_front(i-l);while(!q.empty()&&q.back()<wh-1) q.pop_back();
		if(wh<=i-l+1&&!q.empty()) dp[i]=dp[q.back()]+1;
	}
	return printf("%d\n",dp[n]>1e9?-1:dp[n]),0;
}