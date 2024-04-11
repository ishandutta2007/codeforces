#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#ifdef LOCAL
#include <cassert>
#endif // LOCAL

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int speed[100];

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
#endif // LOCAL

	int v1, v2, t, d;
	cin >> v1 >> v2 >> t >> d;

	speed[0] = v1;
	speed[t - 1] = v2;

	int ret = v1 + v2;

	int left = 0;
	int right = t - 1;
	while (left + 1 < right) {
//		cerr << left << ", " << right << ": " << speed[left] << " " << speed[right] << endl;

		if (speed[left] < speed[right]) {
			left++;
			speed[left] = speed[left - 1] + d;
			ret += speed[left];
//			cerr << "inc l " << speed[left] << endl;
		} else {
			right--;
			speed[right] = speed[right + 1] + d;
//			cerr << "inc r " << speed[right] << endl;
			ret += speed[right];
		}
	}

//	for (int i = 0; i < t; i++) {
//		cout << speed[i] << " ";
//	}
//	cout << endl;

	cout << ret << endl;
    return 0;
}