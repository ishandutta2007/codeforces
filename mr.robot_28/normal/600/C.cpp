#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main() {
	string s;
	cin >> s;
	vector <int> A(26, 0);
	for(int i = 0; i < s.size(); i++)
	{
		A[s[i] - 'a']++;
	}
	int j = 25;
	string ans = "";
	string h = "";
	for(int i = 0; i < 26; i++)
	{
		if(A[i] % 2 == 0){
			for(int k = 0; k < A[i] / 2; k++)
			{
				char t = 'a' + i;
				cout << t;
				ans += t;
			}
		}
		else
		{
			while(j >= i && A[j] % 2 == 0)
			{
				j--;
			}
			if(j > i)
			{
				char t1 = i + 'a';
				for(int k = 0; k < (A[i] + 1) / 2; k++)
				{
					ans += t1;
					cout << t1;
				}
				A[j]--;
			}
			else if(j == i)
			{
				char t = 'a' + i;
				for(int k = 0; k < A[i]/ 2; k++)
				{
					ans += t;
					cout << t;
				}
				h += t;
			}
		}
	}
	cout << h;
	if(ans.size() > 0)
	{
	for(int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	}
	return 0;
}