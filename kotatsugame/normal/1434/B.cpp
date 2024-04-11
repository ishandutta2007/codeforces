#include<cstdio>
#include<stack>
using namespace std;
int N;
int ans[1<<17];
main()
{
	scanf("%d",&N);
	stack<int>S;
	int in=0;
	for(int t=0;t<2*N;t++)
	{
		char c;scanf(" %c",&c);
		if(c=='+')S.push(--in);
		else
		{
			int x;scanf("%d",&x);
			int mx=0,id=-1;
			while(!S.empty())
			{
				int t=S.top();S.pop();
				if(t>0)
				{
					if(mx<t)mx=t;
				}
				else
				{
					id=-t-1;
					break;
				}
			}
			if(id<0||mx>x)
			{
				puts("NO");
				return 0;
			}
			ans[id]=x;
			S.push(x);
		}
	}
	puts("YES");
	for(int i=0;i<N;i++)
	{
		printf("%d%c",ans[i],i+1==N?'\n':' ');
	}
}