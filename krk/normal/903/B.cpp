#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int h1, a1, c1;
int h2, a2;
vector <string> res;

int main()
{
	scanf("%d %d %d", &h1, &a1, &c1);
	scanf("%d %d", &h2, &a2);
	while (h2 > 0) {
		res.push_back("STRIKE");
		h2 -= a1;
		if (h2 <= 0) break;
		h1 -= a2;
		if (h1 <= 0) {
			res.back() = "HEAL";
			h1 += c1;
			h2 += a1;
		}
	}
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%s\n", res[i].c_str());
	return 0;
}