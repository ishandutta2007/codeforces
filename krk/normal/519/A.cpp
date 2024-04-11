#include <cstdio>
#include <cctype>
using namespace std;

const int Maxd = 8;

int W, B;

int Value(char ch) 
{
	if (ch == 'q') return 9;
	if (ch == 'r') return 5;
	if (ch == 'b') return 3;
	if (ch == 'n') return 3;
	if (ch == 'p') return 1;
	return 0;
}

int main()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++) {
			char ch;
			scanf(" %c", &ch);
			if (ch != '.')
				if (isupper(ch)) W += Value(tolower(ch));
				else B += Value(ch);
		}
	if (W > B) printf("White\n");
	else if (W < B) printf("Black\n");
	else printf("Draw\n");
	return 0;
}