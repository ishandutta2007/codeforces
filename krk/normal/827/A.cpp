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

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
string t[Maxn];
vector <ii> seq;
vector <char> res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		int k; scanf("%d", &k);
		while (k--) {
			int x; scanf("%d", &x); x--;
			seq.push_back(ii(x, i));
		}
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); i++) {
		while (res.size() < seq[i].first) res.push_back('a');
		while (int(res.size()) - seq[i].first < t[seq[i].second].length())
			res.push_back(t[seq[i].second][int(res.size()) - seq[i].first]);
	}
	for (int i = 0; i < res.size(); i++)
		printf("%c", res[i]);
	printf("\n");
	return 0;
}