#include <iostream>
#include <cstdio>
using namespace std;

int solve(long long int m,long long int k,int l)
{
	//cout<<m<<" "<<k<<" "<<l<<endl;
	if(k*2-1==m) return l;
	else
	{
		if(k*2-1<m)
		{
			m--;
			m=m/2;
			return solve(m,k,l-1);
		}
		else
		{
			m--;
			m=m/2;
			k=k-m-1;
			return solve(m,k,l-1);
		}
	}
}
int main()
{
	long long int n;
	long long int m;
	long long int k;
	int l;
	cin>>n>>k;
	l=n;
	m=1;
	while(n>0)
	{
		m=m*2;
		n--;
	}
	m--;
	cout<<solve(m,k,l)<<endl;
	return 0;
}