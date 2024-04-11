#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;

int n;
char s[10];
int x = 1, y = 1;

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		string got = s;
		if (got == "UR" || got == "DL") y++;
		else if (got == "UL" || got == "DR") x++;
		else { y++; x++; }
	}
	printf("%I64d\n", ll(x) * ll(y));
	return 0;
}