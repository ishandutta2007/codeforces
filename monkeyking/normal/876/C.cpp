#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
vector <int> vec;

int lenof(int x)
{
	int s=0;
	while(x)
	{
		x/=10;
		s++;
	}
	return s;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	vec.clear();
	int n;
	cin>>n;
	int start=max(1,n-lenof(n)*9);
//	cout<<lenof(n)<<endl;
	for(int i=start;i<=n;i++)
	{
		int t=i,s=i;
		while(t)
		{
			s+=t%10;
			t/=10;
		}
		if(s==n) vec.push_back(i);
	}
	cout<<vec.size()<<endl;
	rep(vec.size())
	{
		cout<<vec[i]<<endl;
	}
	return 0;
}