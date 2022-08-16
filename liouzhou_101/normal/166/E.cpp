#include<iostream>

using namespace std;

const int MOD=1000000007;
const int MaxN=10000010;

long long p[MaxN],q[MaxN];

int main()
{
	p[0]=1;
	q[0]=0;
	int n;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		p[i]=q[i-1];
		q[i]=(p[i-1]*3+q[i-1]*2)%MOD;
	}
	cout<<p[n]<<endl;
	return 0;
}