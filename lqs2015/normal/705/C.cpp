#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
multiset<int> s[333333];
int n,q,sz,tp,pos,tim,j;
int happtime[333333];
int main()
{
	j=1;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&tp,&pos);
		if (tp==1)
		{
			s[pos].insert(++tim);
			sz++;
			happtime[tim]=pos;
		}
		else if (tp==2)
		{
			sz-=s[pos].size();
			s[pos].clear();
		}
		else
		{
			for (;j<=pos;j++)
			{
				if (s[happtime[j]].find(j)!=s[happtime[j]].end()) 
				{
					s[happtime[j]].erase(j);
					sz--;
				}
			}
		}
		printf("%d\n",sz);
	}
	return 0;
}