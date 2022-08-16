#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF=100000000;

int b,d;
vector<pair<int,int> > v;
int b2[110],b3[110],b11[110];

void init()
{
	cin>>b;
	int t=b;
	for (int i=2;i<=100;++i)
		if (t%i==0)
		{
			v.push_back(make_pair(i,0));
			while (t%i==0)
			{
				v.rbegin()->second++;
				t/=i;
			}
		}
	for (int d=2;d<=100;++d)
	{
		int t=d;
		int get=0;
		for (int i=0;i<v.size();++i)
		{
			int p=0;
			while (t%v[i].first==0)
			{
				t/=v[i].first;
				++p;
			}
			if (!p) continue;
			get=max(get,(p-1)/v[i].second+1);
		}
		b2[d]=(t==1)?get:INF;
		b3[d]=(b%d==1);
		b11[d]=(b%d==d-1);
	}
}

void work()
{
	cin>>d;
	if (b2[d]<INF)
	{
		puts("2-type");
		cout<<b2[d]<<endl;
		return;
	}
	if (b3[d])
	{
		puts("3-type");
		return;
	}
	if (b11[d])
	{
		puts("11-type");
		return;
	}
	int flag=0;
	for (int i=2;i<=100;++i)
		if (d%i==0)
		{
			int t=1;
			while (d%i==0)
			{
				t*=i;
				d/=i;
			}
			if (b2[t]==INF&&!b3[t]&&!b11[t]) flag=1;
		}
	puts(flag?"7-type":"6-type");
}

int main()
{
	init();
	work();
	return 0;
}