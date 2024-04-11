#include<cstdio>
#include<stack>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	stack<pair<int,int> >S;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		if(S.empty())S.push(make_pair(A,1));
		else
		{
			if(S.top().first<A)
			{
				if(S.top().second==1)
				{
					puts("NO");
					return 0;
				}
				S.pop();
				S.push(make_pair(A,1));
			}
			else if(S.top().first>A)
			{
				S.push(make_pair(A,1));
			}
			else
			{
				S.top().second=1-S.top().second;
				if(S.top().second==0)
				{
					S.pop();
					if(S.empty())S.push(make_pair(A,0));
					else
					{
						if(S.top().first<A)
						{
							if(S.top().second==1)
							{
								puts("NO");
								return 0;
							}
							S.top().first=A;
						}
					}
				}
			}
		}
	}
	puts(S.size()==1?"YES":"NO");
}