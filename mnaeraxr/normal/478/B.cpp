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

int64 F(int64 A)
{
	return A * (A - 1) / 2;
}

int main()
{
	int64 N, M;
	cin >> N >> M;

	int64 MAX = N - M + 1;
	int64 MIN = N / M + ((N % M == 0) ? 0 : 1);

	int64 ans1;
	if (N % M)
		ans1 = (N % M) * F(N / M + 1) + (M - N % M) * F(N / M); 
	else
		ans1 = M * F(N / M);

	cout << ans1 << " " << F(MAX) << endl;
}