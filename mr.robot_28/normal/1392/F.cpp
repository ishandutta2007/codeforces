#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int s = 0;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	s += a[i];
	}
	int p1 = (s - (n - 1) * n / 2) / n + 1;
	int s1 = (2 * p1 + n - 1) * n / 2;
	int d = s1 - s;
	for(int i = 0; i < n; i++)
	{
		cout << p1 + i - (n - i <= d) << " "; 
	}
    return 0;
}