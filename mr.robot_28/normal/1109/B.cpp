#include<bits/stdc++.h>
using namespace std;
string s;
int ans = 1e9;
void go_to(int l, int r, int t)
{
	if(l == r)
	{
		return;
	}
	bool flag = false;
	for(int i = l; i <= r; i++)
	{
		if(s[i] != s[s.size() - 1 - r + i])
		{
			flag = true;
		}
	}
	if(flag)
	{
		if(t == 1){
			ans = min(ans, 2);
		}
		else
		{
			ans = min(ans, 1);
		}
	}
	go_to(l, r / 2, max(t, (r + 1) % 2));
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	int n = s.size();
	vector <int> cnt(26, 0);
	int allcnt = 0;
	for(int i = 0; i < n / 2; i++)
	{
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++)
	{
		allcnt += (cnt[i] != 0);
	}
	if(allcnt <= 1)
	{
		cout << "Impossible";
		return 0;
	}
	go_to(0, n / 2 - 1, n % 2);
	if(ans != 1e9)
	{
		cout << ans;
		return 0;
	}
	if(n == 3)
	{
		cout << "Impossible";
		return 0;
	}
	cout << 4;
    return 0;
}