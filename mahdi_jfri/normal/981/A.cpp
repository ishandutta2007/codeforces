#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;


	int ans = 0;
	int n = s.size();
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			string tmp = s.substr(i , j - i + 1);

			string tmp2 = tmp;
			reverse(tmp2.begin() , tmp2.end());

			if(tmp != tmp2)
				ans = max(ans , j - i + 1);
		}

	cout << ans << endl;
}