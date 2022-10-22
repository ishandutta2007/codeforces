#include<bits/stdc++.h>
using namespace std;
const int N=500000;
int n,m;
int num[N+5],sum[N+5];
int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	vector<int> v;
	v.push_back(1);
	for(int i=1;i<=(n-1)/2;i++)
	{
		v.push_back(i*4);
		v.push_back(i*4+1);
	}
	v.push_back(2);
	for(int i=1;i<=(n-1)/2;i++)
	{
		v.push_back(i*4-1);
		v.push_back(i*4+2);
	}
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	printf("\n");
	return 0;
}