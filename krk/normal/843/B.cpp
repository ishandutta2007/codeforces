#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int n, start, x;

ii Get(int ind)
{
	printf("? %d\n", ind); fflush(stdout);
	int value, nxt; scanf("%d %d", &value, &nxt);
	return ii(value, nxt);
}

void Ans(int res)
{
	printf("! %d\n", res); fflush(stdout);
}

int main()
{
	scanf("%d %d %d", &n, &start, &x);
	srand(time(NULL));
	vector <int> seq;
	for (int i = 1; i <= n; i++)
		seq.push_back(i);
	random_shuffle(seq.begin(), seq.end());
	ii best = Get(start);
	if (best.first >= x) { Ans(best.first); return 0; }
	for (int i = 0; i < 1500 && i < seq.size(); i++) {
		ii got = Get(seq[i]);
		if (got.first < x && got.first > best.first) best = got;
	}
	while (best.first < x)
		if (best.second == -1) { Ans(-1); return 0; }
		else best = Get(best.second);
	Ans(best.first);
	return 0;
}