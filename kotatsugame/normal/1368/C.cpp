#include<cstdio>
#include<set>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	set<pair<int,int> >S;
	S.insert(make_pair(0,0));
	S.insert(make_pair(N+1,N+1));
	for(int i=1;i<=N;i++)
	{
		S.insert(make_pair(i,i));
		S.insert(make_pair(i-1,i));
		S.insert(make_pair(i+1,i));
		S.insert(make_pair(i,i-1));
		S.insert(make_pair(i,i+1));
	}
	printf("%d\n",(int)S.size());
	for(set<pair<int,int> >::iterator it=S.begin();it!=S.end();it++)
	{
		printf("%d %d\n",it->first,it->second);
	}
}