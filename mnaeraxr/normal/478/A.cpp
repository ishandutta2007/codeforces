#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <map>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define DB(x) cout << #x << ":" << x << endl
#define MP make_pair

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;


int main()
{
	int S = 0;
	for (int i = 0; i < 5; ++i)
	{
		int v;
		cin >> v;
		S += v;
	}

	if (S % 5 == 0 && S != 0)
		cout << S / 5 << endl;
	else
		cout << -1 << endl;

	return 0;
}