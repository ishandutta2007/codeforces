#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	int n;
	char ch;
	cin >> n;

	int zeros = 0, ones = 0;

	while (n--) {
		cin >> ch;
		if (ch == '1') ones++;
		else zeros++;
	}

	cout << abs(zeros - ones) << endl;

    return 0;
}