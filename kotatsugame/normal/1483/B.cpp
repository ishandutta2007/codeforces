#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,N;
int prv[1<<17],nxt[1<<17],A[1<<17];
bool ex[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			prv[i]=(i+N-1)%N;
			nxt[i]=(i+1)%N;
			ex[i]=true;
		}
		queue<int>P;
		for(int i=0;i<N;i++)P.push((i+1)%N);
		vector<int>ans;
		while(!P.empty())
		{
			int id=P.front();P.pop();
			if(!ex[id])
			{
				continue;
			}
			int g=gcd(A[id],A[prv[id]]);
			if(g==1)
			{
				ans.push_back(id);
				nxt[prv[id]]=nxt[id];
				prv[nxt[id]]=prv[id];
				ex[id]=false;
				if(!P.empty()&&P.front()==nxt[id])P.pop();
				P.push(nxt[id]);
			}
		}
		printf("%d",ans.size());
		for(int id:ans)printf(" %d",id+1);
		puts("");
	}
}