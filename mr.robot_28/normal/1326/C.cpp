#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> p(n);
	vector <bool> used(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		if(p[i] >= n - k + 1)
		{
			sum += p[i];
			used[i] = true;
		}
	}
	int j = 0;
	int pr = 1;
	int i = 0;
	while(i < n && !used[i])
	{
		i++;
	}
	for(; i < n; i++)
	{
		j = i + 1;
		while(j < n && !used[j])
		{
			j++;
		}
		if(j == n)
		{
			break;
		}
		pr = pr * (j - i) % const1;
		i = j - 1;
	}
	cout << sum << " ";
	cout << pr; 
	return 0;
}