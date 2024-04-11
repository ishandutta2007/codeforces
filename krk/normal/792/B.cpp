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

const int Maxn = 105;

int n, k;
int a[Maxn];
vector <int> seq;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		seq.push_back(i);
	int ind = 0;
	for (int i = 0; i < k && seq.size() > 0; i++) {
		ind %= seq.size();
		int nxt = (ind + a[i]) % seq.size();
		printf("%d", seq[nxt] + 1);
		seq.erase(seq.begin() + nxt);
		printf("%c", i + 1 < k && seq.size()? ' ': '\n');
		ind = nxt;
	}
	return 0;
}