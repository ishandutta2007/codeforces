#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int v[26];
int t[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < 26; ++i)
		v[i] = i;
	for (int i = 0; i < m; ++i){
		char a, b;
		cin >> a >> b;
		int va = a - 'a', vb = b - 'a';
		swap(v[va], v[vb]);
	}
	for (int i = 0; i < 26; ++i)
		t[v[i]] = i;

	for (int i = 0; i < n; ++i)
		cout << (char)(t[s[i] - 'a'] + 'a');
	cout << endl;


	return 0;
}