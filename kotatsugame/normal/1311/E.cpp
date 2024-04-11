#include<cstdio>
#include<vector>
using namespace std;
int T,N,D;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&D);
		if(N*(N-1)/2<D)
		{
			puts("NO");
			continue;
		}
		vector<int>dep(N);
		vector<int>master;
		master.push_back(0);
		vector<int>pr(N);
		vector<bool>ok(N,false);
		for(int i=1;i<N;i++)
		{
			pr[i]=(i-1)/2;
			dep[i]=dep[pr[i]]+1;
			D-=dep[i];
			if(master.back()==pr[i])master.push_back(i);
			else ok[i]=true;
		}
		if(D<0)
		{
			puts("NO");
			continue;
		}
		for(int i=N;D>0&&i--;)if(ok[i])
		{
			int id=dep[i]-1;
			while(D>0&&id+1<master.size())D--,id++;
			pr[i]=master[id];
			if(id+1==master.size())
			{
				master.push_back(i);
			}
		}
		puts("YES");
		for(int i=1;i<N;i++)printf("%d%c",pr[i]+1,i+1==N?10:32);
	}
}