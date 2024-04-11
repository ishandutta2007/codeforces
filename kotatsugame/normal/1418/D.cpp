#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
int N,Q;
int ip[1<<17];
set<int>p;
set<pair<int,int> >B;
priority_queue<pair<int,pair<int,int> > >P;
void answer()
{
	if(p.size()<=2)
	{
		printf("0\n");
	}
	else
	{
		int width=*p.rbegin()-*p.begin();
		while(B.find(P.top().second)==B.end())P.pop();
		printf("%d\n",width-P.top().first);
	}
}
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)scanf("%d",&ip[i]);
	sort(ip,ip+N);
	for(int i=0;i<N;i++)p.insert(ip[i]);
	for(int i=0;i<N-1;i++)
	{
		B.insert(make_pair(ip[i],ip[i+1]));
		P.push(make_pair(ip[i+1]-ip[i],make_pair(ip[i],ip[i+1])));
	}
	answer();
	for(;Q--;)
	{
		int t,x;scanf("%d%d",&t,&x);
		if(t==0)
		{
			set<int>::iterator it=p.find(x);
			int L=-1,R=-1;
			if(it!=p.begin())
			{
				it--;
				L=*it;
				B.erase(make_pair(L,x));
				it++;
			}
			it++;
			if(it!=p.end())
			{
				R=*it;
				B.erase(make_pair(x,R));
			}
			it--;
			p.erase(it);
			if(L!=-1&&R!=-1)
			{
				B.insert(make_pair(L,R));
				P.push(make_pair(R-L,make_pair(L,R)));
			}
		}
		else
		{
			set<int>::iterator it=p.lower_bound(x);
			int L=-1,R=-1;
			if(it!=p.begin())
			{
				it--;
				L=*it;
				B.insert(make_pair(L,x));
				P.push(make_pair(x-L,make_pair(L,x)));
				it++;
			}
			if(it!=p.end())
			{
				R=*it;
				B.insert(make_pair(x,R));
				P.push(make_pair(R-x,make_pair(x,R)));
			}
			if(L!=-1&&R!=-1)
			{
				B.erase(make_pair(L,R));
			}
			p.insert(x);
		}
		answer();
	}
}