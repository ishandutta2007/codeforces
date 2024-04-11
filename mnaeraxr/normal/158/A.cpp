/*
	Author:	MarX
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define MAX 100000

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> V(n);
	for (int i = 0; i < n; ++i) cin >> V[i];
	sort(V.begin(), V.end());
	int pos = n - k;
	while (pos > 0 && V[pos - 1] == V[n - k]) --pos;
	while (pos < n && V[pos] == 0) ++pos;
	cout << n - pos << endl;
}