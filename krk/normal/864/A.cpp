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

int n;
int freq[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		freq[a]++;
	}
	vector <int> seq;
	for (int i = 0; i < Maxn; i++)
		if (freq[i] > 0) seq.push_back(i);
	if (seq.size() == 2 && freq[seq[0]] == freq[seq[1]])
		printf("YES\n%d %d\n", seq[0], seq[1]);
	else printf("NO\n");
	return 0;
}