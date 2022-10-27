#include <bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		set <int> ans;
		for(int i = 0; i <= sqrt(n); i++)
		{
			ans.insert(i);
		}
		for(int i = 1; i <= sqrt(n); i++)
		{
			ans.insert(n / i);
		}
		cout << ans.size() << "\n";
		set <int> :: iterator it;
		for(it = ans.begin(); it != ans.end(); it++){
			cout << *it << " ";
		}
		cout << "\n";
	}
	return 0;
}