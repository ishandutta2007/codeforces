#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string A, B;
ll res;
int zers, ones;

int main()
{
	cin >> n;
	cin >> A;
	cin >> B;
	for (int i = 0; i < n; i++)
		if (B[i] == '1')
			if (A[i] == '0') zers++;
			else ones++;
	for (int i = 0; i < n; i++)
		if (B[i] == '0')
			if (A[i] == '0') { res += ones; zers++; }
			else { res += zers; ones++; }
	cout << res << endl;
	return 0;
}