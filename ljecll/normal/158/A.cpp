#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#define MAXN 51

using namespace std;

int N, K;
int cutoff;
int score[MAXN];
int j;
int ans;

int main()
{
//	freopen ("cf158.in", "r", stdin);
//	freopen ("cf158.out", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}
	cutoff = score[K - 1];
	while(score[j] > 0 && score[j] >= cutoff && j < N)
	{
		j++;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}