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

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

char tmp[Maxn];
int tlen;
int n;
vector <ii> seq;
ll res;

bool Less(const ii &a, const ii &b)
{
	return ll(a.first) * b.second > ll(b.first) * a.second;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); tlen = strlen(tmp);
		int ones = 0, twos = 0;
		for (int j = 0; j < tlen; j++)
			if (tmp[j] == 's') ones++;
			else { res += ones; twos++; }
		seq.push_back(ii(ones, twos));
	}
	sort(seq.begin(), seq.end(), Less);
	ll cur = 0;
	for (int i = 0; i < seq.size(); i++) {
		res += cur * ll(seq[i].second);
		cur += seq[i].first;
	}
	cout << res << endl;
	return 0;
}