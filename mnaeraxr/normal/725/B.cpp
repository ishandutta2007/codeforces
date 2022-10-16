#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 S[6] = {3, 4, 5, 2, 1, 0};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	int64 num = 0;
	for (int i = 0; i + 1 < (int)s.length(); ++i)
		num = num * 10 + s[i] - '0';

	int64 T = 16 * ((num - 1) / 4) + 1;
	if (num % 2 == 0) T += 7;

	T += S[s.back() - 'a'];

	cout << T << endl;

	return 0;
}