#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=1<<20;
const int MOD=1000000007;

int n,ans;

struct node
{
	int v[MaxN];
	void add(int x,int p)
	{
		for (;x<=n;x+=x&-x) (v[x]+=p)%=MOD;
	}
	int get(int x)
	{
		int p=0;
		for (;x;x-=x&-x) (p+=v[x])%=MOD;
		return p;
	}
}A[2];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int now=i&1;
		int pre=now^1;
		int get=A[pre].get(i)+1;
		(ans+=get)%=MOD;
		A[now].add(i,get);
	}
	cout<<ans<<endl;
	return 0;
}