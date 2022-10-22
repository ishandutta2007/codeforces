#include <cstdio>
#include <stack>
using namespace std;

stack <char> S;

int main()
{
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (S.empty() || S.top() != ch) S.push(ch);
		else S.pop();
	printf("%s\n", S.empty()? "Yes": "No");
	return 0;
}