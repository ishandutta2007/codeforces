#include <cstdio>
#include <vector>
using namespace std;

vector <char> V;

int main()
{
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (V.empty() || V.back() != ch) V.push_back(ch);
		else V.pop_back();
	for (int i = 0; i < V.size(); i++)
		printf("%c", V[i]);
	printf("\n");
	return 0;
}