#include<cstdio>
#include<vector>
using namespace std;
int N;
int A[2<<17];
bool used[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)scanf("%d",&A[i]);
	int root=A[0];
	used[root]=true;
	int maxv=N;
	vector<pair<int,int> >E;
	for(int i=0;i<N-1;)
	{
		while(used[maxv])maxv--;
		used[maxv]=true;
		int p=A[i];
		i++;
		while(i<N-1&&!used[A[i]])
		{
			E.push_back(make_pair(p,A[i]));
			p=A[i];
			used[p]=true;
			i++;
		}
		E.push_back(make_pair(p,maxv));
	}
	printf("%d\n",root);
	for(int i=0;i<N-1;i++)printf("%d %d\n",E[i].first,E[i].second);
}