#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	int answer = 0;

	int p = 0;
	while (p < (int)s.length() && s[p] == '<') answer++, p++;

	p = (int)s.length() - 1;
	while (p >= 0 && s[p] == '>') answer++, p--;

	cout << answer << endl;


	return 0;
}