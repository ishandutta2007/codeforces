#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int Maxn = 5005;

int nim[Maxn];
char s[Maxn];
int len;
bool win[Maxn];

bool Lose()
{
	int res = 0, cur = 0;
	for (int i = 0; i < len; i++)
		if (win[i]) cur++;
		else { res ^= nim[cur]; cur = 0; }
	return res == 0;
}

int main()
{
	nim[0] = 0; nim[1] = 1; nim[2] = 1;
	for (int i = 3; i < Maxn; i++) {
		set <int> S;
		S.insert(nim[i - 2]);
		for (int j = 2; j <= (i + 1) / 2; j++)
			S.insert(nim[j - 2] ^ nim[i - (j + 1)]);
		while (S.count(nim[i])) nim[i]++;
	}
	scanf("%s", s); len = strlen(s);
	for (int i = 1; i + 1 < len; i++)
		win[i] = s[i - 1] == s[i + 1];
	if (Lose()) printf("Second\n");
	else {
		printf("First\n");
		for (int i = 1; i + 1 < len; i++) if (win[i]) {
			bool a = win[i - 1], b = win[i + 1]; win[i - 1] = win[i] = win[i + 1] = false;
			if (Lose()) { printf("%d\n", i + 1); break; }
			win[i - 1] = a; win[i] = true; win[i + 1] = b;
		}
	}
	return 0;
}