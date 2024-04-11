#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
int main()
{
	int n,st,x;
	scanf("%d%d%d",&n,&st,&x);
	srand(time(0));
	for (int i=0;i<1000;i++)
	{
		int tmp=(rand()*rand())%n+1;
		printf("? %d\n",tmp);
		fflush(stdout);
		int val,ne;
		scanf("%d%d",&val,&ne);
		v.push_back({val,tmp});
	}
	sort(v.begin(),v.end());
	int ind=st;
	for (auto p:v)
	{
		if (p.first<x)
		ind=p.second;
	}
	while (1)
	{
		printf("? %d\n",ind);
		fflush(stdout);
		int val,ne;
		scanf("%d%d",&val,&ne);
		if (val>=x)
		{
			printf("! %d\n",val);
			fflush(stdout);
			return 0;
		}
		if (ne==-1)
		{
			printf("! -1");
			fflush(stdout);
			return 0;
		}
		ind=ne;
	}
}