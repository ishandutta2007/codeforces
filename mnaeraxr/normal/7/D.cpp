#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

vector<int> manacher(const string &s)
{
	int n = 2 * s.length();
	vector<int> rad(n);

	for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0))
	{
		for (; i >= j && i + j + 1 < n
			&& s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
		rad[i] = j;
		for (k = 1; i >= k &&
			rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
			rad[i + k] = min(rad[i - k], rad[i] - k);
	}

	return rad;
}

bool is_pal(const vector<int> &rad, int b, int e)
{
	int n = rad.size() / 2;
	return b >= 0 && e < n && rad[b + e] >= e - b + 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	vi rad = manacher(s);
	vi K(s.length());
	K[0] = 1;

	int64 answer = 1;

	for (int i = 1; i < (int)s.length(); ++i){
		if (is_pal(rad, 0, i)){
			int s = (i - 1) / 2;
			answer += K[i] = K[s] + 1;
		}
	}

	cout << answer << endl;

	return 0;
}