#include<cstdio>
#include<stack>
using namespace std;
char S[1<<17];
main()
{
	scanf("%s",&S);
	stack<char>s;
	int cnt=0;
	for(int i=0;S[i];i++)
	{
		if(s.empty()||s.top()!=S[i])s.push(S[i]);
		else
		{
			s.pop();
			cnt^=1;
		}
	}
	puts(cnt?"Yes":"No");
}