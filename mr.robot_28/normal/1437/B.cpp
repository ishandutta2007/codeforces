#include <bits/stdc++.h>
using namespace std;


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
/*	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> b(k + 1);
	for(int i = 0; i < k; i++)
	{
		cin >> b[i];
		if(i != 0 && b[i] - b[i - 1] > a[b[i] - 1] - a[b[i - 1] - 1])
		{
			cout << -1;
			return 0;
		}
	}
	*/
	int t;
	cin >> t;
	while(t--)
	{
		vector <int> vec1, vec2, vec3, vec4;
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		for(int i = 0; i < n - 1; i++)
		{
			if(s[i] == s[i + 1])
			{
				cnt++;
			}
		}
		cout << (cnt + 1) / 2 << "\n";
	}
	return 0;
}