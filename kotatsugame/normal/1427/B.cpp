#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,K;
char s[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d\n",&N,&K);
		scanf("%s",s);
		int id=0;
		int rest=0;
		while(id<N&&s[id]=='L')
		{
			rest++;
			id++;
		}
		if(id==N)
		{
			printf("%d\n",K==0?0:K+K-1);
			continue;
		}
		int R=N-1;
		while(R>=0&&s[R]=='L')
		{
			rest++;
			R--;
		}
		vector<int>X;
		int ans=0;
		for(int i=id;i<R;)
		{
			ans++;
			if(i>0&&s[i-1]=='W')ans++;
			int now=0;
			i++;
			while(s[i]=='L')
			{
				i++;
				now++;
			}
			rest+=now;
			if(now>0)X.push_back(now);
		}
		ans++;
		if(R>0&&s[R-1]=='W')ans++;
		if(K>rest)K=rest;
		ans+=K*2;
		sort(X.begin(),X.end());
		for(int x:X)
		{
			K-=x;
			if(K>=0)ans++;
		}
		printf("%d\n",ans);
	}
}