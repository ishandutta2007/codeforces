#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

char ch[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int tot;

vector<int> v;

void solve(int n, string &s, string &t)
{
	if (n == 2)
	{
		char a = ch[tot++];
		s += a; s += a;
		t += a;
		return;
	}
	if (n == 3)
	{
		char a = ch[tot++];
		s += a; s += a; s += a;
		t += a;
		return;
	}
	vector<int> v;
	for (int i = 2; i*i <= n; ++ i)
		while (n%i == 0)
		{
			v.push_back(i);
			n /= i;
		}
	if (n > 1)
		v.push_back(n);
	if (v.size() >= 2)
	{
		for (auto p : v)
		{
			string ss, tt;
			solve(p, ss, tt);
			s += ss;
			t += tt;
		}
	}
	else
	{
		int p = n;
		solve(p-1, s, t);
		for (int i = 0; i < t.size(); ++ i)
			if (t[t.size()-i-1] != s[s.size()-i-1])
			{
				s = s.substr(0, s.size()-i)+t;
				break;
			}
	}
}

int main()
{
	
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		puts("a a");
		return 0;
	}
	string s, t;
	solve(n, s, t);
	cout << s << " " << t << endl;
	
	return 0;
}