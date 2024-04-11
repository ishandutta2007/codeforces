#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
int n;
long long b;
vector<long long>a[66];
list<long long>ans;
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&b);
		int cnt=0;
		while(b>>cnt)cnt++;
		a[cnt-1].push_back(b);
	}
	for(int i=60;i>=0;i--)
	{
		if(a[i].size()>0)ans.push_front(a[i][0]);
		list<long long>::iterator it=ans.begin();
		for(int j=1;j<a[i].size();j++)
		{
			it++;
			while(it!=ans.end()&&!((*it>>i)&1))it++;
			if(it==ans.end())
			{
				puts("No");
				return 0;
			}
			it++;
			it=ans.insert(it,a[i][j]);
		}
	}
	puts("Yes");
	int flag=0;
	for(long long it:ans)
	{
		if(flag++)putchar(' ');
		printf("%lld",it);
	}
	puts("");
}