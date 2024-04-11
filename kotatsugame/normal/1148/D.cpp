#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,A[3<<17],B[3<<17];
vector<pair<int,int> >UP,DOWN;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",A+i,B+i);
		if(A[i]<B[i])UP.push_back(make_pair(A[i],i));
		else DOWN.push_back(make_pair(A[i],i));
	}
	if(UP.size()>=DOWN.size())
	{
		cout<<UP.size()<<endl;
		sort(UP.begin(),UP.end());
		reverse(UP.begin(),UP.end());
		for(int i=0;i<UP.size();i++)
		{
			printf("%d%c",UP[i].second+1,i+1==UP.size()?'\n':' ');
		}
	}
	else
	{
		cout<<DOWN.size()<<endl;
		sort(DOWN.begin(),DOWN.end());
		for(int i=0;i<DOWN.size();i++)
		{
			printf("%d%c",DOWN[i].second+1,i+1==DOWN.size()?'\n':' ');
		}
	}
}