#include<iostream>
#include<vector>
using namespace std;
int N,A,c[1<<17];
vector<int>idx[1<<20];
main()
{
	cin>>N>>A;
	for(int i=0;i<N;i++)
	{
		cin>>c[i];
		idx[c[i]].push_back(i);
	}
	for(int B=1;B<1<<20;B++)if(A!=B)
	{
		bool ok=true;
		for(int a=0;a<idx[A].size();a++)
		{
			if(a>=idx[B].size()||idx[A][a]<idx[B][a])
			{
				ok=false;
				break;
			}
		}
		if(ok)
		{
			cout<<B<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}