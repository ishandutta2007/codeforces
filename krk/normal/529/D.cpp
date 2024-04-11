#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int n, M, T;
int res;
vector <int> seq;
deque <ii> D;
bool was;

int getTim(char s[])
{
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int mn = (s[3] - '0') * 10 + s[4] - '0';
	int sc = (s[6] - '0') * 10 + s[7] - '0';
	return sc + 60 * (mn + 60 * h);
}

int main()
{
	scanf("%d %d %d", &n, &M, &T);
	char str[15];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		int tim = getTim(str);
		if (!D.empty() && D[0].first < tim) D.pop_front();
		if (D.size() < M) {
			D.push_back(ii(tim + T - 1, ++res));
			seq.push_back(res);
		} else {
			D.back().first = tim + T - 1;
			seq.push_back(D.back().second);
		}
		if (D.size() == M) was = true;
	}
	if (was) {
		printf("%d\n", res);
		for (int i = 0; i < seq.size(); i++)
			printf("%d\n", seq[i]);
	} else printf("No solution\n");
	return 0;
}