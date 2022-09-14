#include<cstdio>
#include<vector>
using namespace std;
int N;
char L[151515],R[151515];
vector<int>ids[27];
main()
{
	scanf("%d%s%s",&N,L,R);
	for(int i=0;i<N;i++)
	{
		if(L[i]=='?')ids[26].push_back(i);
		else ids[L[i]-'a'].push_back(i);
	}
	vector<pair<int,int> >ans;
	vector<int>r;
	for(int i=0;i<N;i++)
	{
		if(R[i]=='?')r.push_back(i);
		else
		{
			if(ids[R[i]-'a'].empty())
			{
				if(ids[26].empty());
				else
				{
					ans.push_back(make_pair(ids[26].back(),i));
					ids[26].pop_back();
				}
			}
			else
			{
				ans.push_back(make_pair(ids[R[i]-'a'].back(),i));
				ids[R[i]-'a'].pop_back();
			}
		}
	}
	for(int i=0;i<27;i++)
	{
		while(!ids[i].empty()&&!r.empty())
		{
			ans.push_back(make_pair(ids[i].back(),r.back()));
			ids[i].pop_back();
			r.pop_back();
		}
	}
	printf("%d\n",ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first+1,p.second+1);
}