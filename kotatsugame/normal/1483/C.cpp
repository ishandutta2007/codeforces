#include<cstdio>
#include<queue>
using namespace std;
int N;
int H[3<<17],B[3<<17],inv[3<<17];
bool del[3<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&H[i]),H[i]--,inv[H[i]]=i;
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	priority_queue<pair<long long,int> >presum;
	priority_queue<pair<int,long long> >P;
	P.push(make_pair(H[0],B[0]));
	presum.push(make_pair(B[0],H[0]));
	for(int i=1;i<N;i++)
	{
		long long ps=presum.top().first;
		while(!P.empty()&&P.top().first>H[i])
		{
			int id=inv[P.top().first];
			long long now=P.top().second-B[id];
			if(ps<now)ps=now;
			P.pop();
			del[id]=true;
		}
		ps+=B[i];
		P.push(make_pair(H[i],ps));
		presum.push(make_pair(ps,H[i]));
		while(del[inv[presum.top().second]])presum.pop();
	}
	printf("%lld\n",presum.top().first);
}