#include<cstdio>
#include<stack>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	stack<int>S;
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		A=A%2*2-1;
		if(S.empty())S.push(A);
		else
		{
			if(S.top()==0)
			{
				S.pop();
				S.push(A);
			}
			else if(S.top()==A)
			{
				S.pop();
				if(S.empty())S.push(0);
			}
			else S.push(A);
		}
	}
	puts(S.size()==1?"YES":"NO");
}