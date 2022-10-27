#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	vector <int> prefs1(n + 1, 0), prefs2(n+ 1, 0), preft1(m + 1, 0), preft2(m + 1, 0);
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'A')
		{
			prefs1[i + 1] = prefs1[i] + 1;
			prefs2[i + 1] = prefs2[i];
		}
		else
		{
			prefs1[i + 1] = 0;
			prefs2[i + 1] = prefs2[i] + 1;
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(t[i] == 'A')
		{
			preft1[i + 1] = preft1[i] + 1;
			preft2[i + 1] = preft2[i];
		}
		else
		{
			preft1[i + 1] = 0;
			preft2[i + 1] = preft2[i] + 1;
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		l1--;
		r1--;
		l2--;
		r2--;
		int lens = min(r1 - l1 + 1, prefs1[r1 + 1]);
		int lent = min(r2 - l2 + 1, preft1[r2 + 1]);
		int cnts = prefs2[r1 + 1] - prefs2[l1];
		int cntt = preft2[r2 + 1] - preft2[l2];
		if(cnts % 2 != cntt % 2 || cnts > cntt || lent > lens)
		{
			cout << 0;
			continue;
		}
		if(cnts == cntt)
		{
			if(abs(lens - lent) % 3 == 0)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		else if(lens == lent)
		{
			if(cnts == 0)
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
		}
		else
		{
		//	cout << "A";
			cout << 1;
		}
	}
    return 0;
}