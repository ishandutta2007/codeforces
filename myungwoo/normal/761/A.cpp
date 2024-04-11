#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int main()
{
	int even, odd;
	cin >> even >> odd;
	if ((even+odd) > 0 && (even == odd || abs(even-odd) == 1)) puts("YES");
	else puts("NO");
}