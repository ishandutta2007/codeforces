#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(N) for(int i=0;i<N;i++)
using namespace std;

int main()
{
	int n;
	long long k;
	cin>>n>>k;
	int power[2*n];
	rep(n)
	{
		cin>>power[i];
		power[n+i]=power[i];
	}
	int maxk=0;
	for(int i=1;i<n;i++)
	{
		if(power[i]>power[maxk]) maxk=i;
	}
	for(int i=0;i<2*n;i++)
	{
		int len=(bool)i;
		for(int j=i+1;j<2*n;j++)
		{
			if(power[j]>power[i]) break;
			len++;
		}
		if(len>=k)
		{
			cout<<power[i]<<endl;
			return 0;
		}
	}
	cout<<power[maxk]<<endl;
	return 0;
}