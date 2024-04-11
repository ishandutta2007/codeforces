#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		vector <int> a;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '1')
			{
				int j = i;
				while(j < s.size() && s[j] == '1')
				{
					j++;	
				}
				a.push_back(j - i);
				i = j - 1;
			}
		}
		sort(a.begin(), a.end());
		int sum = 0;
		for(int i = a.size() - 1; i >= 0; i-= 2)
		{
			sum += a[i];
		}
		cout << sum << "\n";
	}
	return 0;
}