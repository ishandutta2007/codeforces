#include<cstdio>
#include<iostream>

using namespace std;

const long long INF=1000000000000000000LL;

long long ans=INF;

void solve(long long a,long long b,long long c)
{
	if ((a+b)%2==1) return;
	long long k=min(a,b)+c;
	ans=min(ans,a+b+c-k);
}

int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	solve(a,b,c);
	solve(a,c,b);
	solve(b,c,a);
	if (ans==INF) puts("-1");
	else cout<<ans<<endl;
	return 0;
}