#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;     
typedef long long ll;

const int MAXN = 1e4 + 5;
const ll INF = 1e15;

vector <ll> coord;
pair <ll, ll> query[MAXN];
int n;
ll x;
ll dp[MAXN];
ll tmp[MAXN];


int main()
{
	ios_base::sync_with_stdio(0);
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	cin >> n >> x;
	coord.resize(2 * n + 1);
	coord[2 * n] = x;
	for (int i = 0; i < n; i++)
	{
		cin >> query[i].first >> query[i].second;
		coord[2 * i] = query[i].first;
                coord[2 * i + 1] = query[i].second;
	}
	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());

	for (int i = 0; i < (int)coord.size(); i++) {
		if (coord[i] == x)
			dp[i] = 0;
		else
			dp[i] = INF;
		tmp[i] = INF;
	}

	ll cur;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < (int) coord.size(); ++j) {
			cur = j ? min(cur + coord[j] - coord[j - 1], dp[j]) : dp[0];
			tmp[j] = min(tmp[j], cur +
					((coord[j] > query[i].first) != (coord[j] > query[i].second) ? 0 :
					min(abs(coord[j] - query[i].first), abs(coord[j] - query[i].second)))
				);
		}

		for (int j = (int)coord.size() - 1; j >= 0; --j) {
			cur = j != (int)coord.size() - 1 ? min(cur + coord[j + 1] - coord[j], dp[j]) : dp[(int)coord.size() - 1];
			tmp[j] = min(tmp[j], cur +
					((coord[j] > query[i].first) != (coord[j] > query[i].second) ? 0 :
					min(abs(coord[j] - query[i].first), abs(coord[j] - query[i].second)))
				);
		}

		for (int j = 0; j < (int)coord.size(); j++)
		{
			dp[j] = tmp[j];
			tmp[j] = INF;
		}
	}


	ll res = INF;

	for (int j = 0; j < (int)coord.size(); j++)
		res = min(res, dp[j]);

	cout << res;
	
	return 0;
}