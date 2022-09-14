#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		vector<pair<int,int> >X(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&X[i].first,&X[i].second);
		}
		string ans="";
		bool flag=false;
		sort(X.begin(),X.end());
		int nx=0,ny=0;
		for(int i=0;i<N;i++)
		{
			if(nx>X[i].first)
			{
				flag=true;
				break;
			}
			while(nx<X[i].first)
			{
				nx++;
				ans+='R';
			}
			if(ny>X[i].second)
			{
				flag=true;
				break;
			}
			while(ny<X[i].second)
			{
				ny++;
				ans+='U';
			}
		}
		if(flag)puts("NO");
		else
		{
			puts("YES");
			puts(ans.c_str());
		}
	}
}