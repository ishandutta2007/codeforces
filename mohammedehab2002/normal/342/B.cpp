#include <iostream>
#include <deque>
using namespace std;
deque<pair<int,pair<int,int> > > v;
int main()
{
	int n,m,s,f,di=1;
	scanf("%d%d%d%d",&n,&m,&s,&f);
	while (m--)
	{
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		v.push_back(make_pair(t,make_pair(l,r)));
	}
	int cur=s;
	if (s>f)
	di=-1;
	for (int ti=1;cur!=f;ti++)
	{
		if (v.front().first==ti)
		{
			if (v.front().second.first<=cur && v.front().second.second>=cur)
			{
				printf("X");
				v.pop_front();
				continue;
			}
			cur+=di;
			if (v.front().second.first<=cur && v.front().second.second>=cur)
			{
				printf("X");
				v.pop_front();
				cur-=di;
				continue;
			}
			cur-=di;
			v.pop_front();
		}
		if (di==1)
		printf("R");
		else
		printf("L");
		cur+=di;
	}
}