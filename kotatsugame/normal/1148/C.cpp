#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int P[3<<17];
int id[3<<17];
vector<pair<int,int> >ans;
void s(int i,int j)
{
	if(i==j)return;
	id[P[i]-1]=j;
	id[P[j]-1]=i;
	swap(P[i],P[j]);
	ans.push_back(make_pair(i+1,j+1));
}
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",P+i);
		id[P[i]-1]=i;
	}
	for(int i=0;i<N;i++)
	{
		int j=id[i];
		if(i==j)continue;
		if(abs(i-j)*2>=N)
		{
			s(i,j);
		}
		else if(abs(N-1-j)*2>=N)
		{
			s(j,N-1);
			s(i,N-1);
		}
		else if(i*2>=N)
		{
			s(0,j);
			s(0,i);
			s(0,j);
		}
		else
		{
			s(0,j);
			s(0,N-1);
			s(i,N-1);
			s(0,N-1);
			s(0,j);
		}
	}
	cout<<ans.size()<<endl;
	for(pair<int,int>&p:ans)printf("%d %d\n",p.first,p.second);
}