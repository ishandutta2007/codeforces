#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> >mk(int sx,int sy,int gx,int gy)
{
	vector<pair<int,int> >ret;
	ret.push_back(make_pair(sx,sy));
	while(sx!=gx||sy!=gy)
	{
		if(sx<gx)sx++;
		else if(sx>gx)sx--;
		else if(sy<gy)sy++;
		else sy--;
		ret.push_back(make_pair(sx,sy));
	}
	return ret;
}
void un(set<pair<int,int> >&A,vector<pair<int,int> >B)
{
	for(pair<int,int>p:B)A.insert(p);
}
set<pair<int,int> >mn(set<pair<int,int> >A,set<pair<int,int> >B)
{
	return A.size()<B.size()?A:B;
}
main()
{
	int A[3][2];
	for(int i=0;i<3;i++)for(int j=0;j<2;j++)scanf("%d",&A[i][j]);
	int mini=1e9,X,Y;
	for(int x=0;x<=1000;x++)for(int y=0;y<=1000;y++)
	{
		int now=1;
		for(int i=0;i<3;i++)now+=abs(x-A[i][0])+abs(y-A[i][1]);
		if(mini>now)
		{
			mini=now;
			X=x;
			Y=y;
		}
	}
	set<pair<int,int> >ans;
	for(int i=0;i<3;i++)un(ans,mk(X,Y,A[i][0],A[i][1]));
	printf("%d\n",ans.size());
	for(pair<int,int>p:ans)printf("%d %d\n",p.first,p.second);
}