#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	int a = v[k];

	int p1 = k, p2 = k;
	while (true){
		p1--; p2++;
		if (p1 < 1 || p1 > n){
			if (p2 < 1 || p2 > n){
				break;
			}
			else
				a += v[p2];
		}
		else{
			if (p2 < 1 || p2 > n)
				a += v[p1];
			else{
				if (v[p1] == v[p2])
					a += 2 * v[p1];
			}
		}
	}

	cout << a << endl;

	return 0;
}