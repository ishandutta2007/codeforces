#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < b.size(); i++)
    {
    	cnt += b[i] - '0';
	}
	vector <int> pref(a.size());
	for(int i = 0; i < a.size(); i++)
	{
		if(i == 0)
		{
			pref[i] = a[i] - '0';
		}
		else
		{
			pref[i] = pref[i - 1] + a[i] - '0';
		}
	}
	int CNT = 0;
	for(int i = 0; i <= a.size() - b.size(); i++)
	{
		if(i == 0 && (pref[i + b.size() - 1]) % 2 == cnt % 2 || i != 0 && (pref[i + b.size() - 1] - pref[i - 1]) % 2 == cnt % 2 )
		{
			CNT++;
		}
	}
	cout << CNT;
    return 0;
}