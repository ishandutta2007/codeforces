#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int64> V(6);
	for (int i = 0; i < 6; ++i)
		cin >> V[i];

	int64 ans = 0;

	bool change = true;

	while (change){
		change = false;
		for (int i = 1; i < 5; ++i){
			while (V[i - 1] > 0 && V[i + 1] > 0){			
				change = true;
				ans += 2 * V[i] + 1;
				V[i - 1]--;
				V[i + 1]--;
				V[i]++;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
		ans += V[i] * V[i + 1];

	cout << ans << endl;

	return 0;
}