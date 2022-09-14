#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;
int N;
char S[3<<17];
deque<int>ids[3];
main()
{
	scanf("%d%s",&N,S);
	for(int i=0;i<N;i++)ids[S[i]-'0'].push_back(i);
	int c0=0,c1=0,c2=0;
	if(ids[0].size()<N/3)c0=N/3-ids[0].size();
	if(ids[1].size()<N/3)c1=N/3-ids[1].size();
	if(ids[2].size()<N/3)c2=N/3-ids[2].size();
	while(ids[0].size()>N/3&&c2>0)
	{
		c2--;
		S[ids[0].back()]='2';
		ids[0].pop_back();
	}
	while(ids[0].size()>N/3&&c1>0)
	{
		c1--;
		S[ids[0].back()]='1';
		ids[0].pop_back();
	}
	while(ids[1].size()>N/3&&c0>0)
	{
		c0--;
		S[ids[1].front()]='0';
		ids[1].pop_front();
	}
	while(ids[1].size()>N/3&&c2>0)
	{
		c2--;
		S[ids[1].back()]='2';
		ids[1].pop_back();
	}
	while(ids[2].size()>N/3&&c0>0)
	{
		c0--;
		S[ids[2].front()]='0';
		ids[2].pop_front();
	}
	while(ids[2].size()>N/3&&c1>0)
	{
		c1--;
		S[ids[2].front()]='1';
		ids[2].pop_front();
	}
	puts(S);
}