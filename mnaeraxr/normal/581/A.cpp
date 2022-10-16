#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	cout << min(a, b) << " ";
	cout << (max(a, b) - min(a, b)) / 2 << endl;

	return 0;
}