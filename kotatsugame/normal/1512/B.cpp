#include<cstdio>
#include<vector>
using namespace std;
int T,N;
char S[444][444];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >XY;
		for(int i=0;i<N;i++)
		{
			scanf("%s",S[i]);
			for(int j=0;j<N;j++)if(S[i][j]=='*')
			{
				XY.push_back(make_pair(i,j));
			}
		}
		int x1=XY[0].first,y1=XY[0].second;
		int x2=XY[1].first,y2=XY[1].second;
		if(x1!=x2)
		{
			if(y1!=y2)
			{
				S[x1][y2]=S[x2][y1]='*';
			}
			else
			{
				int y=y1==0?1:0;
				S[x1][y]=S[x2][y]='*';
			}
		}
		else
		{
			int x=x1==0?1:0;
			S[x][y1]=S[x][y2]='*';
		}
		for(int i=0;i<N;i++)puts(S[i]);
	}
}