#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int A[2<<17],B[2<<17];
int id[4<<17];
bool usd[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
		id[A[i]]=id[B[i]]=i;
	}
	int L=1,R=2*N;
	int ans=0;
	while(L<R)
	{
		int cnt=0;
		vector<pair<int,int> >X,Y;
		int pl=L,pr=R;
		usd[id[L]]=true;
		if(L==A[id[L]])R=B[id[L]];
		else cnt++,R=A[id[L]];
		X.push_back(make_pair(L,R));
		while(pl!=L||pr!=R)
		{
			if(pl!=L)
			{
				while(pl<L)
				{
					int i=id[pl];
					if(!usd[i])
					{
						if(pl==A[i])
						{
							X.push_back(make_pair(A[i],B[i]));
						}
						else
						{
							cnt++;
							X.push_back(make_pair(B[i],A[i]));
						}
						if(R>X.back().second)R=X.back().second;
						else
						{
							puts("-1");
							return 0;
						}
						usd[i]=true;
					}
					pl++;
				}
			}
			else
			{
				while(pr>R)
				{
					int i=id[pr];
					if(!usd[i])
					{
						if(pr==B[i])
						{
							cnt++;
							Y.push_back(make_pair(B[i],A[i]));
						}
						else
						{
							Y.push_back(make_pair(A[i],B[i]));
						}
						if(L<Y.back().second)L=Y.back().second;
						else
						{
							puts("-1");
							return 0;
						}
						usd[i]=true;
					}
					pr--;
				}
			}
		}
		for(int i=Y.size();i--;)X.push_back(Y[i]);
		for(int i=1;i<X.size();i++)
		{
			if(X[i-1].first>X[i].first||X[i-1].second<X[i].second)
			{
				puts("-1");
				return 0;
			}
		}
		ans+=min(cnt,(int)X.size()-cnt);
		L++,R--;
	}
	printf("%d\n",ans);
}