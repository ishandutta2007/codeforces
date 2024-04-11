#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<vector<int> >A(N-1);
		for(int i=0;i<N-1;i++)
		{
			int K;scanf("%d",&K);
			A[i].assign(K,0);
			for(int j=0;j<K;j++)
			{
				scanf("%d",&A[i][j]);
				A[i][j]--;
			}
		}
		vector<int>ans;
		for(int fst=0;fst<N;fst++)
		{
			vector<set<int> >ids(N);
			for(int i=0;i<N-1;i++)for(int u:A[i])ids[u].insert(i);
			vector<int>now(N);
			vector<bool>usd(N,false);
			usd[fst]=true;
			now[0]=fst;
			bool out=false;
			vector<int>del;
			for(int tm=N;--tm;)
			{
				int fn=-1;
				for(int i=0;i<N;i++)if(!usd[i]&&ids[i].size()==1)
				{
					fn=i;
					break;
				}
				if(fn==-1)
				{
					out=true;
					break;
				}
				now[tm]=fn;
				usd[fn]=true;
				int id=*ids[fn].begin();
				for(int u:A[id])ids[u].erase(id);
				del.push_back(id);
			}
			if(!out)
			{
				for(int tm=0;tm<N-1;tm++)
				{
					set<int>ch(A[del[tm]].begin(),A[del[tm]].end());
					int sz=A[del[tm]].size();
					for(int i=N-tm;i--,sz--;)
					{
						ch.erase(now[i]);
					}
					if(!ch.empty())
					{
						out=true;
						break;
					}
				}
				if(!out)
				{
					ans=now;
					break;
				}
			}
		}
		for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?10:32);
	}
}