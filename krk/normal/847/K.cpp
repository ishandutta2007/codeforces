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

typedef pair <string, string> ss;

int n, a, b, k, f;
map <ss, int> M;
int res;

void Insert(string a, string b, int cost)
{
	if (a > b) swap(a, b);
	M[ss(a, b)] += cost;
}

int main()
{
	scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
	string lst = "-1";
	for (int i = 0; i < n; i++) {
		string A, B; cin >> A >> B;
		int cost = lst == A? b: a; res += cost;
		lst = B;
		Insert(A, B, cost);
	}
	vector <int> seq;
	for (map <ss, int>::iterator it = M.begin(); it != M.end(); it++)
		seq.push_back(it->second);
	sort(seq.rbegin(), seq.rend());
	int tk = min(int(seq.size()), k);
	for (int i = 0; i < tk; i++)
		if (f < seq[i]) res -= (seq[i] - f);
	printf("%d\n", res);
	return 0;
}