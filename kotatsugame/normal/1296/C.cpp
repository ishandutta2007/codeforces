#include<cstdio>
#include<map>
using namespace std;
int T,N;
char S[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s",&N,S);
		map<pair<int,int>,int>mp;
		int al=-1,ar=N;
		pair<int,int>now=make_pair(0,0);
		mp[now]=0;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='L')now.first--;
			else if(S[i]=='R')now.first++;
			else if(S[i]=='U')now.second++;
			else now.second--;
			if(mp.find(now)!=mp.end())
			{
				int l=mp[now],r=i+1;
				if(ar-al>r-l)ar=r,al=l;
			}
			mp[now]=i+1;
		}
		if(al<0)puts("-1");
		else printf("%d %d\n",al+1,ar);
	}
}