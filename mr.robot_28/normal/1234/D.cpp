#include <bits/stdc++.h>

using namespace std;
string s;
vector <vector <int> > t;
void built(int v, int l, int r)
{
	if(l == r)
	{
		t[v][s[l] - 'a']++;
	}
	else
	{
		built(v * 2, l, (r + l) / 2);
		built(v * 2 + 1, (r + l) / 2 + 1, r);
		for(int i = 0; i < 26; i++)
		{
			t[v][i] = t[v * 2][i] + t[v * 2 + 1][i];
		}
	}
}
void update(int v, int l, int r, int ind, int type)
{
	t[v][s[ind] - 'a']--;
	t[v][type]++;
	if(r == l)
	{
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, type);
	}
	else
	{
		update(2 * v + 1, (r + l) / 2 + 1, r, ind, type);
	}
}
void ans(int v, int l, int r, int al, int ar, vector <int> &F)
{
	if(al <= l && r <= ar)
	{
		for(int i =  0; i < 26; i++)
		{
			F[i] += t[v][i];
		}
	}
	else if(l <= ar && r >= al)
	{
		ans(v * 2, l, (r + l) / 2, al, ar, F);
		ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, F);
	}
}
int main()
{
	cin >> s;
	t.resize(4 * s.size(), vector <int> (26, 0));
	built(1, 0, s.size() - 1);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int pos;
			char c;
			cin >> pos >> c;
			int u = c - 'a';
			update(1, 0, s.size() - 1, pos - 1, u);
			s[pos - 1] = c;
		}
		else
		{
			int l, r;
			cin >> l >> r;
			vector <int> P(26, 0);
			ans(1, 0, s.size() - 1, l - 1, r - 1, P);
			int cnt = 0;
			for(int j = 0; j < 26; j++)
			{
				if(P[j] != 0)
				{
					cnt++;
				}
			}
			cout << cnt << "\n";
		}
	}
    return 0;
}