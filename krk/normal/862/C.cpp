#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int from = 131072;

int n, x;
vector <int> seq;

void Print()
{
	printf("YES\n");
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
}

int main()
{
	scanf("%d %d", &n, &x);
	int got = (n - 1) / 2 * 2;
	int res = 0;
	for (int i = from; i < from + got; i++) {
		seq.push_back(i); res ^= i;
	}
	n -= got;
	if (n == 1) {
		seq.push_back(res ^ x);
		Print();
		return 0;
	}
	if (res == x && seq.size() > 0) { res ^= seq.back(); seq.back()++; res ^= seq.back(); }
	if (res == x) { printf("NO\n"); return 0; }
	seq.push_back(0); seq.push_back(res ^ x);
	Print();
	return 0;
}