#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl
#define SZ(x) (int)(x.size())

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	if (n % 2 == 0 && n > 2) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}